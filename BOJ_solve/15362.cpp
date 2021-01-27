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
ll n,m,k;
vecpi vx,vy;
vec rx,ry;
int co;
ll ans,cx[1000005],cy[1000005];
map <pi,ll> c;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> k;
	for(int i = 1;i <= k;i++) {
		char op; int x,y;
		cin >> op >> x >> y;
		if(op == 'R') rx.pb(x), vx.pb({x,y});
		else ry.pb(x), vy.pb({x,y});
	}
	if(n % 2 == 0||m % 2 == 0) ans = (n*m/2%mod)*((n*m+1)%mod)%mod;
	else ans = (n*m%mod)*((n*m+1)/2%mod)%mod;
	for(int i = 1;i <= n;i++) {
		cx[i] = (m*(m+1)/2%mod+(i-1)*m%mod*m%mod)%mod;
	}
	for(int i = 1;i <= m;i++) {
		cy[i] = (n*i%mod+(n*(n-1)/2%mod)*m%mod)%mod;
	}
	sort(all(rx)), rx.erase(unique(all(rx)),rx.end());
	sort(all(ry)), ry.erase(unique(all(ry)),ry.end());
	for(int i : rx) {
		for(int j : ry) {
			c[{i,j}] = (m*(i-1)+j)%mod;
		}
	}
	for(pi i : vx) {
		int x = i.x;
		ll val = i.y;
		ans = ((ans+cx[x]*(val-1)%mod)%mod+mod)%mod;
		cx[x] = cx[x]*val%mod;
		for(int y : ry) {
			cy[y] = ((cy[y]+c[{x,y}]*(val-1))%mod+mod)%mod;
			c[{x,y}] = c[{x,y}]*val%mod;
		}
	}
	for(pi i : vy) {
		int y = i.x;
		ll val = i.y;
		ans = ((ans+cy[y]*(val-1)%mod)%mod+mod)%mod;
		cy[y] = cy[y]*val%mod;
	}
	cout << ans;
}
