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
int n,m,c[100005],cnt;
pi a[100005];
vec v[100005];

int dfs(int x,int pr) {
	if(c[x]) return 1;
	c[x] = 1;
	cnt++;
	int ret = 0;
	for(int i : v[x]) {
		if(i == pr) continue;
		if(dfs(i,x)) ret = 1;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while(T--) {
		cin >> n >> m;
		for(int i = 1;i <= n;i++) c[i] = 0;
		for(int i = 1;i <= m;i++) {
			v[i].clear();
			cin >> a[i].x >> a[i].y;
			c[a[i].y] = i;
		}
		for(int i = 1;i <= m;i++) {
			if(a[i].x != a[i].y&&c[a[i].x]) {
				v[i].pb(c[a[i].x]);
				v[c[a[i].x]].pb(i);
			}
		}
		for(int i = 1;i <= n;i++) c[i] = 0;
		int ans = 0;
		for(int i = 1;i <= m;i++) {
			if(c[i]||a[i].x == a[i].y) continue;
			cnt = 0;
			if(dfs(i,-1)) ans++;
			ans += cnt;
		}
		cout << ans << '\n';
	}
}