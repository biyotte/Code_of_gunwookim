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
const long long mod = 998244353;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
ll n;
vecpi ans;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); 
	int T; cin >> T;
	while(T--) {
		cin >> n;
		ans.clear();
		ll gop = 1;
		int j = 0;
		while(n) {
			if(n % 2) {
				ll i = 0,g = 1;
				for(;g <= n;g *= 3,i++);
				i--, g /= 3;
				n -= g;
				ans.pb({j,i});
			}
			else gop *= 2, j++, n /= 2;
		}
		cout << ans.size() << '\n';
		for(pi i : ans) cout << i.x << ' ' << i.y << '\n';
	}
}