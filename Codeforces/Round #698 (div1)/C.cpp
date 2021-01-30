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
int n;
pl a[5005];
int ans[5005];

unsigned long long dist(pl x,pl y) {
	return (x.x-y.x)*(x.x-y.x)+(x.y-y.y)*(x.y-y.y);
}

bool isdun(pl x,pl y,pl z) {
	unsigned long long d1 = dist(x,y), d2 = dist(y,z), d3 = dist(x,z);
	return (d1+d2 <= d3);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i].x >> a[i].y;
	ans[1] = 1, ans[2] = 2;
	for(int i = 3;i <= n;i++) {
		ans[i] = i;
		for(int j = i;j >= 3;j--) {
			if(isdun(a[ans[j-2]],a[ans[j-1]],a[ans[j]])) {
				swap(ans[j-1],ans[j]);
			}
		}
		for(int j = 3;j <= i;j++) {
			if(isdun(a[ans[j-2]],a[ans[j-1]],a[ans[j]])) {
				swap(ans[j-2],ans[j]);
			}
		}
	}
	for(int i = 1;i <= n;i++) cout << ans[i] << ' ';
}
