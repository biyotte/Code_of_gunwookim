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
const long long mod = 1e9+7;
const long long hmod1 = 1e9+409;
const long long hmod2 = 1e9+433;
const long long base = 257;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,m,k,sum[2005];
pi a[2005];

bool cmp(pi x,pi y) {
	if(x.y == y.y) return x.x > y.x;
	return x.y < y.y;
}

int getAns(int l,int r) {
	memset(sum,0,sizeof(sum));
	for(int i = l;i <= r;i++) {
		sum[a[i].x]++;
		sum[a[i].y+1]--;
	}
	for(int i = 1;i <= n;i++) sum[i] += sum[i-1];
	for(int i = 1;i <= n;i++) sum[i] += sum[i-1];
	int ret = 0;
	for(int i = k;i <= n;i++) {
		ret = max(ret,sum[i]-sum[i-k]);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	for(int T = 1;1;T++) {
		//cin >> n >> m >> k;
		srand(time(NULL));
		n = rand()%1000+1, m = rand()%2000+1, k = rand()%n+1;
		for(int i = 1;i <= m;i++) {
			//cin >> a[i].x >> a[i].y;
			a[i].x = rand()%n+1, a[i].y = rand()%(n-a[i].x+1)+a[i].x;
		}
		sort(a+1,a+m+1);
		int ans = 0;
		for(int l = 0;l <= m;l++) {
			ans = max(ans,getAns(1,l)+getAns(l+1,m));
		}
		int ans2 = 0,ar,ar2;
		for(int r = k;r <= n;r++) {
			for(int r2 = k;r2 <= n;r2++) {
				int cnt = 0;
				for(int i = 1;i <= m;i++) {
					cnt += max(max(0,min(a[i].y,r)-max(a[i].x,r-k+1)+1),max(0,min(a[i].y,r2)-max(a[i].x,r2-k+1)+1));
				}
				if(ans2 < cnt) {
					ans2 = cnt;
					ar = r, ar2 = r2;
				}
			}
		}
		if(ans != ans2) {
			cout << ans << ' ' << ans2 << '\n';
			cout << ar << ' ' << ar2 << '\n';
			cout << n << ' ' << m << ' ' << k << '\n';
			for(int i = 1;i <= m;i++) {
				cout << a[i].x << ' ' << a[i].y << '\n';
			}
			return 0;
		}
	}
}
