#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define all(v) v.begin(),v.end()
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
using namespace std;
const long long INF = 1e9;
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
int n,m,sx,sy;
vec v[1000005];
ll cost[1000005],k;
ll g[1000005],tg[1000005];
ll ind[1000005],nope[1000005];

void dfs(int x,int pr) {
	for(int i : v[x]) {
		if(i == pr) continue;
		g[i] = tg[x]*ind[i];
		tg[i] = tg[x]*(ind[i]-1);
		if(g[i] > INF) nope[i] = 1, g[i] = INF+1;
		if(tg[i] > INF) tg[i] = INF+1;
		dfs(i,x);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++) cin >> cost[i];
	sort(cost+1,cost+m+1);
	for(int i = 1;i < n;i++) {
		int x,y; cin >> x >> y;
		v[x].pb(y), v[y].pb(x);
		ind[x]++, ind[y]++;
		if(i == 1) sx = x, sy = y;
	}
	g[sx] = ind[sx], tg[sx] = ind[sx]-1;
	g[sy] = ind[sy], tg[sy] = ind[sy]-1;
	dfs(sx,sy), dfs(sy,sx);
	long long ans = 0; 
	for(int i = 1;i <= n;i++) {
		if(nope[i]) continue;
		int it = lower_bound(cost+1,cost+m+1,k*g[i])-cost;
		int it2 = lower_bound(cost+1,cost+m+1,(k+1)*g[i])-cost;
		ans += 1LL*(it2-it)*k;
		if(ans > llINF) return -1; 
	}
	cout << ans;
}
