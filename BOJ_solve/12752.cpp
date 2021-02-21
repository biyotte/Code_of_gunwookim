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
const int MAXN = 20000;
const int MAXM = 4000000;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pl;
typedef pair <ll,ll> pi;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,k,m,wi[6];
ll d[1 << 5][100005];
vecpi v[100005];
priority_queue <pair<ll,int>> q;

void DIJ(int x) {
	for(int i = 1;i <= n;i++) q.push({-d[x][i],i}); 
	while(!q.empty()) {
		pair <ll,int> now = q.top(); q.pop();
		if(d[x][now.y] != -now.x) continue;
		for(pi i : v[now.y]) {
			if(-now.x+i.y < d[x][i.x]) {
				d[x][i.x] = -now.x+i.y;
				q.push({now.x-i.y,i.x});
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k >> m;
	for(int i = 1;i <= k;i++) cin >> wi[i];
	for(int i = 1;i <= m;i++) {
		int x,y,z; cin >> x >> y >> z;
		v[x].pb({y,z}), v[y].pb({x,z});
	}
	for(int i = 0;i < (1 << k);i++) {
		for(int j = 1;j <= n;j++) d[i][j] = llINF;
	}
	for(int i = 0;i < k;i++) d[(1 << i)][wi[i+1]] = 0;
	for(int i = 1;i < (1 << k);i++) {
		for(int j = 1;j <= k;j++) {
			if(i & (1 << (j-1))) {
				for(int l = 1;l <= n;l++) {
					d[i][l] = min(d[i][l],d[i-(1 << (j-1))][l]+d[1 << (j-1)][l]);
				}
			}
		}
		DIJ(i);
	}
	ll ans = llINF;
	for(int i = 1;i <= n;i++) ans = min(ans,d[(1 << k)-1][i]);
	cout << ans;
}