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
int n,m;
ll col[2005][205];
ll a[2005][205],edge[2005];
ll d[2005][2][2005][2];
ll row[2005][205];

ll rowD(int st,int en,int op) {
	if(st > en) swap(st,en);
	return row[en][op]-row[st-1][op];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= m;j++) {
			cin >> a[i][j];
			col[i][j] = col[i][j-1]+a[i][j];
			if(j == 1) row[i][0] = row[i-1][0]+a[i][j];
			if(j == m) row[i][1] = row[i-1][1]+a[i][j];
		}
		edge[i] = col[i][m-1]-a[i][1];
	}
	for(int i = 1;i <= n;i++) {
		d[i][0][i][1] = llINF;
		for(int j = 1;j <= n;j++) {
			d[i][0][i][0] = a[i][1], d[i][1][i][1] = a[i][m];
			d[i][0][i][1] = min(d[i][0][i][1],rowD(i,j,0)+edge[j]+rowD(j,i,1));
		}
		d[i][1][i][0] = d[i][0][i][1];
	}
	for(int i = 1;i <= n;i++) {
		for(int i2 = 0;i2 <= 1;i2++) {
			for(int j = i+1;j <= n;j++) {
				for(int j2 = 0;j2 <= 1;j2++) {
					d[i][i2][j][j2] = min(d[i][i2][j-1][0]+d[j][0][j][j2],d[i][i2][j-1][1]+d[j][1][j][j2]);
					d[j][j2][i][i2] = d[i][i2][j][j2];
				}
			}
		}
	}
	int Q; cin >> Q;
	int x = 1,y = 1;
	ll ans = 0;
	while(Q--) {
		int nx,ny; cin >> nx >> ny;
		ll xl = col[x][y]-a[x][1];
		ll xr = col[x][m]-col[x][y-1]-a[x][m];
		ll nxl = col[nx][ny]-a[nx][1];
		ll nxr = col[nx][m]-col[nx][ny-1]-a[nx][m];
		ans += min({xl+nxl+d[x][0][nx][0],xl+nxr+d[x][0][nx][1],xr+nxl+d[x][1][nx][0],xr+nxr+d[x][1][nx][1],(x == nx ? col[x][max(ny,y)]-col[x][min(ny,y)-1] : llINF)})-a[nx][ny];
		x = nx, y = ny;
	}
	cout << ans+a[x][y];
}