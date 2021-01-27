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
ll n,m;

ll mpow(ll x,ll M,ll Mod) {
    if(!M) return 1;
    ll tmp = mpow(x,M/2,Mod);
    tmp = tmp*tmp%Mod;
    if(M % 2) return tmp*x%Mod;
    return tmp;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	ll m1 = mpow(10,n,m);
	for(ll m2 = 0;m2 < m;m2++) {
		ll nam = (m2*m+m1)%(m*m);
		if(mpow(10,n,m*m) == nam) {
			cout << m2;
		}
	}
}