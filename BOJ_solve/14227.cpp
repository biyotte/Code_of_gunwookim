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
const long long llINF = 1e16;
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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> a >> b >> c >> d;
	ll ans = llINF;
	for(int n = 0;a*pow(2,n) <= c;n++) {
		if(c-a*pow(2,n) != d-b*pow(2,n)) continue;
		ll diff = c-a*pow(2,n);
		ll sum = 0;
		for(ll tn = pow(2,n);tn >= 1;tn /= 2) {
			sum += diff/tn;
			diff %= tn;
		}
		ans = min(ans,sum+n);
	}
	if(ans == llINF) ans = -1;
	cout << ans;
}