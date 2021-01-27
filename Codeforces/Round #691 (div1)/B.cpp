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
const long long mod = 1e18;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int d[105][10005][105];
int n,b[105],a[105],bsum[105];
int ans[105],suma;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) {
		cin >> b[i] >> a[i];
		bsum[i] = bsum[i-1]+b[i];
		suma += a[i];
		ans[i] = suma;
	}
	memset(d,-1,sizeof(d));
	for(int i = 0;i <= n;i++) d[i][0][0] = 0;
	for(int i = 1;i <= n;i++) {
		for(int j = 0;j <= bsum[n];j++) {
			for(int k = 0;k <= n;k++) {
				d[i][j][k] = d[i-1][j][k];
				if(j >= b[i]&&k&&d[i-1][j-b[i]][k-1] != -1) d[i][j][k] = max(d[i][j][k],d[i-1][j-b[i]][k-1]+a[i]);
				if(d[i][j][k] != -1) ans[k] = max(ans[k],min(j*2,suma+d[i][j][k]));
			}
		}
	}
	for(int i = 1;i <= n;i++) {
		if(ans[i] % 2) cout << ans[i]/2 << ".5000000000 ";
		else cout << ans[i]/2 << ".0000000000 ";
	}
}

// 1억 7천만
// 40만 플3 : 600문제
// 230만 : 100문제