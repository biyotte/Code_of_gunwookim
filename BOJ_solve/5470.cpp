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
int n;
ll m,d[1000005][3];
char a[1000005];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> a+1;
	d[0][0] = d[1][0] = 1;
	for(int i = 2;i <= n;i++) {
		d[i][1] = d[i-1][0]+d[i-1][2];
		if(i >= 2) for(int j = 0;j < 3;j++) d[i][j] += d[i-2][j];
		if(i >= 3) d[i][2] += d[i-3][0]+d[i-3][1];
		d[i][0] %= m, d[i][1] %= m, d[i][2] %= m;
	}
	ll ans = 1;
	char pp = '!',p = '?';
	for(int i = 1;i <= n;i++) {
		if(pp^p&&a[i] == 'P') {
			ans += d[n-i+1][0];
			if(pp^'L'&&p^'L') ans += d[n-i+1][1];
			if(pp^'P'||p == 'L') ans += d[n-i+1][2];
		}
		if(a[i] == p) pp = a[i];
		p = a[i];
		ans %= m;
	}
	cout << ans;
}