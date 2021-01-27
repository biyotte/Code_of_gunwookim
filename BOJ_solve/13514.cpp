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
const long long llINF = 2e18;
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
int n,p[100005],isw[100005];
int sz[100005];
int c[100005],dep[100005];
int sp[100005][20];
vec v[100005];


// d[i] : i번 노드가 센트로이드일때 흰색 자식들의 거리 set
set <pi> d[100005];

void dfs_init(int x,int pr) {
	for(int i : v[x]) {
		if(i == pr) continue;
		sp[i][0] = x;
		dep[i] = dep[x]+1;
		dfs_init(i,x);
	}
}

void make_sparse() {
	for(int i = 1;i < 20;i++) {
		for(int j = 1;j <= n;j++) {
			sp[j][i] = sp[sp[j][i-1]][i-1];
		}
	}
}

int LCA(int x,int y) {
	if(dep[x] < dep[y]) swap(x,y);
	for(int i = 19;i >= 0;i--) {
		if(dep[x]-(1 << i) >= dep[y]) x = sp[x][i];
	}
	if(x == y) return x;
	for(int i = 19;i >= 0;i--) {
		if(sp[x][i]^sp[y][i]) x = sp[x][i], y = sp[y][i];
	}
	return sp[x][0];
}

int dist(int x,int y) {
	return dep[x]+dep[y]-dep[LCA(x,y)]*2;
}

int dfs_centroid(int x,int pr,int cap) {
	for(int i : v[x]) {
		if(i == pr||c[i]||sz[i] <= cap) continue;
		return dfs_centroid(i,x,cap);
	}
	return x;
}

void getsz(int x,int pr) {
	sz[x] = 1;
	for(int i : v[x]) {
		if(i == pr||c[i]) continue;
		getsz(i,x), sz[x] += sz[i];
	}
}

int make_centroid(int x) {
	getsz(x,-1);
	int cent = dfs_centroid(x,-1,sz[x]/2);
	c[cent] = 1;
	for(int i : v[cent]) {
		if(c[i]) continue;
		int nxcent = make_centroid(i);
		p[nxcent] = cent;
	}
	return cent;
}

void update(int x) {
	isw[x] ^= 1;
	int go = x;
	while(go) {
		if(isw[x]) d[go].insert({dist(x,go),x});
		else d[go].erase({dist(x,go),x});
		go = p[go];
	}
}

int query(int x) {
	int ret = INF, go = x;
	while(go) {
		if(!d[go].empty()) ret = min(ret,(*d[go].begin()).x+dist(x,go));
		go = p[go];
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i < n;i++) {
		int x,y; cin >> x >> y;
		v[x].pb(y), v[y].pb(x);
	}
	dep[1] = 1, dfs_init(1,-1), make_sparse();
	int stcent = make_centroid(1);
	int Q; cin >> Q;
	while(Q--) {
		int op,x; cin >> op >> x;
		if(op & 1) update(x);
		else {
			int ans = query(x);
			if(ans == INF) ans = -1;
			cout << ans << '\n';
		}
	}
}