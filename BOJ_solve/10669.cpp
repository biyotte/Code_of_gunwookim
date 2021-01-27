#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define all(v) v.begin(),v.end()
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
using namespace std;
const long long INF = 1e9;
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
int n,h[1005][1005],g[1005][1005];
pi a[505];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) {
		int x,y; char op;
		cin >> x >> y >> op; x++, y++;
		a[i] = {x,y};
		if(op == 'H') h[x][y]++;
		else g[x][y]++;
	}
	for(int i = 1;i <= 1001;i++) {
		for(int j = 1;j <= 1001;j++) {
			h[i][j] += h[i-1][j]+h[i][j-1]-h[i-1][j-1];
			g[i][j] += g[i-1][j]+g[i][j-1]-g[i-1][j-1];
		}
	}
	int ans = 0,area = 0;
	for(int i = 1;i <= n;i++) {
		for(int j = i;j <= n;j++) {
			int sx = min(a[i].x,a[j].x), ex = max(a[i].x,a[j].x);
			int sy = min(a[i].y,a[j].y), ey = max(a[i].y,a[j].y);
			if(g[ex][ey]-g[sx-1][ey]-g[ex][sy-1]+g[sx-1][sy-1] != 0) continue;
			int val = h[ex][ey]-h[sx-1][ey]-h[ex][sy-1]+h[sx-1][sy-1];
			if(ans < val) ans = val, area = (ex-sx)*(ey-sy);
			else if(ans == val&&area > (ex-sx)*(ey-sy)) ans = val, area = (ex-sx)*(ey-sy);
		}
	}
	cout << ans << '\n' << area;
}
