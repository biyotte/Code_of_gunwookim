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
int n,m,k,cnt,a[1005],b[1005];
int d[1005][1005];
 
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); 
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int j = 1;j <= m;j++) cin >> b[j];
	for(int i = 0;i <= n;i++) {
		for(int j = 0;j <= m;j++) {
			d[i][j] = INF;
			if(!i&&!j) d[i][j] = 0;
			if(i) d[i][j] = min(d[i][j],d[i-1][j]+1);
			if(j) d[i][j] = min(d[i][j],d[i][j-1]+1);
			if(i&&j) d[i][j] = min(d[i][j],d[i-1][j-1]+1);
			if(i&&j&&a[i] == b[j]) d[i][j] = min(d[i][j],d[i-1][j-1]);
		}
	}
	cout << d[n][m];
}