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
ll k;
int bit[70];
int ans[2005];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while(T--) {
		cin >> k;
		if(k % 2) {
			cout << "-1\n";
			continue;
		}
		memset(ans,0,sizeof(ans));
		k /= 2;
		int n = 0;
		for(int i = 0;i <= 62;i++) {
			if(k & (1LL << i)) {
				ans[++n] = 1;
				if(!i) continue;
				ans[++n] = 1;
				for(int j = 2;j <= i;j++) {
					ans[++n] = 0;
				}
			}
		}
		cout << n << '\n';
		for(int i = 1;i <= n;i++) cout << ans[i] << ' ';
		cout << '\n';
	}
}