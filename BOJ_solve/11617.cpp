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
int n,m,Q,deg[300005];
int nam,cnt0,cnt2,same,q[300005];
int p[300005],nsz[300005],d2sz[300005];
pi ans[300005];
vecpi v[300005];
vec qu[300005];

int Find(int x) {return (x^p[x] ? p[x] = Find(p[x]) : x);}

void merge(int x,int y) {
	if(x == y) return; p[y] = x;
	same -= (d2sz[x] == nsz[x])+(d2sz[y] == nsz[y]);
	d2sz[x] += d2sz[y], nsz[x] += nsz[y];
	same += (d2sz[x] == nsz[x]);
} 

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) p[i] = i, nsz[i] = 1;
	for(int i = 1;i <= m;i++) {
		int x,y,z; cin >> x >> y >> z;
		v[z].pb({x,y});
	}
	cin >> Q; cnt0 = n;
	for(int i = 1;i <= Q;i++) {
		cin >> q[i];
		qu[q[i]].pb(i);

	}
	for(int i = 300000;i >= 0;i--) {
		for(pi j : v[i]) {
			int x = j.x, y = j.y;
			if(x == y) return -1;
			int px = Find(x), py = Find(y);
			nam++;			cnt0 -= (!deg[x])+(!deg[y]), cnt2 -= (deg[x] == 2)+(deg[y] == 2);
			same -= (d2sz[px] == nsz[px]--); d2sz[px] -= (deg[x] == 2); same += (d2sz[px] == nsz[px]);
			same -= (d2sz[py] == nsz[py]--); d2sz[py] -= (deg[y] == 2); same += (d2sz[py] == nsz[py]);
			deg[x]++, deg[y]++; merge(px,py);
			px = Find(x), py = Find(y);
			same -= (d2sz[px] == nsz[px]++); d2sz[px] += (deg[x] == 2); same += (d2sz[px] == nsz[px]);
			same -= (d2sz[py] == nsz[py]++); d2sz[py] += (deg[y] == 2); same += (d2sz[py] == nsz[py]);
			cnt2 += (deg[x] == 2)+(deg[y] == 2);
		}
		for(int idx : qu[i]) ans[idx] = {n-cnt0-cnt2+same,nam-cnt2+same};
	}
	for(int i = 1;i <= Q;i++) cout << ans[i].x << ' ' << ans[i].y << '\n';
}