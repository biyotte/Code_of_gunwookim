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
const long long llINF = 1e18;
const long long mod = 998244353;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
pi a[100005];
int n;
int t[2][1000005];

void update(int op,int x,int l,int r,int wi,int val) {
	if(wi < l||r < wi) return;
	if(l == r) {t[op][x] += val; return;}
	int mid = (l + r) >> 1;
	update(op,x*2,l,mid,wi,val), update(op,x*2+1,mid+1,r,wi,val);
	t[op][x] = t[op][x*2]+t[op][x*2+1];
}

int query(int x,int l,int r,int rl,int rr) {
	if(x > TMX/2) return max((l < r ? max(l+t[0][x],r) : max(l,r+t[0][x])),(rl < rr ? max(rl+t[1][x],rr) : max(rl,rr+t[1][x])));
	int mid = (l + r) >> 1;
	if(max(l+t[0][x*2],rl+t[1][x*2]) >= max(r+t[0][x*2+1],rr+t[1][x*2+1])) return query(x*2,l,r+t[0][x*2+1],rl,rr+t[1][x*2+1]);
	return query(x*2+1,l+t[0][x*2],r,rl+t[1][x*2],rr);
}

bool cmp(pi x,pi y) {
	if(x.y == y.y) return x.x < y.x;
	return x.y < y.y;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); 
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i].x >> a[i].y;
	sort(a+1,a+n+1);
	int cnt = 0, la = a[1].x;
	for(int i = 1;i <= n;i++) {
		if(la^a[i].x) {
			la = a[i].x;
			cnt++;
		}
		a[i].x = cnt;
	}
	sort(a+1,a+n+1,cmp);
	for(int i = 1;i <= n;i++) update(0,1,0,TMX/2,a[i].x,1);
	int ans = n;
	for(int i = 1;i <= n;) {
		cnt = 0;
		while(i+cnt <= n&&a[i].y == a[i+cnt].y) {
			update(0,1,0,TMX/2,a[i+cnt].x,-1);
			update(1,1,0,TMX/2,a[i+cnt].x,1);
			cnt++;
		}
		ans = min(ans,query(1,0,0,0,0));
		i += cnt;
	}
	cout << ans;
}
