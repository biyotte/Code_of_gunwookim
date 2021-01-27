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
const long long llINF = 1e18;
const long long mod = 1e9+7;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
ll a[2005][2005],b[2005][2005];
ll a2[2005][2005],b2[2005][2005];
ll rev2 = 500000004,gop = 1;
int n;
char m[2005][2005];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) {
		cin >> m[i]+1;
		for(int j = 1;j <= n;j++) {
			if(m[i][j] == '.') gop = gop*2%mod;
		}
	}
	for(int i = 1;i <= n;i++) {
		if(m[1][i] == '.') a[1][i] = a2[1][i] = rev2;
		if(m[i][1] == '.') b[i+1][0] = b2[i+1][0] = rev2;
	}
	for(int i = 2;i <= n+1;i++) {
		for(int j = 1;j <= n;j++) {
			if(m[i][j] == '.') a[i][j] = b2[i][j-1]*rev2%mod;
			if(m[i-1][j+1] == '.') b[i][j] = a2[i-1][j]*rev2%mod;
			a2[i][j] = (a2[i-1][j]+a[i][j])%mod;
			b2[i][j] = (b2[i][j-1]+b[i][j])%mod;
		}
	}
	cout << (a2[n][n]+b2[n+1][n])%mod*gop%mod;
}
