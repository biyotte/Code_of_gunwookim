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
const long long llINF = 1e18;
long long mod;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi; 
typedef long long ll;
int d[1005][1005];
int n,m,C,a[1005];
vec v[1005];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> C;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= m;i++) {
		int x,y; cin >> x >> y;
		v[y].pb(x);
	}
	for(int i = 0;i <= 1000;i++) {
		for(int j = 1;j <= n;j++) d[i][j] = -INF;
	}
	d[0][1] = 0;
	int ans = 0;
	for(int i = 1;i <= 1000;i++) {
		for(int j = 1;j <= n;j++) {
			for(int k : v[j]) {
				d[i][j] = max(d[i][j],d[i-1][k]+a[j]-(i*i-(i-1)*(i-1))*C);
			}
		}
		ans = max(ans,d[i][1]);
	}
	cout << ans;
}