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
int n,m,ans;
int a[105][105],c[105][105];
int nx[4] = {1,0,-1,0}, ny[4] = {0,1,0,-1};
priority_queue <pair<int,pi>> q;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= m;j++) cin >> a[i][j];
	}
	for(int i = 1;i <= m;i++) {
		q.push({-a[1][i],{1,i}});
		q.push({-a[n][i],{n,i}});
	}
	for(int i = 1;i <= n;i++) {
		q.push({-a[i][1],{i,1}});
		q.push({-a[i][m],{i,m}});
	}
	while(!q.empty()) {
		auto now = q.top(); q.pop();
		int cost = -now.x, x = now.y.x, y = now.y.y;
		if(c[x][y]) continue;
		c[x][y] = 1;
		ans += max(0,cost-a[x][y]);
		for(int i = 0;i < 4;i++) {
			int dx = x+nx[i], dy = y+ny[i];
			if(dx < 1||dx > n||dy < 1||dy > m) continue;
			q.push({-max(cost,a[dx][dy]),{dx,dy}});
		}
	}
	cout << ans;
}