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
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,cent,dep[100005],sz[100005];
int a[100005],vis[100005],ans = INF;
int pc[100005],sp[100005][20];
vec v[100005],vc[100005];
map <int,int> m[100005];

void dfs(int x,int pr) {
	for(int i : v[x]) {
		if(i == pr) continue;
		dep[i] = dep[x]+1;
		sp[i][0] = x;
		dfs(i,x);
	}
}

int get_sz(int x,int pr) {
	sz[x] = 1;
	for(int i : v[x]) {
		if(!vis[i]&&i^pr) sz[x] += get_sz(i,x);
	}
	return sz[x];
}

int get_cent(int x,int pr,int cap) {
	for(int i : v[x]) {
		if(!vis[i]&&i^pr&&sz[i] > cap) return get_cent(i,x,cap);
	}
	return x;
}

int make_cent(int x) {
	int cap = get_sz(x,-1), now_cent = get_cent(x,-1,cap/2);
	vis[now_cent] = 1;
	for(int i : v[now_cent]) {
		if(vis[i]) continue;
		int child_cent = make_cent(i);
		pc[child_cent] = now_cent;
		vc[now_cent].pb(child_cent);
	}
	return now_cent;
}

int LCA(int x,int y) {
	if(dep[x] > dep[y]) swap(x,y);
	for(int i = 19;i >= 0;i--) {
		if(dep[x]+(1 << i) <= dep[y]) {
			y = sp[y][i];
		}
	}
	if(x == y) return x;
	for(int i = 19;i >= 0;i--) {
		if(sp[x][i]^sp[y][i]) x = sp[x][i], y = sp[y][i];
	}
	return sp[x][0];
}

int dist(int x,int y) {
	return dep[x]+dep[y]-2*dep[LCA(x,y)];
}

void update(int x) {
	int st = x;
	while(x) {
		int di = dist(st,x);
		if(m[x].find(a[st]) != m[x].end()) {
			ans = min(ans,m[x][a[st]]+di);
			m[x][a[st]] = min(m[x][a[st]],di);
		}
		else m[x][a[st]] = di;
		x = pc[x];
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i < n;i++) {
		int x,y; cin >> x >> y;
		v[x].pb(y), v[y].pb(x);
	}
	dep[1] = 1, dfs(1,-1);
	cent = make_cent(1);
	for(int i = 1;i < 20;i++) {
		for(int j = 1;j <= n;j++) sp[j][i] = sp[sp[j][i-1]][i-1];
	}
	for(int i = 1;i <= n;i++) update(i);
	cout << ans;
}
