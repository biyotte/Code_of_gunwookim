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
int n,m,k;
int a[200005];
ll f[200005][3];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	for(int i = 0;i <= 2;i++) f[i][0] = f[i][i] = 1;
	for(int i = 3;i <= 200000;i++) f[i][0] = 1;
	for(int i = 1;i <= 200000;i++) {
		for(int j = 1;j <= 2;j++) {
			f[i][j] = f[i-1][j]+f[i-1][j-1];
		}
	}
	int T; cin >> T;
	while(T--) {
		cin >> n;
		for(int i = 1;i <= n;i++) cin >> a[i];
		sort(a+1,a+n+1);
		ll ans = 0;
		for(int l = 1,r = 1;l <= n;l++) {
			while(r <= n&&a[r]-a[l] <= 2) r++;
			if(r-l-1 < 2) continue;
			ans = ans+f[r-l-1][2];
		}
		cout << ans << '\n';
	}
}