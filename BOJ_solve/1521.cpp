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
int n,fact = 1;
int a[10],c[10],b[10];
ld d[40400][41];

int f() {
	memset(c,0,sizeof(c));
	int gop = fact/n,ret = 1;
	for(int i = 1;i < n;i++) {
		int cnt = 0;
		for(int j = 1;j < a[i];j++) {
			cnt += 1-c[j];
		}
		c[a[i]] = 1;
		ret += gop*cnt;
		gop /= (n-i);
	}
	return ret;
}

int main() {
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= n;i++) fact *= i;
	d[f()][0] = 1.0;
	for(int i = fact;i >= 1;i--) {
		int gop = fact/n,nam = i-1;
		memset(c,0,sizeof(c));
		for(int j = 1;j <= n;j++) {
			int wh = nam/gop+1;
			for(int k = 1;k <= n;k++) {
				if(!c[k]&&!--wh) {
					a[j] = k;
					c[k] = 1;
					break;
				}
			}
			nam %= gop;
			if(n^j) gop /= (n-j);
		}
		ld cnt = 0;
		for(int j = 1;j <= n;j++) {
			for(int k = j+1;k <= n;k++) {
				if(a[j] > a[k]) cnt += 1;
			}
		}
		for(int h = 0;h < 40;h++) {
			for(int j = 1;j <= n;j++) {
				for(int k = j+1;k <= n;k++) {
					if(a[j] > a[k]) {
						swap(a[j],a[k]);
						d[f()][h] += d[i][h-1]/cnt;
						swap(a[j],a[k]);
					}
				}
			}
		}
	}
	ld ans = 0;
	for(int i = 0;i < 40;i++) ans += d[1][i]*(ld)i;
	printf("%.12LF",ans);
}	