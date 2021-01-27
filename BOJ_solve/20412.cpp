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
ll m,seed,x1,x2,a,c;

ll mpow(ll x,ll M) {
	if(!M) return 1;
	ll tmp = mpow(x,M/2);
	if(M % 2) return tmp*tmp%m*x%m;
	return tmp*tmp%m;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> m >> seed >> x1 >> x2;
	if(seed-x1 < 0) a = ((x2-x1)*mpow(x1-seed,m-2)%m+m)%m;
	else a = ((x1-x2)*mpow(seed-x1,m-2)%m+m)%m;
	c = ((x1-a*seed)%m+m)%m;
	cout << a << ' ' << c;
}