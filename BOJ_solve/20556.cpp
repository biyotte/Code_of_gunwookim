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
int n,Q,sz[300005];
vecpi q[300005];
vec v[300005];
ll ans[300005],rans;
ll cnt[1200005],t[1200005];

void dfs(int x) {
	sz[x] = 1;
	for(int i : v[x]) {
		if(!sz[i]) dfs(i), sz[x] += sz[i];
	}
}

void update(int x,int l,int r,int wi,int val) {
	if(wi < l||r < wi) return;
	if(l == r) {
		t[x] += val*l;
		cnt[x] += val;
		return;
	}
	int mid = (l + r) >> 1;
	update(x*2,l,mid,wi,val), update(x*2+1,mid+1,r,wi,val);
	t[x] = t[x*2]+t[x*2+1];
	cnt[x] = cnt[x*2]+cnt[x*2+1];
}

ll kth(int x,int l,int r,int k) {
	if(l == r) return 1LL*k*l;
	int mid = (l + r) >> 1;
	if(cnt[x*2+1] <= k) return kth(x*2,l,mid,k-cnt[x*2+1])+t[x*2+1];
	return kth(x*2+1,mid+1,r,k);
}

void dfs2(int x,int pr) {
	for(pi i : q[x]) ans[i.y] = rans-kth(1,1,n,i.x);
	for(int i : v[x]) {
		if(i == pr) continue;
		update(1,1,n,sz[i],-1);
		update(1,1,n,n-sz[i],1);
		rans += (n-sz[i]*2)*2;
		dfs2(i,x);
		update(1,1,n,sz[i],1);
		update(1,1,n,n-sz[i],-1);
		rans -= (n-sz[i]*2)*2;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> Q;
	for(int i = 1;i < n;i++) {
		int x,y; cin >> x >> y;
		v[x].pb(y), v[y].pb(x);
	}
	for(int i = 1;i <= Q;i++) {
		int x,y; cin >> x >> y;
		q[x].pb({y,i});
	}
	dfs(1);
	for(int i = 2;i <= n;i++) rans += 2*sz[i], update(1,1,n,sz[i],1);
	dfs2(1,-1);
	for(int i = 1;i <= Q;i++) cout << ans[i] << '\n';
}