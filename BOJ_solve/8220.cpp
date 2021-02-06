#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define all(v) v.begin(),v.end()
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
using namespace std;
const long long INF = 2e9;
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
int n,m,m2,c[605];
ll d[605][605];
int wu[605][605];
vec v;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> m2;
	for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) d[i][j] = INF;
	for(int i = 1;i <= n;i++) d[i][i] = 0, wu[i][i] = 1;
	for(int i = 1;i <= m;i++) {
		int x,y; cin >> x >> y;
		d[x][y] = min(d[x][y],1LL), d[y][x] = -1;
		wu[x][y] = wu[y][x] = 1;
	}
	for(int i = 1;i <= m2;i++) {
		int x,y; cin >> x >> y;
		d[y][x] = min(d[y][x],0LL);
		wu[y][x] = 1;
	}
	for(int k = 1;k <= n;k++) {
		for(int i = 1;i <= n;i++) {
			for(int j = 1;j <= n;j++) {
				d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
				wu[i][j] |= (wu[i][k]&wu[k][j]);
			}
		}
	}
	ll ans = 0;
	for(int i = 1;i <= n;i++) {
		if(d[i][i] < 0) {cout << "NIE"; return 0;}
		if(c[i]) continue;
		v.clear();
		for(int j = 1;j <= n;j++) {
			if(wu[i][j]&&wu[j][i]) c[j] = 1, v.pb(j);
		}
		ll tmp = -llINF;
		for(int j : v) for(int k : v) tmp = max(tmp,d[j][k]);
		ans += tmp+1;
	}
	cout << ans;
}