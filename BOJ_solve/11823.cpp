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
int k,Q;
vec p;
bool prime[15500005];
vec po[26];

void getPrime() {
	prime[0] = prime[1] = 1;
	for(int i = 2,j;i <= 15500000;i++) {
		if(prime[i]) continue;
		//cout << i << ' ';
		p.pb(i);
		if(i >= 4000) continue;
		for(j = i*i;j <= 15500000;j += i) {
			prime[j] = 1;
		}
	}
	for(int i = 1;i <= 30000000;i++) {
		int cnt = __builtin_popcount(i);
		po[cnt].pb(i);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); 
	getPrime();
	cin >> k >> Q;
	while(Q--) {
		int n; cin >> n;
		if(n % 2) {
			if(n > 15500000) {
				k = 30000000;
				continue;
			}
			int it = lower_bound(all(p),n)-p.begin()-1;
			k = min(30000000,k+p[it]-1);
		}
		else {
			int cnt = __builtin_popcount(n);
			k -= upper_bound(all(po[cnt]),k)-po[cnt].begin();
		}
	}
	cout << k;
}
