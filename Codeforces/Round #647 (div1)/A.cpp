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
const int MAXN = 100000;
const int MAXM = 1000000;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,m,g[500005],h[500005],co[500005];
vec v[500005];
vecpi go;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= m;i++) {
		int x,y; cin >> x >> y;
		v[x].pb(y), v[y].pb(x);
	}
	for(int i = 1;i <= n;i++) {
		cin >> co[i];
		go.pb({co[i],i});
	}
	sort(all(go));
	for(pi j : go) {
		int x = j.y;
		for(int i : v[x]) g[h[i]] = 1;
		for(int i = 1;i <= n;i++) if(!g[i]) {
			h[x] = i; break;
		}
		for(int i : v[x]) g[h[i]] = 0;
		if(h[x]^co[x]) {
			cout << -1;
			return 0;
		}
	}
	for(pi i : go) cout << i.y << ' ';
}
