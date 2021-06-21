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
const long long llINF = 1e16;
const long long mod = 1e9+9;
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
int n,m,k,a[1005],b[1005];
ll d[2][1005][1005];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> k;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= m;i++) cin >> b[i];
	sort(a+1,a+n+1), sort(b+1,b+m+1);
	d[0][0][0] = 1;
	for(int cnt = 0;cnt <= k;cnt++) {
		for(int i = 0;i <= n;i++) {
			for(int j = 0;j <= m;j++) {
				if(!cnt&&!i&&!j) continue;
				d[cnt%2][i][j] = 0;
				if(i&&j) d[cnt%2][i][j] = d[cnt%2][i-1][j]+d[cnt%2][i][j-1]-d[cnt%2][i-1][j-1];
				else if(i) d[cnt%2][i][j] = d[cnt%2][i-1][j];
				else if(j) d[cnt%2][i][j] = d[cnt%2][i][j-1];
				if(i&&j&&a[i] > b[j]) d[cnt%2][i][j] += d[1-cnt%2][i-1][j-1];
				d[cnt%2][i][j] = (d[cnt%2][i][j]+mod)%mod;
			}
		}
	}
	cout << d[k%2][n][m];
}