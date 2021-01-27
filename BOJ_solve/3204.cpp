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
const int MAXN = 1000;
const int MAXM = 100000;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pl;
typedef pair <ll,ll> pi;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,m,pos[MAXN+5],c[MAXM*2+5];
vecpi v[MAXN+5];

void dfs(int x) {
	for(;1;) {
		for(;pos[x] < v[x].size()&&c[v[x][pos[x]].y];pos[x]++);
		if(pos[x] == v[x].size()) break;
		c[v[x][pos[x]].y] = 1;
		if(x&&v[x][pos[x]].x) cout << x << ' ' << v[x][pos[x]].x << '\n';
		dfs(v[x][pos[x]].x);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= m;i++) {
		int x,y; cin >> x >> y;
		v[x].pb({y,i}), v[y].pb({x,i});
	}
	for(int i = 1;i <= n;i++) {
		if(v[i].size() % 2) v[i].pb({0,++m}), v[0].pb({i,m});
	}
	cout << "Yes\n";
	for(int i = 1;i <= n;i++) dfs(i);
}