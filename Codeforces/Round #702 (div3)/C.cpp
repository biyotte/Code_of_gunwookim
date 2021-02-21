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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while(T--) {
		ll x;
		cin >> x;
		bool fl = 0;
		for(ll i = 1;i*i*i <= x;i++) {
			ll l = 1, r = 10000;
			while(l < r) {
				ll mid = (l + r) >> 1;
				if(mid*mid*mid+i*i*i < x) l = mid+1;
				else r = mid;
			}
			if(l*l*l+i*i*i == x) {
				cout << "YES\n";
				fl = 1;
				break;
			}
		}
		if(!fl) cout << "NO\n";
	}
}