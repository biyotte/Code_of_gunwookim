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
const long long llINF = 1e18;
const int mod = 998244353;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
vecpi v[500005];
int n,m,c[500005],c2[500005],g[500005];

void dfs(int x) {
	if(c[x]) {
		while(c[x]) {
			cout << x << ' ';
			c[x] = 0, x = g[x];
		}
		cout << '\n';
	}
	while(!v[x].empty()) {
		pi y = v[x].back(); v[x].pop_back();
		if(c2[y.y]) continue;
		c[x] = 1, c2[y.y] = 1, g[x] = y.x;
		dfs(y.x);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= m;i++) {
		int x,y; cin >> x >> y;
		v[x].pb({y,i}), v[y].pb({x,i});
	}
 	dfs(1);
}
