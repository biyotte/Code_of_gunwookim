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
const long long mod = 998244353;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,m,st,en;
int c[100005],p[100005],co[100005],c2[100005];
int cango[100005];
vecpi v[100005];
vec rv[100005];

void Cango(int x) {
	if(cango[x]) return;
	cango[x] = 1;
	if(x == st) return;
	for(int i : rv[x]) Cango(i);
}

int Find_path(int x) {
	if(c[x]) return 0;
	if(x == en) return 1;
	c[x] = 1;
	for(pi i : v[x]) {
		if(Find_path(i.y)) return 1;
	}
	return 0;
}

int dfs(int x) {
	if(c[x]) return -1; // cycle
	if(c2[x]) return 0;
	if(x == en) return 1;
	c[x] = 1, c2[x] = 1;
	sort(all(v[x]));
	for(pi i : v[x]) {
		int nx = i.y;
		if(!cango[nx]) continue;
		p[nx] = x;
		co[nx] = i.x;
		int tmp = dfs(nx);
		if(tmp == -1) return -1;
		if(tmp == 1) return 1;
	}
	c[x] = 0;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); 
 	cin >> n >> m >> st >> en;
 	for(int i = 1;i <= m;i++) {
 		int x,y,z; cin >> x >> y >> z;
 		v[x].pb({z,y}), rv[y].pb(x);
 	}
 	if(!Find_path(st)) {
 		cout << "IMPOSSIBLE";
 		return 0;
 	}
 	Cango(en);
 	memset(c,0,sizeof(c));
 	int tmp = dfs(st);
 	if(tmp == -1) {
 		cout << "TOO LONG";
 		return 0;
 	}
 	if(tmp == 1) {
 		vec ans;
 		for(int i = en;i != st;i = p[i]) ans.pb(co[i]);
 		reverse(all(ans));
 		for(int i : ans) cout << i << ' ';
 	}
 	else return -1;
}