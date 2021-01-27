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
const long long mod = 998244353;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
ll l,k,r,t,x,y;
int c[1000005];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); 
	cin >> k >> l >> r >> t >> x >> y;
	k -= l, r -= l, l = 0;
	if(k+y <= r) k += y;
	if(x > y) {
		if(k < x) cout << "No";
		else if(t < (k-(x-1))/(x-y)+((k-(x-1))%(x-y) > 0)+1) cout << "Yes";
		else cout << "No";
		return 0;
	}
	if(x+y-1 <= r) {
		cout << "Yes";
		return 0;
	}
	ll ti = 0;
	while(1) {
		ti += k/x;
		k %= x;
		if(c[k]) {
			cout << "Yes";
			return 0;
		}
		c[k] = 1;
		k += y;
		if(k > r) break;
	}
	if(ti >= t) cout << "Yes";
	else cout << "No";
}