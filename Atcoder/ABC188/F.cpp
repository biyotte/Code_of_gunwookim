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
const long long llINF = 3e18;
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
ll X,Y,ans,d[70][2];

ll Cnt(ll x,ll lim) {
	ll ret = 0;
	for(ll j = lim;j >= 0;j--) {
		if(x & (1LL << j)) ret++;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> X >> Y;
	if(X > Y) {
		cout << X-Y;
		return 0;
	}
	ans = llINF;
	for(int gop = 0;X <= Y*2;X *= 2,gop++) {
		ll s = abs(X-Y);
		ll cnt = 0,mn = llINF,ti = gop;
		for(ll j = 0;j <= gop;j++) {
			s += (1LL << j);
		}
		for(ll j = gop;j >= 0;j--) {
			cnt += s/(2LL << j);
			s %= (2LL << j);
		}
		ans = min(ans,cnt+gop);
	}
	cout << ans;
}