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
vector <pl> g;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); 
	cin >> n;
	int cnt = 0;
	for(ll i = 1;i*i <= n;i++) {
		if(n % i == 0) {
			ll x = (n/i), y = i;
			if(i % 2||(n/i) % 2) {
				if(y % 2) {
					g.pb({x-y/2,x+y/2});
				}
				else g.pb({x/2-y+1,x/2+y});
			}
			if(i*i != n&&(i % 2||(n/i) % 2)) {
				x = i, y = (n/i);
				if(y % 2) {
					g.pb({x-y/2,x+y/2});
				}
				else g.pb({x/2-y+1,x/2+y});
			}
		}
	}
	for(pl i : g) {
		g.pb({-i.x+1,i.y});
	}
	sort(all(g)), g.erase(unique(all(g)),g.end());
	cout << g.size();
}