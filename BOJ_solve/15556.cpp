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
int n,m,c[100005];
int S,T,U,V;
ll ds[100005],dt[100005],du[100005],dv[100005];
ll dpu[100005],dpv[100005];
vecpi v[100005];

void BFS(int st,int op) {
	priority_queue <pair<ll,int>> q;
	q.push({0,st});
	memset(c,0,sizeof(c));
	while(!q.empty()) {
		ll cost = -q.top().x; int x = q.top().y; q.pop();
		if(c[x]++) continue;
		if(!op) ds[x] = cost;
		else if(op == 1) dt[x] = cost;
		else if(op == 2) du[x] = cost;
		else dv[x] = cost;
		for(pi i : v[x]) q.push({-cost-i.y,i.x});
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> S >> T >> U >> V;
	for(int i = 1;i <= m;i++) {
		int x,y,z; cin >> x >> y >> z;
		v[x].pb({y,z}), v[y].pb({x,z});
	}
	BFS(S,0), BFS(T,1), BFS(U,2), BFS(V,3);
	vector <pair<ll,int>> vis;
	for(int i = 1;i <= n;i++) {
		dpu[i] = dpv[i] = llINF;
		if(ds[T] == ds[i]+dt[i]) vis.pb({dt[i],i}); // on shortest path
	}
	sort(all(vis));
	ll ans = du[V];
	for(auto now : vis) {
		int x = now.y;
		dpu[x] = du[x], dpv[x] = dv[x];
		for(pi i : v[x]) {
			if(dt[x] == dt[i.x]+i.y) {
				dpu[x] = min(dpu[x],dpu[i.x]);
				dpv[x] = min(dpv[x],dpv[i.x]);
			}
		}
		ans = min({ans,dpu[x]+dv[x],dpv[x]+du[x]});
	}
	cout << ans;
}