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
const long long mod = 1e9+7;
const long long hashmod = 100003;
const int MAXN = 100000;
const int MAXM = 1000000;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,co,sz[300005],t[1200005],ans[1200005];
int t2[1200005],up[300005],tpos[300005],rtpos[300005];
int sp[300005][20],c[300005],dep[300005];
ll cost[300005],cnt[1200005],sum;
vecpi v[300005];

// not solved

void dfs(int x,int pr) {
	sz[x] = 1;
	for(pi i : v[x]) {
		if(i.x == pr) continue;
		sp[i.x][0] = x;
		cost[i.x] = i.y;
		dep[i.x] = dep[x]+1;
		dfs(i.x,x);
		sz[x] += sz[i.x];
	}
}

bool cmp(pi x,pi y) {
	return sz[x.x] > sz[y.x];
}

void dfs2(int x,int pr,int la) {
	up[x] = la;
	tpos[++co] = x;
	rtpos[x] = co;
	sort(all(v[x]),cmp);
	int ch = 1;
	for(pi i : v[x]) {
		if(i.x == pr) continue;
		if(ch) dfs2(i.x,x,la), ch = 0;
		else dfs2(i.x,x,i.x);
	}
}

int lca(int x,int y) {
	if(!x) return y;
	if(!y) return x;
	if(dep[x] < dep[y]) swap(x,y);
	for(int i = 19;i >= 0;i--) {
		if(dep[x] >= dep[y]+(1 << i)) {
			x = sp[x][i];
		}
	}
	if(x == y) return x;
	for(int i = 19;i >= 0;i--) {
		if(sp[x][i]^sp[y][i]) x = sp[x][i], y = sp[y][i];
	}
	return sp[x][0];
}

void update(int x,int l,int r,int wi) {
	if(wi < l||r < wi) return;
	if(l == r) {
		c[l] ^= 1;
		if(c[l]) t[x] = l;
		else t[x] = 0;
		return;
	}
	int mid = (l + r) >> 1;
	update(x*2,l,mid,wi), update(x*2+1,mid+1,r,wi);
	t[x] = lca(t[x*2],t[x*2+1]);
}

void updateLCA(int x,int y,int val) {
	while(up[x]^up[y]) {
		if(dep[up[x]] < dep[up[y]]) swap(x,y);
		update2(1,1,n,tpos[up[x]],tpos[x],val);
		
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i < n;i++) {
		int x,y,z; cin >> x >> y >> z;
		v[x].pb({y,z}), v[y].pb({x,z});
	}
	dep[1] = 1; dfs(1,-1);
	for(int i = 1;i < 20;i++) {
		for(int j = 1;j <= n;j++) sp[j][i] = sp[sp[j][i-1]][i-1];
	}
	int Q; cin >> Q;
	while(Q--) {
		char op; int x;
		cin >> op >> x;
		update(1,1,n,x);
		int u = t[1];
		cout << u << "\n";
	}
}
