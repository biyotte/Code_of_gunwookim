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
const long long llINF = 1e18+10;
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
pi a[100005];
vec vx[20005],vy[20005];
vec sx[20005],sy[20005];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) {
		int x,y; cin >> x >> y;
		vx[x+10000].pb(y), vy[y+10000].pb(x);
		a[i] = {x,y};
	}
	for(int i = 0;i <= 20000;i++) {
		sort(all(vx[i])), sort(all(vy[i]));
		sx[i].pb(0), sy[i].pb(0);
		for(int j : vx[i]) sx[i].pb(sx[i].back()+j);
		for(int j : vy[i]) sy[i].pb(sy[i].back()+j);
	}
	ll ans = 0;
	for(int i = 1;i <= n;i++) {
		int x = a[i].x, y = a[i].y;
		int it = lower_bound(all(vx[x+10000]),y)-vx[x+10000].begin()+1;
		ll ysum = y*it-sx[x+10000][it]+(sx[x+10000].back()-sx[x+10000][it])-y*((int)sx[x+10000].size()-it-1);
		it = lower_bound(all(vy[y+10000]),x)-vy[y+10000].begin()+1;
		ll xsum = x*it-sy[y+10000][it]+(sy[y+10000].back()-sy[y+10000][it])-x*((int)sy[y+10000].size()-it-1);
		ans += xsum*ysum%mod;
		ans %= mod;
	}
	cout << ans;
}
