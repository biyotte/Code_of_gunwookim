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
int n,m,c[50005];
int del[100005];
vecpi rv[50005],v[50005];

void make_tree(int x) {
	c[x] = 1;
	for(pi i : rv[x]) {
		if(!c[i.x]) {
			v[x].pb(i);
			del[i.y] = 0;
			make_tree(i.x);
		}
	}
}

int dfs(int x,int st) {
	c[x] = 1;
	int ret = v[x].size()+st;
	for(pi i : v[x]) {
		if(dfs(i.x,1)) {
			del[i.y] = 1;
			ret--;
		}
	}
	return 1-ret%2;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= m;i++) {
		int x,y; cin >> x >> y;
		rv[x].pb({y,i}), rv[y].pb({x,i});
		del[i] = 1;
	}
	for(int i = 1;i <= n;i++) if(!c[i]) make_tree(i);
	memset(c,0,sizeof(c));
	for(int i = 1;i <= n;i++) {
		if(c[i]) continue;
		if(dfs(i,0)) {
			cout << -1;
			return 0;
		}
	}
	vec ans;
	for(int i = 1;i <= m;i++) if(!del[i]) ans.pb(i);
	cout << ans.size() << '\n';
	for(int i : ans) cout << i << '\n';
}