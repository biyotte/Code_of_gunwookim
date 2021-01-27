#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define all(v) v.begin(),v.end()
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
using namespace std;
const long long INF = 1e9;
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
int n;
ll fact[300005],factInv[300005];
map <ld,int> ma;

ll mpow(ll x,ll m) {
    if(!m) return 1;
    ll tmp = mpow(x,m/2);
    tmp = tmp*tmp % mod;
    if(m % 2) return tmp*x%mod;
    return tmp;
}

ll Com(ll x,ll r) {
	if(x < r) return 0LL;
    return fact[x]*factInv[r]%mod*factInv[x-r]%mod;
}

struct Line {
	ld gi;
	ld A,B,C;
}a[300005];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
    fact[0] = 1;
    for(int i = 1;i <= 300000;i++) fact[i] = fact[i-1]*i%mod;
    factInv[300000] = mpow(fact[300000],mod-2);
    for(int i = 299999;i >= 0;i--) factInv[i] = factInv[i+1]*(i+1)%mod;
	cin >> n;
	for(int i = 1;i <= n;i++) {
		cin >> a[i].A >> a[i].B >> a[i].C;
		if(a[i].B == 0) a[i].gi = INF*5;
		else a[i].gi = -a[i].A/a[i].B;
		ma[a[i].gi]++;
	}
	ll ans = Com(n,3);
	for(auto i : ma) {
		ans -= Com(i.y,2)*(n-i.y)+Com(i.y,3);
	}
	
	cout << (ans%mod+mod)%mod;
}
