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
const int MAXM = 1000001;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,m,S,E,co,c[100005];
vec v[100005],rv[100005];
vec st;

void dfs(int x) {
	if(c[x]) return;
	c[x] = 1;
	for(int i : v[x]) dfs(i);
	st.pb(x);
}

void dfs2(int x) {
	if(c[x]) return
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> S >> E;
	for(int i = 1;i <= m;i++) {
		int x,y; cin >> x >> y;
		v[x].pb(y), rv[y].pb(x);
	}
	for(int i = 1;i <= n;i++) {
		if(c[i]) continue;
		dfs(i);
	} 
	reverse(all(st));
	memset(c,0,sizeof(c));
	for(int i : st) {
		if(c[i]) continue;
		co++;
		dfs2(i); 
	}
} 