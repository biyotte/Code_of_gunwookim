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
long long mod = 1e9+7;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef vector <int> vec;
typedef vector <pi> vecpi; 
typedef long long ll;
int n,x,pos;
ll fact[30005],factInv[30005];

ll mpow(ll x,ll m) {
    if(!m) return 1;
    ll tmp = mpow(x,m/2);
    tmp = tmp*tmp % mod;
    if(m % 2) return tmp*x%mod;
    return tmp;
}
 
ll Com(ll x,ll r) {
	if(x < r) return 0;
    return fact[x]*factInv[x-r]%mod;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	//int T; cin >> T;
    fact[0] = 1;
    for(int i = 1;i <= 30000;i++) fact[i] = fact[i-1]*i%mod;
    factInv[30000] = mpow(fact[30000],mod-2);
    for(int i = 29999;i >= 0;i--) factInv[i] = factInv[i+1]*(i+1)%mod;
	int T = 1,ch = 0;
	while(T--) {
		cin >> n >> x >> pos;
		int cu = 0,cd = 0;
		int l = 0,r = n;
		while (l < r) {
			int mid = (l + r) / 2;
			if(mid <= pos) cd++, l = mid+1;
			else cu++, r = mid;
			//cout << l << ' ' << r << '\n';
			if(mid == pos) ch = 1;
		}
		if(ch) cd--;
		cout << Com(x-1,cd)*Com(n-x,cu)%mod*fact[n-cu-cd-1]%mod;
	}
}