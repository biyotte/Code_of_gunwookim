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
const long long mod = 998244353;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,m,k,c[50005],w[50005],dist[50005];
pi a[50005];
vecpi v[50005];
int inq[50005],ans[50005];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++) {
		int x,y,z; cin >> x >> y >> z;
		v[x].pb({y,z}), v[y].pb({x,z});
	}
	for(int i = 1;i <= k;i++) cin >> a[i].x >> a[i].y, w[a[i].x] = i;
	priority_queue <pi> q;
	q.push({0,n});
	while(!q.empty()) {
		int cost = -q.top().x, x = q.top().y; q.pop();
		if(c[x]) continue; c[x] = 1;
		dist[x] = cost;
		if(w[x]) inq[w[x]] = a[w[x]].y-cost;
		for(pi i : v[x]) q.push({-cost-i.y,i.x});
	}
	for(int i = 1;i <= k;i++) q.push({inq[i],a[i].x});
	memset(c,0,sizeof(c));
	while(!q.empty()) {
		int nam = q.top().x, x = q.top().y; q.pop();
		if(c[x]) continue; c[x] = 1;
		if(dist[x]+nam >= 0) ans[x] = 1;
		for(pi i : v[x]) q.push({nam-i.y,i.x});
	}
	for(int i = 1;i < n;i++) cout << ans[i] << '\n';
}