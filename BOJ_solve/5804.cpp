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
ll a,b,c,d;

pl add_gcd(ll x,ll y) {
	if(!y) return make_pair(1,0);
	ll g,nx,ny;
	pl N = add_gcd(y,x%y);
	nx = N.x, ny = N.y;
	return {ny,nx-(x/y)*ny};
}

pl inverse(ll ax,ll by) {
	ll g,x,y;
	g = __gcd(ax,by);
	pl N = add_gcd(ax,by);
	return N;
}

int main() {
	int T; cin >> T;
	while(T--) {
		scanf("%lld/%lld",&c,&d);
		ll rc = c,rd = d;
		a = inverse(d,c).x, b = inverse(d,c).y;
		if(__gcd(c,d) != 1) {
			cout << c/__gcd(c,d) << '/' << d/__gcd(c,d) << '\n';
			continue;
		}
		ll a2 = -a, b2 = -b;
		ll na = c/__gcd(d,c), nb = d/__gcd(d,c);
		ll op = (d-b-1)/nb,op2 = (d-b2-1)/nb;
		a -= op*na, b += op*nb, a2 -= op2*na, b2 += op2*nb;

		if(b < d&&b2 < d) {
			if(b == b2) cout << min(-a,-a2) << '/' << b << '\n';
			else if(b > b2) cout << -a << '/' << b << '\n';
			else cout << -a2 << '/' << b2 << '\n';
		}
		else if(b < d) cout << -a << '/' << b << '\n';
		else if(b2 < d) cout << -a2 << '/' << b2 << '\n';
		else return -1;
	}
}