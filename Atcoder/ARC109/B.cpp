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
ll n;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	ll l = 1, r = INF*2;
	while(l < r) {
		ll mid = (l + r) >> 1;
		if(mid*(mid+1)/2 < n+1) l = mid+1;
		else r = mid;
	}
	if(l*(l+1)/2 == n+1) cout << n-l+1;
	else cout << n-l+2;
}
