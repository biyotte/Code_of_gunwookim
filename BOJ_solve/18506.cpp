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
const int MAXM = 1000000;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int T,c2[1000005],c3[1000005];
int n,m,k,c[1000005],ans[1000005];
vec v[1000005],v2[1000005];

void dfs(int x) {
	int cnt = 1;
	vec rv;
	for(int i : v[x]) {
		if(c[i]) rv.pb(c[i]);
	}
	sort(all(rv));
	for(int i : rv) {
		if(cnt == i) cnt++;
	}
	c[x] = cnt;
	for(int i : v[x]) {
		if(!c[i]) dfs(i);
	}
}

bool cmp(int x,int y) {
	return c[x] > c[y];
}

void dfs2(int x,int y) {
	ans[x] = y;
	sort(all(v[y]),cmp);
	int p1 = 0,p2 = 0;
	while(p1 < v2[x].size()&&p2 < v[y].size()) {
		if(!c2[v2[x][p1]]&&!c3[v[y][p2]]) {
			c2[v2[x][p1]] = c3[v[y][p2]] = 1;
			dfs2(v2[x][p1],v[y][p2]);
		}
		if(c2[v2[x][p1]]) p1++;
		if(c3[v[y][p2]]) p2++;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	while(T--) {
		cin >> n >> m >> k;
		for(int i = 1;i <= n;i++) v[i].clear(), v2[i].clear(), c[i] = c2[i] = c3[i] = 0;
		for(int i = 1;i <= m;i++) {
			int x,y; cin >> x >> y;
			v[x].pb(y), v[y].pb(x);
		}
		for(int i = 1;i < k;i++) {
			int x,y; cin >> x >> y;
			v2[x].pb(y), v2[y].pb(x);
		}
		for(int i = 1;i <= n;i++) {
			if(!c[i]) dfs(i);
		}
		int now;
		for(int i = 1;i <= n;i++) {
			if(c[i] == k) now = i;
		}
		dfs2(1,now);
		cout << "Yes\n";
		for(int i = 1;i <= k;i++) {
			cout << ans[i] << ' ';
		}
		cout << '\n';
	}
}