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
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,c[505],a[505],v[505];
int d[505][505][505];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) {
		cin >> c[i] >> a[i] >> v[i];
	}
	for(int i = 0;i <= n+1;i++) {
		for(int j = 0;j <= n+1;j++) {
			for(int k = 0;k <= n+1;k++) d[i][j][k] = -INF;
		}
	}
	d[0][1][2] = 0;
	for(int i = 0;i <= n+1;i++) {
		for(int j = 0;j <= n+1;j++) {
			for(int k = 0;k <= n;k++) {
				if(d[k][i][j] < 0) continue;
				int nx = min(n,max({i,j,k}))+1;
				if(i <= n&&(!i||!k||a[i] == a[k]||c[i] == c[k])) d[i][j][nx] = max(d[i][j][nx],d[k][i][j]+v[i]);
				if(nx <= n&&(!k||!nx||a[k] == a[nx]||c[k] == c[nx])) d[nx][i][j] = max(d[nx][i][j],d[k][i][j]+v[nx]);
			}
		}
	}
	int ans = 0;
	for(int i = 0;i <= n+1;i++) {
		for(int j = 0;j <= n+1;j++) {
			for(int k = 0;k <= n+1;k++) ans = max(ans,d[i][j][k]);
		}
	}
	cout << ans;
}