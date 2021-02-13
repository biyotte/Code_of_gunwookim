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
const int MAXN = 20000;
const int MAXM = 4000000;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pl;
typedef pair <ll,ll> pi;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,p[200005],dep[200005],er[200005];
ll d[200005],a[200005];
vec v[200005],v2[200005];
priority_queue <pair<ll,int>> mn,mx;

void dfs(int x) {
	for(int i : v2[x]) {
		dep[i] = dep[x]+1;
		dfs(i);
	}
}

bool cmp(int x,int y) {
	return a[x] < a[y];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while(T--) {
		cin >> n;
		dep[1] = 1;
		for(int i = 1;i <= n;i++) v2[i].clear(), v[i].clear(), er[i] = 0;
		for(int i = 2;i <= n;i++) cin >> p[i], v2[p[i]].pb(i);
		for(int i = 2;i <= n;i++) cin >> a[i];
		dfs(1);
		for(int i = 1;i <= n;i++) v[dep[i]].pb(i);
		for(int i = 1;i <= n;i++) sort(all(v[i]),cmp);
		ll ans = 0;
		for(int i = 2;i <= n;i++) {
			while(!mn.empty()) mn.pop();
			while(!mx.empty()) mx.pop();
			for(int j : v[i]) mx.push({d[p[j]]+a[j],j});
			for(int j : v[i]) {
				er[j] = 1;
				mn.push({d[p[j]]-a[j],j});
				while(!mx.empty()&&er[mx.top().y]) mx.pop();
				d[j] = max({d[p[j]]+max(a[j]-a[v[i][0]],a[v[i].back()]-a[j]),(mx.empty() ? -llINF : mx.top().x-a[j]),mn.top().x+a[j]});
				ans = max(ans,d[j]);
			}
		}
		cout << ans << '\n';
	}
}
