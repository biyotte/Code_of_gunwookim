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
int n,k;
int d[5005][5005][2],sum[5005][5005][2];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	d[n-k][k][0] = d[n-k][k][1] = 1;
	for(int i = n-k;i >= 0;i--) {
		if(i != n-k) {
			for(int j = 1;j <= n;j++) {
				if(i+j <= n) d[i][j][0] = sum[i+j][j-1][1];
				if(i+j <= n) d[i][j][1] = sum[i+j][j+1][0];
			}
		}
		for(int j = 1;j <= n;j++) sum[i][j][1] = (sum[i][j-1][1]+d[i][j][1]) % mod;
		for(int j = n;j >= 1;j--) sum[i][j][0] = (sum[i][j+1][0]+d[i][j][0]) % mod;
	}
	ll ans = 0;
	for(int j = 1;j <= n;j++) ans = (ans+1LL*d[0][j][0]+1LL*d[0][j][1]) % mod;
	if(n == k) ans--;
	cout << ans;
} 