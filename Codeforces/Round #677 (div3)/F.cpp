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
int d[71][71][40][71];
int n,m,K;
int a[75][75];
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	//int T; cin >> T;
	int T = 1;
	while(T--) {
		cin >> n >> m >> K;
		for(int i = 1;i <= n;i++) {
			for(int j = 1;j <= m;j++) cin >> a[i][j];
		}
		for(int i = 0;i <= n;i++) {
			for(int j = 0;j <= m;j++) {
				for(int k = 0;k <= (m+1)/2;k++) {
					for(int l = 0;l < K;l++) d[i][j][k][l] = -INF;
				}
			}
		}
		d[0][m][0][0] = 0;
		for(int i = 1;i <= n;i++) {
			for(int j = 1;j <= m;j++) {
				if(j == 1) {
					for(int k = 0;k <= (m)/2;k++) {
						for(int l = 0;l < K;l++) {
							d[i][1][0][l] = max(d[i][1][0][l],d[i-1][m][k][l]);
							d[i][1][1][(l+a[i][j])%K] = max(d[i][1][1][(l+a[i][j]%K)],d[i-1][m][k][l]+a[i][j]);
						}
					}
					continue;
				}
				for(int k = 0;k <= (m)/2;k++) {
					for(int l = 0;l < K;l++) {
						d[i][j][k][l] = max({d[i][j][k][l],d[i][j-1][k][l],(!k ? -INF : d[i][j-1][k-1][(l-a[i][j]+100*K)%K]+a[i][j])});
					}
				}
			}
		}
		int ans = 0;
		for(int k = 0;k <= (m)/2;k++) {
			ans = max(ans,d[n][m][k][0]);
		}
		cout << ans;
	}
}