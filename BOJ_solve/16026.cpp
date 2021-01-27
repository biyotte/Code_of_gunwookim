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
long long mod = 1e9+7;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef vector <int> vec;
typedef vector <pi> vecpi; 
typedef long long ll;
int n,m;
ll d[2][100005];

struct Computer {
	int c,f,v;
}a[4005];

bool cmp(Computer x,Computer y) {
	if(x.f == y.f) return x.c > y.c; 
	return x.f > y.f;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i].c >> a[i].f >> a[i].v, a[i].v *= -1;
	cin >> m;
	for(int i = n+1;i <= n+m;i++) cin >> a[i].c >> a[i].f >> a[i].v, a[i].c *= -1;
	sort(a+1,a+n+m+1,cmp);
	for(int i = 1;i <= 100000;i++) d[0][i] = d[1][i] = -llINF;
	for(int i = 1;i <= n+m;i++) {
		for(int j = 0;j <= 100000;j++) {
			d[i%2][j] = d[(i-1)%2][j];
			if(j-a[i].c < 0||j-a[i].c > 100000) continue;
			d[i%2][j] = max(d[i%2][j],d[(i-1)%2][j-a[i].c]+a[i].v);
		}
	}
	ll ans = -INF;
	for(int j = 0;j <= 100000;j++) ans = max(ans,d[(n+m)%2][j]);
	cout << ans;
}