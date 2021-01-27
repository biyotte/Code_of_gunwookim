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
const int MAXN = 100000;
const int MAXM = 1000000;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int d[5005][5005],a[5005];
ll sum[5005];
int n,k,Q,cnt[5005];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k >> Q;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= n;i++) d[0][i] = 1;
	for(int i = 1;i <= k;i++) {
		for(int j = 1;j <= n;j++) {
			if(j > 1) d[i][j] += d[i-1][j-1];
			if(j < n) d[i][j] += d[i-1][j+1];
			d[i][j] %= mod;
		}
	}
	for(int i = 0;i <= k;i++) {
		for(int j = 1;j <= n;j++) sum[j] = (sum[j]+1LL*d[i][j]*d[k-i][j]%mod)%mod;
	}
	ll ans = 0;
	for(int i = 1;i <= n;i++) ans = (ans+sum[i]*a[i])%mod;
	while(Q--) {
		int x,val; cin >> x >> val;
		ans = (ans-1LL*a[x]*sum[x]%mod)%mod;
		a[x] = val;
		ans = (ans+1LL*a[x]*sum[x]%mod)%mod;
		ans = (ans+mod)%mod;
		cout << ans << '\n';
	}
}