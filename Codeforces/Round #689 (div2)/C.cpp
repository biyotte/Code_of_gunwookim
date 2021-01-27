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
int n,m;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); 
	int T; cin >> T;
	while(T--) {
		cin >> n >> m;
		int la = n+1;
		for(int i = 1;i <= n;i++) {
			int x; cin >> x;
			if(x != i) la = i;
		}
		ld ans = 1,gop = 1;
		if(la == n+1) gop = 0;
		for(int i = 1;i <= m;i++) {
			int x; ld p;
			cin >> x >> p;
			if(la <= x) gop *= (1-p);
		}
		cout << ans-gop << '\n';
	}
}