#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define all(v) v.begin(),v.end()
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
using namespace std;
const long long INF = 2e9;
const int TMX = 1 << 18;
const long long llINF = 1e18;
const long long mod = 1e9+7;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,m,k,Q,c[20005];
int dist[25][25],bit[25];
int d[1 << 20][21];
vecpi v[20005];
priority_queue <pi> q;

int go(int b,int pv) {
	if(d[b][pv] != -1) return d[b][pv];
	d[b][pv] = INF;
	if(b == (1 << k)-1) return d[b][pv] = dist[pv][k+1];
	for(int i = 1;i <= k;i++) {
		if(!(b & (1 << (i-1)))&&(bit[i] & b) == bit[i]) {
			d[b][pv] = min(d[b][pv],go(b|(1 << (i-1)),i)+dist[pv][i]);
		}
	}
	return d[b][pv];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> k;
	memset(d,-1,sizeof(d));
	for(int i = 1;i <= m;i++) {
		int x,y,z; cin >> x >> y >> z;
		v[x].pb({y,z}), v[y].pb({x,z});
	}
	for(int st = 1,cost,x;st <= k+2;st++) {
		q.push({0,(st == k+2 ? n : st)});
		memset(c,0,sizeof(c));
		while(!q.empty()) {
			cost = -q.top().x, x = q.top().y; q.pop();
			if(c[x]) continue; c[x] = 1;
			if(x <= k+1||x == n) {
				if(x == n) dist[st-1][k+1] = cost;
				else dist[st-1][x-1] = cost;
			}
			for(pi i : v[x]) if(!c[i.x]) q.push({-cost-i.y,i.x});
		}
	}
	cin >> Q;
	for(int i = 1;i <= Q;i++) {
		int x,y; cin >> x >> y;
		bit[y-1] |= (1 << (x-2));
	}
	int ans = INF;
	if(!k) ans = dist[0][k+1];
	for(int i = 1;i <= k;i++) {
		if(!bit[i]) ans = min(ans,go(1 << (i-1),i)+dist[0][i]);
	}
	cout << ans;
}
