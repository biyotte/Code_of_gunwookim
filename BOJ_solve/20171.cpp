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
const long long llINF = 5e18;
const long long mod = 1e9+7;
const long long hmod1 = 1e9+409;
const long long hmod2 = 1e9+433;
const long long base = 257;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,k,nope[100005];
int c[100005],c2[100005];
vecpi v[100005];

// not solved

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	cin >> n >> k;
	for(int i = 1;i < n;i++) {
		int x,y,z; cin >> x >> y >> z;
		v[x].pb({y,z}), v[y].pb({x,z});
	}
	priority_queue <pi> q;
	for(int i = 1;i <= k;i++) {
		int x; cin >> x;

		q.push({0,x});
	}
	memset(c2,-1,sizeof(c2));
	while(!q.empty()) {
		int cost = -q.top().x, now = q.top().y; q.pop();
		if(c2[now] == cost) {
			nope[now] = 1;
			continue;
		}
		if(c[now]) continue;
		c[now] = 1;
		c2[now] = cost;
		for(pi i : v[now]) {
			q.push({-cost-i.y,i.x});
		}
	}
	int ans = 0;
	for(int i = 1;i <= n;i++) {
		if(!nope[i]) cout << i << ' ', ans++;
	}
	cout << ans;
}
