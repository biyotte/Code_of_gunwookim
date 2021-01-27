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
const long long mod = 1e18;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,color;
map <int,int> c[65000];
int a[255][255],b[65000];
int co[255][255],cnt[65000];
int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
vec v[65000];
map<int,vector <int>> v2[65000];

void dfs(int x,int y) {
	if(co[x][y]) return;
	co[x][y] = color;
	cnt[color]++;
	for(int i = 0;i < 4;i++) {
		int nx = x+dx[i], ny = y+dy[i];
		if(a[x][y]^a[nx][ny]) continue;
		dfs(nx,ny);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	memset(a,-1,sizeof(a));
	cin >> n;
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) cin >> a[i][j];
	}
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) {
			if(!co[i][j]) {
				++color;
				b[color] = a[i][j];
				dfs(i,j);
			}
		}
	}
	for(int x = 1;x <= n;x++) {
		for(int y = 1;y <= n;y++) {
			for(int i = 0;i < 2;i++) {
				int nx = x+dx[i], ny = y+dy[i];
				if(co[x][y]^co[nx][ny]) {
					v[co[x][y]].pb(co[nx][ny]);
					v[co[nx][ny]].pb(co[x][y]);
					v2[co[x][y]][a[nx][ny]].pb(co[nx][ny]);
					v2[co[nx][ny]][a[x][y]].pb(co[x][y]);
				}
			}
		}
	}
	for(int i = 1;i <= color;i++) {
		sort(all(v[i])), v[i].erase(unique(all(v[i])),v[i].end());
	}
	int ans1 = 0,ans2 = 0;
	for(int i = 1;i <= color;i++) {
		ans1 = max(ans1,cnt[i]);
		for(int j : v[i]) {
			queue <int> q;
			int cn = cnt[i];
			q.push(i);
			c[i][b[j]] = 1;
			while(!q.empty()) {
				int x = q.front(); q.pop();
				for(int k : v2[x][b[i]^b[j]^b[x]]) {
					if(c[k][b[x]]) continue;
					c[k][b[x]] = 1;
					cn += cnt[k];
					q.push(k);
				}
			}
			ans2 = max(ans2,cn);
		}
	}
	cout << ans1 << '\n' << max(ans1,ans2);
}