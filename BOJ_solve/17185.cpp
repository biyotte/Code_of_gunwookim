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
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,m,Q,root,co,lpos[100005],rpos[100005];
int ishop[100005],p[100005][20];
int ep[100005],dep[100005];
ll dist[100005],d[100005][20];
pi edge[100005];

struct Edge {
	int x,y,idx;
};
vector <Edge> v[100005];

void dfs(int x,int pr) {
	lpos[x] = ++co;
	if(ishop[x]) d[x][0] = dist[x];
	else d[x][0] = llINF;
	for(auto i : v[x]) {
		if(pr == i.x) continue;
		dist[i.x] = dist[x]+i.y;
		dep[i.x] = dep[x]+1;
		ep[i.idx] = i.x;
		dfs(i.x,x);
		d[x][0] = min(d[x][0],d[i.x][0]);
	}
	p[x][0] = pr;
	rpos[x] = co;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> Q >> root;
	for(int i = 1;i < n;i++) {
		int x,y,z; cin >> x >> y >> z;
		v[x].pb({y,z,i}), v[y].pb({x,z,i});
	}
	for(int i = 1;i <= m;i++) {
		int x; cin >> x;
		ishop[x] = 1;
	}
	dep[root] = 1;
	dfs(root,root);
	for(int i = 1;i <= n;i++) d[i][0] -= dist[i]*2;
	for(int i = 1;i <= 18;i++) {
		for(int j = 1;j <= n;j++) {
			p[j][i] = p[p[j][i-1]][i-1];
			d[j][i] = min(d[j][i-1],d[p[j][i-1]][i-1]);
		}
	}
	while(Q--) {
		int x,y; cin >> x >> y;
		x = ep[x];
		if(lpos[x] > lpos[y]||rpos[y] > rpos[x]) cout << "escaped\n";
		else {
			ll res = d[x][0];
			int ry = y;
			for(int i = 18;i >= 0;i--) {
				if(dep[p[y][i]] >= dep[x]) {
					res = min(res,d[y][i]);
					y = p[y][i];
				}
			}
			if(res > llINF/10) cout << "oo\n";
			else cout << res+dist[ry] << '\n';
		}
	}
}
