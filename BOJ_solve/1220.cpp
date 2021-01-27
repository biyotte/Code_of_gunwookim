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
int n,m,k,sx,sy,ex,ey;
ll d[2005][2005][4];
int c[2005][2005];
int nx[4] = {1,0,-1,0}, ny[4] = {0,1,0,-1};
// down, right, up, left

struct S {
	int sx,sy,ex,ey,val;
}area[1005];

vec revx,revy;

void getCost(int x,int y,int dx,int dy,int op,int val) {
	d[x][y][op] = d[dx][dy][op+2] = 1LL*(abs(revx[x]-revx[dx])+abs(revy[y]-revy[dy]))*val;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	revx.pb(-1), revy.pb(-1);
	cin >> sx >> sy >> ex >> ey;
	revx.pb(sx), revy.pb(sy);
	revx.pb(ex), revy.pb(ey);
	cin >> k;
	for(int i = 1;i <= k;i++) {
		cin >> area[i].sx >> area[i].sy >> area[i].ex >> area[i].ey >> area[i].val;
		revx.pb(area[i].sx), revx.pb(area[i].ex);
		revy.pb(area[i].sy), revy.pb(area[i].ey);
	}
	sort(all(revx)), revx.erase(unique(all(revx)),revx.end());
	sort(all(revy)), revy.erase(unique(all(revy)),revy.end());
	sx = lower_bound(all(revx),sx)-revx.begin();
	sy = lower_bound(all(revy),sy)-revy.begin();
	ex = lower_bound(all(revx),ex)-revx.begin();
	ey = lower_bound(all(revy),ey)-revy.begin();
	for(int i = 1;i <= k;i++) {
		area[i].sx = lower_bound(all(revx),area[i].sx)-revx.begin();
		area[i].sy = lower_bound(all(revy),area[i].sy)-revy.begin();
		area[i].ex = lower_bound(all(revx),area[i].ex)-revx.begin();
		area[i].ey = lower_bound(all(revy),area[i].ey)-revy.begin();
	}
	n = revx.size()-1, m = revy.size()-1;
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= m;j++) {
			if(i != n) getCost(i,j,i+1,j,0,10);
			if(j != m) getCost(i,j,i,j+1,1,10);
		}
	}
	for(int i = 1;i <= k;i++) {
		for(int x = area[i].sx;x < area[i].ex;x++) {
			for(int y = area[i].sy;y < area[i].ey;y++) {
				if(y != area[i].sy) getCost(x,y,x+1,y,0,area[i].val);
				if(x != area[i].sx) getCost(x,y,x,y+1,1,area[i].val);
			}
		}
	}
	priority_queue <pair<ll,pi>> q;
	q.push({0,{sx,sy}});
	while(!q.empty()) {
		auto now = q.top(); q.pop();
		ll cost = -now.x; int x = now.y.x, y = now.y.y;
		if(c[x][y]) continue;
		c[x][y] = 1;
		if(x == ex&&y == ey) {
			cout << cost; return 0;
		}
		for(int i = 0;i < 4;i++) {
			int dx = x+nx[i], dy = y+ny[i];
			if(dx < 1||dx > n||dy < 1||dy > m||c[dx][dy]) continue;
			q.push({-cost-d[x][y][i],{dx,dy}});
		}
	}
}