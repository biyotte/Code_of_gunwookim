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
int n,m;
ll d[205][205],dist[205];
priority_queue <pi> q;

struct Edge {
	int x,y;
	ll cost,rev;
}edge[50005];

struct Vec {
	int x; ll y; int idx;
};
vector <Vec> v[205];

ll bfs(int st,int en,int idx) {
	for(int j = 1;j <= n;j++) dist[j] = llINF;
	q.push({0,st});
	while(!q.empty()) {
		auto now = q.top(); q.pop();
		ll cost = -now.x;
		int x = now.y;
		if(dist[x] != llINF) continue;
		dist[x] = cost;
		for(Vec i : v[x]) if(i.idx != idx&&dist[i.x] == llINF) q.push({-cost-i.y,i.x});
		if(x == edge[idx].y) q.push({-cost-edge[idx].cost,edge[idx].x});
	}
	return dist[en];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= m;i++) {
		int x,y; ll cost,rev; cin >> x >> y >> cost >> rev;
		v[x].pb({y,cost,i});
		edge[i] = {x,y,cost,rev};
	}
	for(int st = 1;st <= n;st++) {
		for(int j = 1;j <= n;j++) d[st][j] = llINF;
		q.push({0,st});
		while(!q.empty()) {
			auto now = q.top(); q.pop();
			ll cost = -now.x;
			int x = now.y;
			if(d[st][x] != llINF) continue;
			d[st][x] = cost;
			for(Vec i : v[x]) if(d[st][i.x] == llINF) q.push({-cost-i.y,i.x});
		}
	}
	ll ans = d[1][n]+d[n][1];
	for(int i = 1;i <= m;i++) {
		int st = edge[i].x, en = edge[i].y;
		ll cost = edge[i].cost, rev = edge[i].rev;
		ll go = min(d[1][n],d[1][en]+cost+d[st][n]);
		ll back = min(d[n][1],d[n][en]+cost+d[st][1]);
		if(ans > go+back+rev) {
			ans = min(ans,bfs(1,n,i)+bfs(n,1,i)+rev);
		}
	}
	cout << (ans >= llINF ? -1 : ans);
}