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
long long mod;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi; 
typedef long long ll;
int n,m,k,c[1005];
int d[1005][1005];
vecpi v[1005];
pi q[1005];
vector <pair<pi,int>> edge;
 
void dist(int st) {
	priority_queue <pi> q;
	q.push({0,st});
	memset(c,0,sizeof(c));
	while(!q.empty()) {
		auto x = q.top(); q.pop();
		if(c[x.y]) continue;
		c[x.y] = 1;
		d[st][x.y] = -x.x;
		for(pi i : v[x.y]) {
			q.push({x.x-i.y,i.x});
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	//int T; cin >> T;
	int T = 1;
	while(T--) {
		cin >> n >> m >> k;
		for(int i = 1;i <= m;i++) {
			int x,y,z; cin >> x >> y >> z;
			edge.pb({{x,y},z});
			v[x].pb({y,z});
			v[y].pb({x,z});
		}
		for(int i = 1;i <= k;i++) {
			cin >> q[i].x >> q[i].y;
		}
		for(int i = 1;i <= n;i++) dist(i);
		int ans = INF*2,sum;
		for(auto i : edge) {
			sum = 0;
			int x = i.x.x, y = i.x.y, z = i.y;
			for(int j = 1;j <= k;j++) {
				sum += min({d[q[j].x][q[j].y],d[q[j].x][x]+d[y][q[j].y],d[q[j].x][y]+d[x][q[j].y]});
			}
			ans = min(ans,sum);
		}
		cout << ans;
	}
}