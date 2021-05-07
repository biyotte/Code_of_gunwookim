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
int T,sum[5005];
int n,d[5005][5005],p[5005][5005];
int a[5005];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	while(T--) {
		cin >> n;
		for(int i = 1;i <= n;i++) cin >> a[i], sum[i] = sum[i-1]+a[i];
		for(int i = 1;i <= n;i++) d[i][i] = 0, p[i][i] = i;
		for(int gap = 1;gap < n;gap++) {
			for(int i = 1;i <= n-gap;i++) {
				int j = i+gap;
				d[i][j] = INF;
				
				for(int k = p[i][j-1];k <= p[i+1][j];k++) {
					if(d[i][j] > d[i][k]+d[k+1][j]+sum[j]-sum[i-1]) {
						d[i][j] = d[i][k]+d[k+1][j]+sum[j]-sum[i-1];
						p[i][j] = k;
					}
				} 
			}
		}
		cout << d[1][n] << '\n';
	}
}   