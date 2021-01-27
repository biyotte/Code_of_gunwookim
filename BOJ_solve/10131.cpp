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
ll sz[500005],mx[500005],c[500005];
ll d[500005];
int n;
vec v[500005],v2[500005];
// d[x] : x 노드의 서브트리의 노드들을 방문했을때 각 노드별로 게임 시작 시간의 최대 값

bool cmp(int x,int y) {
	return d[x]-2*sz[x] > d[y]-2*sz[y];
}

void pre_dfs(int x,int pr) {
	for(int i : v2[x]) {
		if(i == pr) continue;
		pre_dfs(i,x);
		v[x].pb(i);
	}
}

void dfs(int x,int pr) {
	sz[x] = 1;
	d[x] = c[x];
	for(int i : v[x]) {
		dfs(i,x);
		sz[x] += sz[i];
		//d[x] = max(d[x],d[i]);
	}
	sort(all(v[x]),cmp);
	ll ti = 0;
	for(int i : v[x]) {
		ti++;
		d[x] = max(d[x],d[i]+ti);
		ti += sz[i]*2-1;
	}
	//cout <<x << ' ' << d[x] << '\n';
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> c[i];
	for(int i = 1;i < n;i++) {
		int x,y; cin >> x >> y;
		v2[x].pb(y), v2[y].pb(x);
	}
	pre_dfs(1,-1);
	dfs(1,-1);
	cout << max(d[1],(n*2-2)+c[1]);
}
