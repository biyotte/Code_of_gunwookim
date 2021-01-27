#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define all(v) v.begin(),v.end()
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
using namespace std;
const int INF = 1e9;
const int TMX = 1 << 18;
const long long llINF = 5e18;
const long long mod = 1e9+7;
const long long hmod1 = 1e9+409;
const long long hmod2 = 1e9+433;
const long long base = 257;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int a[200005];
int n,t[800005],mx[200005];

void build(int x,int l,int r) {
	t[x] = INF;
	if(l == r) {
		t[x] = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(x*2,l,mid), build(x*2+1,mid+1,r);
	t[x] = min(t[x*2],t[x*2+1]);
}

int query(int x,int l,int r,int rl,int rr) {
	if(rl > r||l > rr) return INF;
	if(rl <= l&&r <= rr) return t[x];
	int mid = (l + r) >> 1;
	return min(query(x*2,l,mid,rl,rr),query(x*2+1,mid+1,r,rl,rr));
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int T; cin >> T;
	//int T = 1;
	while(T--) {
		cin >> n;
		for(int i = 1;i <= n;i++) cin >> a[i];
		build(1,1,n);
		mx[n] = a[n];
		for(int i = n-1;i >= 1;i--) mx[i] = max(mx[i+1],a[i]);
		int done = 0,Mx = 0;
		for(int i = 1;i <= n;i++) {
			Mx = max(Mx,a[i]);
			int l = i, r = n-1,nope = 0;
			while(l < r) {
				int mid = (l + r) >> 1;
				int A = Mx, B = query(1,1,n,i+1,mid), C = mx[mid+1];
				if(A == B&&A == C) {
					cout << "YES\n";
					cout << i << ' ' << mid-i << ' ' << n-mid << '\n';
					done = 1;
					break;
				}
				if(A < B&&A > C) {nope = 1; break;}
				else if(A > B&&A < C) {nope = 1; break;}

				if(A > B) r = mid;
				else if(A < B) l = mid+1;
				else if(A < C) l = mid+1;
				else if(A > C) r = mid;
				else {
					cout << A << ' ' << B << ' ' << C << '\n';
					cout << "WTF";
					return -1;
				}
			}
			if(nope) continue;
			if(done) break;
			if(Mx == query(1,1,n,i+1,l)&&Mx == mx[l+1]) {
				cout << "YES\n";
				cout << i << ' ' << l-i << ' ' << n-l << '\n';
				done = 1;
				break;
			}
		}
		if(!done) {
			cout << "NO\n";
		}
	}
}
