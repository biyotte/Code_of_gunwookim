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
const int mod = 998244353;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,cnt[5005][4];
char a[5005];
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> a+1;
	for(int i = 1;i <= n;i++) {
		for(int j = 0;j < 4;j++) cnt[i][j] = cnt[i-1][j];
		if(a[i] == 'A') cnt[i][0]++;
		if(a[i] == 'T') cnt[i][1]++;
		if(a[i] == 'C') cnt[i][2]++;
		if(a[i] == 'G') cnt[i][3]++;
	}
	int c[4];
	int ans = 0;
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= i;j++) {
			for(int k = 0;k < 4;k++) c[k] = cnt[i][k]-cnt[j-1][k];
			if(c[0] == c[1]&&c[2] == c[3]) ans++;
		}
	}
	cout << ans;
}