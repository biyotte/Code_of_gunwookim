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
int n,Q,cent,ans,sp[100005][20];
int dep[100005],sz[100005];
int pc[100005],vis[100005];
vec v[100005];
set <pi> s[100005];

struct Query {
	char op; int x;
}q[100005];

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
	}
	return now_cent;
}

int LCA(int x,int y) {
	if(dep[x] < dep[y]) swap(x,y);
	for(int i = 19;i >= 0;i--) {
		if(dep[y]+(1 << i) <= dep[x]) x = sp[x][i];
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
	int st = x,la = -1;
	while(x) {
		s[x].insert({-dist(st,x),la});
		while(s[x].size() >= 2&&s[x].begin()->y == next(s[x].begin())->y) s[x].erase(next(s[x].begin()));
		la = x, x = pc[x];
	}
}

int query(int x) {
	int st = x,la = 0,ans = 0;
	while(x) {
		int di = dist(st,x);
		if(s[x].size() >= 1&&s[x].begin()->y != la) ans = max(ans,di-s[x].begin()->x);
		else if(s[x].size() >= 2) {
			if(next(s[x].begin())->y == la) exit(-1);
			ans = max(ans,di-next(s[x].begin())->x);
		}
		la = x, x = pc[x];
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> Q;
	for(int i = 1;i <= Q;i++) {
		cin >> q[i].op >> q[i].x;
		if(q[i].op == 'B') {
			if(q[i].x == -1) {++n; continue;}
			v[++n].pb(q[i].x);
			v[q[i].x].pb(n);
		}
	}
	for(int i = 1;i <= n;i++) {
		if(!dep[i]) dep[i] = 1, dfs(i,-1), make_cent(i);
	}
	for(int i = 1;i < 20;i++) {
		for(int j = 1;j <= n;j++) sp[j][i] = sp[sp[j][i-1]][i-1];
	}
	int m = 0;
	for(int i = 1;i <= Q;i++) {
		if(q[i].op == 'B') update(++m);
		else cout << query(q[i].x) << '\n';
	}
}
