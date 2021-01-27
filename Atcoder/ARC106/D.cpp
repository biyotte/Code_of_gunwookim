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
long long mod = 998244353;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef vector <int> vec;
typedef vector <pi> vecpi; 
typedef long long ll;
int n,m;
ll sum,a[200005];

ll mpow(ll x,int dod) {
	if(!dod) return 1;
	ll tmp = mpow(x,dod/2);
	tmp = tmp*tmp%mod;
	if(dod % 2) return tmp*x%mod;
	return tmp;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i], sum += a[i]*(n-1)%mod;
	ll ans = sum;
	for(int g = 1;g <= m;g++) {
		cout << ans << '\n';
		ll rans = ans*sum%mod;
		for(int i = 1;i <= n;i++) {
			rans -= 
		}
	}
}