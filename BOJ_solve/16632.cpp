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
const long long llINF = 5e18;
const long long mod = 1e9+7;
const long long hmod1 = 1e9+409;
const long long hmod2 = 1e9+433;
const long long base = 257;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,m,k,ind[250005],up[250005];
int c[250005],c2[250005],dep[250005],ans;
int st[250005],en[250005];
vec v[250005];
vecpi path;

void dfs(int x,int depth) {
	dep[x] = depth;
	for(int i : v[x]) dfs(i,depth+1);
}

int dfs2(int x) {
	if(c[x]) return 0; c[x] = 1;
	int ret = 0;
	for(int i : v[x]) ret |= dfs2(i);
	if(en[x]) c2[x] = 1, ret |= 1;
	return ret;
}

bool cmp(pi x,pi y) {
	return dep[x.x] > dep[y.x];
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++) {
		int x,y; cin >> x >> y;
		v[x].pb(y), ind[y]++;
	}
	for(int i = 1;i <= k;i++) {
		int x,y; cin >> x >> y;
		st[x] = 1, en[y] = i;
		path.pb({x,y});
	}
	for(int i = 1;i <= n;i++) {
		if(!ind[i]) dfs(i,1);
	}
	sort(all(path),cmp);
	for(pi i : path) {
		if(c2[i.y]) continue;
		int x = i.x;
		ans += dfs2(x);
	}
	cout << ans;
}