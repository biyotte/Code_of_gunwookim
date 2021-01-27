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
const long long mod = 1e18;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,m,k;
vecpi v[250005];
int c[300005],st[300005];
priority_queue <pair<ll,pair<int,pi>>> q;
ll ans[300005],en[300005];
struct Edge {int x,y; ll w;}edge[300005];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= m;i++) {
		int x,y; ll w; cin >> x >> y >> w;
		v[x].pb({y,w}), v[y].pb({x,w});
		edge[i] = {x,y,w};
	}
	cin >> k;
	for(int i = 1;i <= k;i++) {
		cin >> st[i];
		q.push({0,{-i,{-st[i],st[i]}}});
	}
	while(!q.empty()) {
		auto now = q.top(); q.pop();
		ll cost = -now.x; int sta = -now.y.x, x = -now.y.y.x, pr = now.y.y.y;
		if(c[x]) continue;
		c[x] = sta, en[x] = cost;
		for(pi i : v[x]) {
			q.push({-cost-i.y,{-sta,{-i.x,x}}});
		}
	}
	for(int i = 1;i <= m;i++) {
		int x,y; ll w;
		x = edge[i].x, y = edge[i].y, w = edge[i].w;
		if(c[x] == c[y]) ans[c[x]] += w*2;
		else {
			if(en[x] < en[y]) swap(x,y);
			ans[c[y]] += (en[x]-en[y])*2;
			w -= en[x]-en[y];
			ans[c[x]] += w;
			ans[c[y]] += w;
		}
	}
	for(int i = 1;i <= k;i++) {
		if(ans[i] % 2) cout << ans[i]/2 << ".5\n";
		else cout << ans[i]/2 << ".0\n";
	}
}