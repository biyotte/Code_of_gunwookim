#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define all(v) v.begin(),v.end()
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
using namespace std;
const long long INF = 2e9;
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
ll l[1000005],r[1000005],tl[1000005],tr[1000005];
ll ind[1000005];

void pro(int i) {
	if(l[i] > INF) l[i] = INF+1;
	if(r[i] > INF) r[i] = INF+1;
	if(tl[i] > INF) tl[i] = INF+1;
	if(tr[i] > INF) tr[i] = INF+1;

}

void dfs(int x,int pr) {
	for(int i : v[x]) {
		if(i == pr) continue;
		l[i] = tl[x]*ind[i];
		r[i] = (tr[x]+1)*ind[i]-1;
		tl[i] = tl[x]*(ind[i]-1);
		tr[i] = (tr[x]+1)*(ind[i]-1)-1;
		pro(i);
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
	l[sx] = ind[sx]*k, r[sx] = ind[sx]*(k+1)-1, tl[sx] = (ind[sx]-1)*k, tr[sx] = (ind[sx]-1)*(k+1)-1;
	l[sy] = ind[sy]*k, r[sy] = ind[sy]*(k+1)-1, tl[sy] = (ind[sy]-1)*k, tr[sy] = (ind[sy]-1)*(k+1)-1;
	pro(sx), pro(sy);
	dfs(sx,sy), dfs(sy,sx);
	ll ans = 0; 
	for(int i = 1;i <= n;i++) {
		if(v[i].size() > 1) continue;
		int it = lower_bound(cost+1,cost+m+1,l[i])-cost;
		int it2 = upper_bound(cost+1,cost+m+1,r[i])-cost;
		ans += 1LL*(it2-it)*k;
	}
	cout << ans;
}
