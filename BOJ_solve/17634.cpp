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
const long long llINF = 5e18;
const long long mod = 1e9+7;
const long long hmod1 = 1e9+409;
const long long hmod2 = 1e9+433;
const long long base = 257;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n;
ll A,B,T;
vector <pl> v;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> A >> B;
	A = A/__gcd(A,B+1);
	T = llINF;
	if(A <= llINF/B) T = A*B; // 오버 플로우 방지
	for(int i = 1;i <= n;i++) {
		ll l,r; cin >> l >> r;
		if(r-l+1 >= T) v.pb({0,1}), v.pb({T,-1});
		else {
			l %= T, r %= T;
			if(l <= r) v.pb({l,1}), v.pb({r+1,-1});
			else v.pb({0,1}), v.pb({r+1,-1}), v.pb({l,1}), v.pb({T,-1});
		}
	}
	sort(all(v));
	ll cnt = 0,la = 0,ans = 0;
	for(pl i : v) {
		if(cnt) ans += i.x-la;
		cnt += i.y;
		la = i.x;
	}
	cout << ans;
}
