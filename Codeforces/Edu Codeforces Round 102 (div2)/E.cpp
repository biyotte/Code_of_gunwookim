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
const long long llINF = 1e16;
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
int n,m;
ll d[200005][4];
vector <pl> v[200005];
priority_queue <pair<ll,pi>> q;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= m;i++) {
		int x,y,z; cin >> x >> y >> z;
		v[x].pb({y,z}), v[y].pb({x,z});
	}
	memset(d,-1,sizeof(d));
	q.push({0,{1,0}});
	while(!q.empty()) {
		ll cost = -q.top().x;
		int x = q.top().y.x, y = q.top().y.y;
		q.pop();
		if(d[x][y] != -1) continue;
		d[x][y] = cost;
		for(pl i : v[x]) {
			q.push({-cost-i.y,{i.x,y}});
			if(y % 2 == 0) q.push({-cost,{i.x,y+1}});
			if(y / 2 == 0) q.push({-cost-2*i.y,{i.x,y+2}});
			if(y == 0) q.push({-cost-i.y,{i.x,y+3}});
		}
	}
	for(int i = 2;i <= n;i++) {if(d[i][3] == -1) return -1; cout << d[i][3] << ' ';}
}