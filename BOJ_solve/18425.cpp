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
int n,dep[200005];
int sp[200005][20];
ll C1[200005],C2[200005];
ll d[200005]; // i번 노드와 i번 노드의 부모를 잇는 간선을 지나는 횟수
ll ans;

struct Road {
	int x,c1,c2;
};
vector <Road> v[200005];

void dfs(int x,int pr) {
	for(Road j : v[x]) {
		int i = j.x;
		if(i == pr) continue;
		sp[i][0] = x;
		C1[i] = j.c1, C2[i] = j.c2;
		dep[i] = dep[x]+1;
		dfs(i,x);
	}
}

void dfs2(int x,int pr) {
	for(Road i : v[x]) {
		if(i.x == pr) continue;
		dfs2(i.x,x);
		d[x] += d[i.x];
	}
	ans += min(d[x]*C1[x],C2[x]);
}

int LCA(int x,int y) {
	if(dep[x] > dep[y]) swap(x,y);
	for(int i = 19;i >= 0;i--) {
		if(dep[y]-(1 << i) >= dep[x]) {
			y = sp[y][i];
		}
	}
	if(x == y) return x;
	for(int i = 19;i >= 0;i--) {
		if(sp[x][i]^sp[y][i]) {
			x = sp[x][i];
			y = sp[y][i];
		}
	}
	return sp[x][0];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i < n;i++) {
		int x,y,c1,c2; cin >> x >> y >> c1 >> c2;
		v[x].pb({y,c1,c2}), v[y].pb({x,c1,c2});
	}
	dep[1] = sp[1][0] = 1;
	dfs(1,-1);
	for(int i = 1;i <= 19;i++) {
		for(int j = 1;j <= n;j++) {
			sp[j][i] = sp[sp[j][i-1]][i-1];
		}
	}
	for(int i = 1;i < n;i++) {
		int lca = LCA(i,i+1);
		d[i]++, d[i+1]++, d[lca] -= 2;
	}
	dfs2(1,-1);
	cout << ans;
}