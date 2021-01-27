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
int T,c[35][35],c2[35][35];
int n,m,un[1000];
pi p[35][35];
int nx[4] = {1,0,-1,0}, ny[4] = {0,1,0,-1};
char a[35][35];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	for(int tc = 1;tc <= T;tc++) {
		cin >> n >> m;
		for(int i = 1;i <= n;i++) {
			cin >> a[i]+1;
		}
		queue <pi> q;
		q.push({1,1});
		memset(c,0,sizeof(c));
		memset(c2,0,sizeof(c2));
		c[1][1] = 1;
		p[1][1] = {-1,-1};
		int x,y,fl = 0;
		while(!q.empty()) {
			x = q.front().x, y = q.front().y; q.pop();
			if(x+y != 2&&a[x][y] == 'T') {
				fl = 1; break;
			}
			for(int i = 0;i < 4;i++) {
				int dx = x+nx[i], dy = y+ny[i];
				if(dx < 1||dx > n||dy < 1||dy > m||a[dx][dy] == '.'||c[dx][dy]) continue;
				c[dx][dy] = 1;
				p[dx][dy] = {x,y};
				q.push({dx,dy});
			}
		}
		memset(c,0,sizeof(c));
		int ans = 0,cnt = 1,ex = x,ey = y;
		queue <pair<int,pi>> q2;
		if(fl) {
			for(;;) {
				c2[x][y] = 1;
				int tx = p[x][y].x, ty = p[x][y].y;
				if(tx == -1) break;
				ans += cnt++;
				x = tx, y = ty;
			}
			q2.push({1,{ex,ey}});
			c[ex][ey] = 1;
		}
		q2.push({1,{1,1}});
		c[1][1] = 1;
		while(!q2.empty()) {
			int cost = q2.front().x;
			x = q2.front().y.x, y = q2.front().y.y; q2.pop();
			for(int i = 0;i < 4;i++) {
				int dx = x+nx[i], dy = y+ny[i];
				if(dx < 1||dx > n||dy < 1||dy > m||a[dx][dy] == '.'||c[dx][dy]) continue;
				c[dx][dy] = 1;
				if(!c2[dx][dy]) ans += cost;
				q2.push({cost+1,{dx,dy}});
			}
		}
		cout << "Case #" << tc << ": " << ans << '\n';
	}
}