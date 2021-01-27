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
const int MAXN = 20000;
const int MAXM = 4000000;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pl;
typedef pair <ll,ll> pi;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;

tuple <ll,ll,ll> add_gcd(ll x,ll y) {
	if(!y) return make_tuple(x,1,0);
	ll g,nx,ny;
	tie(g,nx,ny) = add_gcd(y,x%y);
	return make_tuple(g,ny,nx-(x/y)*ny);
}

ll inverse(ll ax,ll by,ll c) {
	ll g,x,y;
	g = __gcd(ax,by);
	if(c % g) return -1;
	tie(g,x,y) = add_gcd(ax,by);
	return x*c;
}

pi CRT(vecpi con) {
	// x = val (mod M)
	// val = a
	// m1,m2 = M,M2
	// ax = z (mod m)
	// ax + my = z
	ll val = con[0].x, M = con[0].y;
	for(int i = 1;i < con.size();i++) {
		ll val2 = con[i].x, M2 = con[i].y;
		ll g = __gcd(M,M2);
		if(val % g != val2 % g) return {-1,-1};
		ll k = inverse(M,M2,((val2-val)%M2+M2)%M2);
		if(k == -1) return {-1,-1};
		ll tm = M*M2/__gcd(M,M2);
		ll tval = M*k+val;
		M = tm, val = tval;
		val = (val%M+M)%M;
	}
	return {val,M};
}