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
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int T,d[20005];
int n,m,p[20005],a[20005];
vecpi v[20005];

int dfs(int x) {
	if(d[x]) return d[x];
	for(pi i : v[x]) {
		int val = dfs(i.x)-i.y;
		if(d[x] < val) {
			d[x] = val;
			p[x] = i.x;
		}
	}
	return d[x] += a[x];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);   
	cin >> T;
	while(T--) {
		cin >> n >> m;
		for(int i = 1;i <= n;i++) cin >> a[i], v[i].clear(), p[i] = d[i] = 0;
		for(int i = 1;i <= m;i++) {
			int x,y,val; cin >> x >> y >> val;
			v[x].pb({y,val});
		}
		dfs(1);
		vec ans;
		for(int i = 1;i;i = p[i]) ans.pb(i);
		cout << d[1] << ' ' << ans.size() << '\n';
		for(int i : ans) cout << i << ' ';
		cout << '\n';
	}
}