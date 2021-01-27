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
int n,m,k;
ll dist[1005][1005],d[1005];
ll s[1005],t[1005];
int w[1005];
vector <pair<int,ll>> v[1005];

// not solved

bool isok(ll mid) {
	for(int i = 1;i <= n;i++) {
		ll distime = dist[w[i]][1];
		for(int j = i;j >= 1;j--) {
			if(dist[1][j]+distime+min(d[j-1],t[i])-s[j] > mid) return 0;
		}
	}
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= m;i++) {
		int x,y,z; cin >> x >> y >> z;
		v[x].pb({y,z}), v[y].pb({x,z});
	}
	cin >> k;
	for(int i = 1;i <= k;i++) cin >> s[i] >> w[i] >> t[i];
	memset(dist,-1,sizeof(dist));
	priority_queue <pair<ll,int>> q;
	for(int st = 1;st <= n;st++) {
		q.push({0,st});
		while(!q.empty()) {
			auto now = q.top(); q.pop();
			if(dist[st][now.y] != -1) continue;
			dist[st][now.y] = -now.x;
			for(auto i : v[now.y]) q.push({now.x-i.y,i.x});
		}
	}
	ll l = 0, r = llINF;
	while(l < r) {
		ll mid = (l + r) >> 1;
		if(isok(mid)) r = mid;
		else l = mid+1;
	}
	cout << l;
}