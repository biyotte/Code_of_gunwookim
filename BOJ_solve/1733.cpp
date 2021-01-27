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
const int MAXN = 1000000;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pl;
typedef pair <ll,ll> pi;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,ind[MAXN+5],c[MAXN+5],c2[MAXN+5];
int V,E,cnt,mx,ans[MAXN+5];
vecpi v[MAXN+5];
vec vis;

void dfs(int x) {
	if(c[x]) return;
	c[x] = 1;
	vis.pb(x);
	V++, E += ind[x];
	for(pi i : v[x]) dfs(i.x);
}

void dfs_fill(int x,int st) {
	c2[x] = 1;
	cnt++;
	for(pi i : v[x]) {
		if(i.x == st&&cnt == mx&&!ans[i.y]) {ans[i.y] = x; return;}
		if(c2[i.x]) continue;
		ans[i.y] = x;
		dfs_fill(i.x,st);
	}
}

void fill_cycle(int st) {
	queue <int> q;
	for(int i : vis) {
		if(ind[i] == 1) c2[i] = 1, q.push(i);
	}
	while(!q.empty()) {
		int x = q.front(); q.pop();
		int cn = 0;
		for(pi i : v[x]) {
			if(c2[i.x]) continue;
			cn++;
			ans[i.y] = x;
			if(--ind[i.x] == 1) {
				c2[i.x] = 1;
				q.push(i.x);
			}
		}
	}
	mx = cnt = 0;
	for(int i : vis) if(!c2[i]) mx++;
	for(int i : vis) {
		if(!c2[i]) {
			dfs_fill(i,i);
			return;
		}
	}
}

void fill_tree(int x) {
	c2[x] = 1;
	for(pi i : v[x]) {
		if(c2[i.x]) continue;
		ans[i.y] = i.x;
		fill_tree(i.x);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) {
		int x,y; cin >> x >> y;
		v[x].pb({y,i}), v[y].pb({x,i});
		ind[x]++, ind[y]++;
	}
	for(int i = 1;i <= MAXN;i++) {
		if(c[i]) continue;
		vis.clear();
		V = E = 0; dfs(i); E /= 2;
		if(!E) continue;
		if(V < E) {
			cout << -1;
			return 0;
		}
		if(V == E) fill_cycle(i);
		else fill_tree(i);
	}
	for(int i = 1;i <= n;i++) cout << ans[i] << '\n';
}