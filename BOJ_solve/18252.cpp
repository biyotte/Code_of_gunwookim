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
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
ll ansa,ansb = INF;
int n,m,c[1005];

struct Edge {
	int nx,flow,cost;
};
vector <Edge> v[1005];
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);   
	cin >> n >> m;
	for(int i = 1;i <= m;i++) {
		int x,y,flow,cost;
		cin >> x >> y >> cost >> flow;
		v[x].pb({y,flow,cost});
		v[y].pb({x,flow,cost});
	}
	for(int mx = 1;mx <= 1000;mx++) {
		priority_queue <pi> q;
		q.push({0,1});
		memset(c,0,sizeof(c));
		while(!q.empty()) {
			auto now = q.top(); q.pop();
			if(c[now.y]) continue;
			c[now.y] = 1;
			if(now.y == n) {
				if(1LL*ansa*-now.x < 1LL*mx*ansb) ansa = mx, ansb = -now.x;
				break;
			}
			for(Edge i : v[now.y]) {
				if(i.flow >= mx) q.push({now.x-i.cost,i.nx});
			}
		}
	}
	cout << ansa*1000000/ansb;
}