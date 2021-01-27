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
int n,m,h[505][505],cl[505][505],cr[505][505];
char a[505][505];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); 
	int T; cin >> T;
	while(T--) {
		cin >> n >> m;
		for(int i = 1;i <= n;i++) {
			cin >> a[i]+1;
		}
		for(int i = 0;i <= n+1;i++) {
			for(int j = 0;j <= m+1;j++) h[i][j] = cl[i][j] = cr[i][j] = 0;
		}
		for(int i = n;i >= 1;i--) {
			for(int j = m;j >= 1;j--) {
				if(a[i][j] == '*') cl[i][j] = cl[i+1][j-1]+1;
			}
		}
		for(int i = n;i >= 1;i--) {
			for(int j = 1;j <= m;j++) {
				if(a[i][j] == '*') cr[i][j] = cr[i+1][j+1]+1;
			}
		}
		int ans = 0;
		for(int i = n;i >= 1;i--) {
			for(int j = 1;j <= m;j++) {
				if(a[i][j] == '.') continue;
				h[i][j] = min(h[i+1][j]+1,min(cl[i][j],cr[i][j]));
				ans += h[i][j];
			}
		}
		cout << ans << '\n';
	}
}