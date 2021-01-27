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
int n,k;
ll d[55][105],c[105];
vec v[55];

void dfs(int x,int pr) {
	d[x][1] = 1;
	for(int u : v[x]) {
		if(u == pr) continue;
		dfs(u,x);
		for(int i = 0;i <= k;i++) c[i] = 0;
		for(int i = 0;i <= k;i++) {
			for(int j = 0;j <= k;j++) {
				c[i+j] = (c[i+j]+d[x][i]*d[u][j])%mod;
			}
		}
		for(int i = 0;i <= k;i++) d[x][i] = (d[x][i]+c[i])%mod;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	for(int i = 1;i < n;i++) {
		int x,y; cin >> x >> y;
		v[x].pb(y), v[y].pb(x);
	}
	dfs(1,-1);
	ll ans = 0;
	for(int i = 1;i <= n;i++) ans += d[i][k];
	cout << ans%mod;
}
