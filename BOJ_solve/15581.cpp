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
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,m;
int a[505],sz[505];
int d[505][2005][2],c[1020][2];
vec v[505];

void dfs(int x,int pr) {
	sz[x] = 1;
	d[x][1][0] = d[x][1][1] = a[x];
	for(int y : v[x]) {
		if(y == pr) continue;
		dfs(y,x);
		memset(c,0,sizeof(c));
		for(int i = 0;i <= sz[x];i++) {
			for(int j = 0;j <= sz[y];j++) {
				c[i+j+1][1] = max(c[i+j+1][1],d[x][i][0]+d[y][j][1]);
				c[i+j+2][0] = max(c[i+j+2][0],d[x][i][0]+d[y][j][0]);
				c[i+j+2][1] = max(c[i+j+2][1],d[x][i][1]+d[y][j][0]);
			}
		}
		sz[x] += sz[y]+2;
		sz[x] = min(sz[x],m);
		for(int i = 0;i <= sz[x];i++) d[x][i][0] = max(d[x][i][0],c[i][0]), d[x][i][1] = max(d[x][i][1],c[i][1]);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i < n;i++) {
		int x,y; cin >> x >> y;
		v[x].pb(y), v[y].pb(x);
	}
	dfs(1,-1);
	int ans = 0;
	for(int i = 0;i <= m;i++) ans = max(ans,d[1][i][1]);
	cout << ans;
}
