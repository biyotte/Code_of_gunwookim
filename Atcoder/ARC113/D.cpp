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
const long long mod = 998244353;
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

ll mpow(ll x,ll M) {
	if(!M) return 1;
	ll tmp = mpow(x,M/2);
	tmp = tmp*tmp%mod;
	if(M % 2) return tmp*x%mod;
	return tmp;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n,m,k;
	cin >> n >> m >> k;
	ll ans = 0;
	if(n > m) swap(n,m);
	if(n == 1) {
		for(int X = 1;X <= k;X++) {
			ans += (mpow(X,m)-mpow(X-1,m)+mod)%mod;
			ans %= mod;
		}
		cout << ans;
		return 0;
	}
	for(int X = 1;X <= k;X++) {
		ans += ((mpow(X,n)-mpow(X-1,n)+mod)%mod)*mpow(k-X+1,m)%mod;
		ans %= mod;
	}
	cout << ans;
}