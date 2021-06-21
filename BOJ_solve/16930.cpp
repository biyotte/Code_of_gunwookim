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
const long long llINF = 1e18+10;
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
int n,m,k,sx,ex,sy,ey;
int nx[4] = {1,0,-1,0}, ny[4] = {0,1,0,-1};
char a[1005][1005];
int c[1005][1005][5];

queue <pair<pi,pi>> q[2];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> k;
	for(int i = 1;i <= n;i++) {
		cin >> a[i]+1;
	}
	cin >> sx >> sy >> ex >> ey;
	q[0].push({{0,4},{sx,sy}});
	int cost, dist, dir, x, y;
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= m;j++) for(int dir = 0;dir < 4;dir++) c[i][j][dir] = INF;
	}
	for(int cost = 0;cost <= n*m;cost++) {
		while(!q[cost%2].empty()) {
			auto now = q[cost%2].front(); q[cost%2].pop();
			dist = -now.x.x, dir = now.x.y, x = now.y.x, y = now.y.y;
			if(c[x][y][dir] < cost) continue;
			if(x == ex&&y == ey) {
				cout << cost;
				return 0;
			}
			for(int i = 0;i < 4;i++) {
				int dx = x+nx[i], dy = y+ny[i];
				int ncost = cost+((i != dir)||(dist == k));
				if(c[dx][dy][i] <= ncost||a[dx][dy] == '#') continue;
				c[dx][dy][i] = ncost;
				q[ncost%2].push({{-(i^dir ? 1 : dist%k+1),i},{dx,dy}});
			}
		}
	}
	cout << -1;
}