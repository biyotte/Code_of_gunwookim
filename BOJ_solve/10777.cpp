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
int n,m,ans;
int a[3005],b[105];
int d[3005][105][105][2];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	cin >> m;
	for(int i = 1;i <= m;i++) cin >> b[i];
	sort(b+1,b+m+1);
	for(int i = 1;i <= n;i++) {
		for(int l = 0;l <= m;l++) {
			for(int r = m+1;r > l;r--) {
				d[i][l][r][0] = max({d[i-1][l][r][0],d[i-1][l][r][1],d[i][l-1][r][0],d[i][l-1][r][1],d[i][l][r+1][0],d[i][l][r+1][1]});
				d[i][l][r][1] = max({d[i-1][l][r][0]+a[i],d[i][l][r+1][0]+b[r]});
				ans = max({ans,d[i][l][r][0],d[i][l][r][1]});
			}
		}
	}
	cout << ans;
}