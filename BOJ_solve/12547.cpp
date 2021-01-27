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
int T;
int n,c;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); 
	cin >> T;
	for(int tc = 1;tc <= T;tc++) {
		cin >> n >> c;
		int i,ans = 0,sum = 0;
		for(i = 0;(1 << i) <= c;i++) {
			ans += (n-sum/(1 << i));
			sum += (1 << i)*(n-sum/(1 << i));
		}
		i--;
		if((1 << i) != c) {
			ans += (n-sum/c);
		}
		cout << "Case #" << tc << ": " << ans << '\n';
	}
}