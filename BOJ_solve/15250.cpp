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
int T,n;
char a[1000005];
ll p1[1000005],p2[1000005];
ll h1[1000005],h2[1000005];

bool isSame(int l,int r,int l2,int r2) {
	ll v11 = (h1[r]-h1[l-1]*p1[r-l+1]%hmod1+hmod1)%hmod1;
	ll v12 = (h2[r]-h2[l-1]*p2[r-l+1]%hmod2+hmod2)%hmod2;

	ll v21 = (h1[r2]-h1[l2-1]*p1[r2-l2+1]%hmod1+hmod1)%hmod1;
	ll v22 = (h2[r2]-h2[l2-1]*p2[r2-l2+1]%hmod2+hmod2)%hmod2;
	return (v11*hmod2+v12 == v21*hmod2+v22);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	p1[0] = p2[0] = 1;
	for(int i = 1;i <= 1000000;i++) {
		p1[i] = p1[i-1]*base%hmod1;
		p2[i] = p2[i-1]*base%hmod2;
	}
	while(T--) {
		cin >> a+1; n = strlen(a+1);
		for(int i = 1;i <= n;i++) {
			h1[i] = (h1[i-1]*base+a[i])%hmod1;
			h2[i] = (h2[i-1]*base+a[i])%hmod2;
		}
		int l = 1,r = n,ll = 1,rr = n,ans = 1;
		while(ll < rr) {
			while(l < r&&!isSame(ll,l,r,rr)) l++, r--;
			if(l >= r) break;
			if(l == r-1) ans++;
			else ans += 2;
			l++, r--;
			ll = l, rr = r;
		}
		cout << ans << '\n';
	}
}
