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
const long long llINF = 1e16;
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
int n,m,T,K,co,dep[300005],go[300005];
int p[300005],cnt[300005],sz[300005],c[300005],is[300005];
vec v[300005],tv[300005];

void dfs(int x,int pr) {
	c[x] = 1;
	dep[x] = go[x] = ++co;
	p[x] = pr, sz[x] = 1;
	for(int i : v[x]) {
		if(i == pr) continue;
		if(c[i]) go[x] = min(go[x],dep[i]);
		else {
			dfs(i,x);
			go[x] = min(go[x],go[i]);
			cnt[x] += cnt[i], tv[x].pb(i), sz[x] += sz[i];
		}
	} 
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> K >> T;
	for(int i = 1;i <= m;i++) {
		int x,y; cin >> x >> y;
		v[x].pb(y), v[y].pb(x);
	}
	for(int i = 1;i <= K;i++) {
		int x; cin >> x; is[x] = cnt[x] = 1;
	}
	dfs(1,-1);
	for(int i = 1;i <= n;i++) {
		int ans = !is[i];
		vecpi g;
		int ro = cnt[1]-cnt[i],All = sz[1]-sz[i];
		for(int j : tv[i]) {
			if(go[j] < dep[i]) ro += cnt[j], All += sz[j];
			else g.pb({cnt[j],sz[j]});
		}
		g.pb({ro,All});
		for(pi j : g) ans += (j.x < T)*(j.y-j.x);
		cout << ans << ' ';
	}
}