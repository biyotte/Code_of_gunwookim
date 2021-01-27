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
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pl;
typedef pair <ll,ll> pi;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,m,k,Q,wi[205];
int c[20005];
ll din[205][20005],dout[205][20005];
vecpi v[20005],rv[20005];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> k >> Q;
	for(int i = 1;i <= m;i++) {
		int x,y,z; cin >> x >> y >> z;
		v[x].pb({y,z}), rv[y].pb({x,z});
	}
	for(int i = 1;i <= k;i++) {
		cin >> wi[i];
		for(int j = 1;j <= n;j++) din[i][j] = dout[i][j] = llINF;
	}
	for(int st = 1;st <= k;st++) {
		priority_queue <pi> q;
		q.push({0,wi[st]});
		memset(c,0,sizeof(c));
		while(!q.empty()) {
			pi now = q.top(); q.pop();
			ll cost = -now.x, x = now.y;
			if(c[x]) continue;
			c[x] = 1;
			din[st][x] = cost;
			for(pi i : v[x]) {
				if(c[i.x]) continue;
				q.push({-cost-i.y,i.x});
			}
		}
	}
	for(int st = 1;st <= k;st++) {
		priority_queue <pi> q;
		q.push({0,wi[st]});
		memset(c,0,sizeof(c));
		while(!q.empty()) {
			pi now = q.top(); q.pop();
			ll cost = -now.x, x = now.y;
			if(c[x]) continue;
			c[x] = 1;
			dout[st][x] = cost;
			for(pi i : rv[x]) {
				if(c[i.x]) continue;
				q.push({-cost-i.y,i.x});
			}
		}
	}
	ll cnt = 0,ans = 0;
	while(Q--) {
		int x,y; cin >> x >> y;
		ll val = llINF;
		for(int i = 1;i <= k;i++) val = min(val,din[i][y]+dout[i][x]);
		if(val != llINF) cnt++, ans += val;
	}
	cout << cnt << '\n' << ans;
}