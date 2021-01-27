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
int n,k,c[105];
pi a[105];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); 
	int T; cin >> T;
	while(T--) {
		cin >> n >> k;
		int ans = -1;
		for(int i = 1;i <= n;i++) cin >> a[i].x >> a[i].y;
		for(int i = 1;i <= n;i++) {
			int j;
			for(j = 1;j <= n;j++) {
				if(abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y) > k) {
					break;
				}
			}
			if(j == n+1) {
				ans = 1;
				break;
			}
		}
		cout << ans << '\n';

	}
}