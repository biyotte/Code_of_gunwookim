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
const int MAXN = 100000;
const int MAXM = 1000000;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,m;
int c[300005];
int is[300005];
vec v[300005];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while(T--) {
		cin >> n >> m;
		for(int i = 1;i <= n;i++) is[i] = c[i] = 0, v[i].clear();
		for(int i = 1;i <= m;i++) {
			int x,y; cin >> x >> y;
			v[x].pb(y), v[y].pb(x);
		}
		queue <int> q;
		is[1] = c[1] = 1;
		q.push(1);
		while(!q.empty()) {
			int x = q.front(); q.pop();
			for(int i : v[x]) {
				if(c[i]) continue;
				c[i] = 1;
				int fl = 1;
				for(int j : v[i]) if(is[j]) fl = 0;
				is[i] = fl;
				q.push(i);
			}
		}
		int fl = 1;
		for(int i = 1;i <= n;i++) if(!c[i]) fl = 0;
		if(!fl) {
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		vec ans;
		for(int i = 1;i <= n;i++) if(is[i]) ans.pb(i);
		cout << ans.size() << '\n';
		for(int i : ans) cout << i << ' ';
		cout << '\n';
	}
}