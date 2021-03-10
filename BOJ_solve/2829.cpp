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
const long long llINF = 1e16;
const long long mod = 1e9+7;
const long long hashmod = 100003;
const int MAXN = 100000;
const int MAXM = 1000000;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int a[405][405];
int sp[805][805];
int sm[805][805];
int n;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) {
			cin >> a[i][j];
		}
	}
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) {
			sp[i+j][i] = sp[i+j][i-1]+a[i][j];
		}
	}
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) {
			sm[i-j+n][i] = sm[i-j+n][i-1]+a[i][j];
		}
	}
	int ans = -INF;
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) {
			for(int len = 1;len <= n;len++) {
				int sx = i, sy = j, ex = i+len-1, ey = j+len-1;
				if(ex > n||ey > n) continue;
				ans = max(ans,(sm[sx-sy+n][ex]-sm[sx-sy+n][sx-1])-(sp[sx+ey][ex]-sp[sx+ey][sx-1]));
			}
		}
	}
	cout << ans;
}