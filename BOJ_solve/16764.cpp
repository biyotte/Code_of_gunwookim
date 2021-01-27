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
const int mod = 1e9+7;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
vec rev;
map <pair<int,pair<int,pair<int,pi>>>,int> cnt;
int n,p[5];
int a[50005][6];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= 5;j++) cin >> a[i][j];
	}
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j < 32;j++) {
			pair<int,pair<int,pair<int,pi>>> x;
			for(int k = 0;k < 5;k++) {
				if(j & (1 << k)) p[k] = a[i][k+1];
				else p[k] = 0;
			}
			sort(p,p+5);
			x.x = p[0];
			x.y.x = p[1];
			x.y.y.x = p[2];
			x.y.y.y.x = p[3];
			x.y.y.y.y = p[4];
			cnt[x]++;
		}
	}
	ll ans = 0;
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j < 32;j++) {
			int cn = 0;
			pair<int,pair<int,pair<int,pi>>> x;
			for(int k = 0;k < 5;k++) {
				if(j & (1 << k)) cn++, p[k] = a[i][k+1];
				else p[k] = 0;
			}
			sort(p,p+5);
			x.x = p[0];
			x.y.x = p[1];
			x.y.y.x = p[2];
			x.y.y.y.x = p[3];
			x.y.y.y.y = p[4];
			if(cn % 2) ans += (n-cnt[x]);
			else ans -= (n-cnt[x]);
		}
	}
	cout << ans/2;
} 
