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
const int MAXN = 20000;
const int MAXM = 4000000;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pl;
typedef pair <ll,ll> pi;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,Q,cent,sp[100005][20],dep2[100005];
int pc[100005],c[100005],vis[100005];
ll sum[100005],dep[100005];
vec vc[100005];
vecpi v[100005];
ll ans,sz[100005],sumsz[100005];
map <int,ll> m[100005],sz2[100005];

void dfs(int x,int pr) {
	for(pi i : v[x]) {
		if(i.x == pr) continue;
		sp[i.x][0] = x;
		dep2[i.x] = dep2[x]+1;
		dep[i.x] = dep[x]+i.y;
		dfs(i.x,x);
	}
}

int get_sz(int x,int pr) {
	sz[x] = 1;
	for(pi j : v[x]) {
		int i = j.x;
		if(!vis[i]&&i^pr) sz[x] += get_sz(i,x);
	}
	return sz[x];
}

int get_cent(int x,int pr,int cap) {
	for(pi j : v[x]) {
		int i = j.x; 
		if(!vis[i]&&i^pr&&sz[i] > cap) return get_cent(i,x,cap);
	}
	return x;
}

int make_cent(int x,int pr) {
	int cap = get_sz(x,pr), now_cent = get_cent(x,pr,cap/2);
	vis[now_cent] = 1;
	for(pi j : v[now_cent]) {
		int i = j.x;
		if(vis[i]) continue;
		int chile_cent = make_cent(i,now_cent);
		vc[now_cent].pb(chile_cent);
		pc[chile_cent] = now_cent;
	}
	return now_cent;
}

int LCA(int x,int y) {
	if(dep2[x] < dep2[y]) swap(x,y);
	for(int i = 19;i >= 0;i--) {
		if(dep2[x] >= dep2[y]+(1 << i)) x = sp[x][i];
	}
	if(x == y) return x;
	for(int i = 19;i >= 0;i--) {
		if(sp[x][i]^sp[y][i]) x = sp[x][i], y = sp[y][i];
	}
	return sp[x][0];
}

ll dist(int x,int y) {
	return dep[x]+dep[y]-2*dep[LCA(x,y)];
}

void update(int x) {
	int st = x,la = 0;
	while(x) {
		ll di = dist(x,st);
		sum[x] += di;
		sumsz[x]++;
		m[x][la] += di;
		sz2[x][la]++;
		la = x, x = pc[x];
	}
}

ll query(int x) {
	int st = x, la = -1;
	ll ans = 0;
	while(x) {
		ll di = dist(x,st);
		ans += di*(sumsz[x]-sz2[x][la])+sum[x]-m[x][la];
		la = x, x = pc[x];
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> Q;
	for(int i = 1;i < n;i++) {
		int x,y,z; cin >> x >> y >> z; x++, y++;
		v[x].pb({y,z}), v[y].pb({x,z});
	}
	dfs(1,-1);
	cent = make_cent(1,-1);
	for(int i = 1;i < 20;i++) {
		for(int j = 1;j <= n;j++) sp[j][i] = sp[sp[j][i-1]][i-1];
	}
	while(Q--) {
		int op,x; cin >> op >> x; x++;
		if(op & 1) {if(!c[x]) update(x), c[x] = 1;}
		else cout << query(x) << '\n';
	}
}