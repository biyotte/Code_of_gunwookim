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
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pl;
typedef pair <ll,ll> pi;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,m,node,edge,c[100005];
vec v[100005];
ll ans = 1;

void dfs(int x) {
	if(c[x]) return;
	c[x] = 1;
	node++, edge += v[x].size();
	for(int i : v[x]) dfs(i);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= m;i++) {
		int x,y; cin >> x >> y;
		v[x].pb(y), v[y].pb(x);
	}
	for(int i = 1;i <= n;i++) {
		if(c[i]) continue;
		node = edge = 0, dfs(i);
		edge /= 2;
		if(node == edge) ans = ans*2%mod;
		else if(node-1 == edge) ans = ans*node%mod;
		else ans = 0;
	}
	cout << ans;
}