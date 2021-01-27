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
const long long llINF = 1e18;
long long mod;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi; 
typedef long long ll;
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	//int T; cin >> T;
	int T = 1;
	while(T--) {
		ll n,d = 1; cin >> n;
		for(ll i = n/2+1;i <= n;i++) d *= i;
		for(ll i = 1;i <= n/2;i++) d /= i;
		ll f = 1;
		for(ll i = 1;i <= n/2-1;i++) f *= i;
		cout << d*f*f/2LL << '\n';
	}
}