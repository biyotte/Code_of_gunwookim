#include <bits/stdc++.h>
#define x first
#define w second
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
int V,E,go,c[100005];
int p[100005],p2[100005];
vector <int> v[100005];
vector <pair<int,int>> ans;

int Find(int x) {return (x^p[x] ? p[x] = Find(p[x]) : x);}
int Find2(int x) {return (x^p2[x] ? p2[x] = Find2(p2[x]) : x);}

int dfs(int x,int la) {
	if(c[x]) return 0;
	c[x] = ++go;
	int ret = go,ch = 0;
	for(int i : v[x]) {
		if(i == la&&!ch) {ch = 1; continue;}
		int tmp = dfs(i,x);
		if(tmp) ret = min(ret,tmp);
		else ret = min(ret,c[i]);
		if(tmp > c[x]) cout << x << ' ' << i << '\n';
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> V >> E;
	for(int i = 1;i <= V;i++) p[i] = p2[i] = i;
	for(int i = 1;i <= E;i++) {
		int x,y;
		cin >> x >> y;
		if(Find(x)^Find(y)) {
			p[p[y]] = p[x];
			v[x].pb(y), v[y].pb(x);
		}
		else if(Find2(x)^Find2(y)) {
			p2[p2[y]] = p2[x];
			v[x].pb(y), v[y].pb(x);
		}
	}
	for(int i = 1;i <= V;i++) if(!c[i]) dfs(i,-1);
}