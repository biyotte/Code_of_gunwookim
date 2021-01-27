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
const long long llINF = 1e18;
long long mod;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi; 
typedef long long ll;
int n,Q,a[200005];
pi t[800005];

void update(int x,int l,int r,int wi,int val) {
	if(wi < l||r < wi) return;
	if(l == r) {
		t[x] = {val,val};
		return;
	}
	int mid = (l + r) >> 1;
	update(x*2,l,mid,wi,val), update(x*2+1,mid+1,r,wi,val);
	t[x] = {min(t[x*2].x,t[x*2+1].x),max(t[x*2].y,t[x*2+1].y)};
}

pi query(int x,int l,int r,int rl,int rr) {
	if(rl > r||l > rr) return {INF,-INF};
	if(rl <= l&&r <= rr) return t[x];
	int mid = (l + r) >> 1;
	pi L = query(x*2,l,mid,rl,rr), R = query(x*2+1,mid+1,r,rl,rr);
	return {min(L.x,R.x),max(L.y,R.y)};
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> Q;
	for(int i = 1;i <= n*4;i++) t[i] = {INF,-INF};
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
		update(1,1,n,a[i],i);
	}
	while(Q--) {
		int op,x,y; cin >> op >> x >> y;
		if(op & 1) {
			update(1,1,n,a[x],y), update(1,1,n,a[y],x);
			swap(a[x],a[y]);
		}
		else {
			pi tmp = query(1,1,n,x,y);
			if(tmp.y-tmp.x+1 == y-x+1) cout << "YES\n";
			else cout << "NO\n";
		}
	}
}