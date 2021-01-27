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
int n,m,p[100005],cnt[100005],c[100005];
ll ans,mi;
vec v[100005];
vecpi edge;

int Find(int x) {return (x^p[x] ? p[x] = Find(p[x]) : x);}

void merge(int x,int y) {
	x = Find(x), y = Find(y);
	if(x == y) return;
	p[y] = x;
	cnt[x] += cnt[y];
}

void dfs(int x) {
	if(c[x]) return;
	c[x] = 1;
	for(int i : v[x]) {
		merge(x,i);
		dfs(i);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= m;i++) {
		int x,y; cin >> x >> y;
		v[x].pb(y);
		edge.pb({x,y});
	}
	for(int i = 1;i <= n;i++) cnt[i] = 1, p[i] = i;
	for(int i = 1;i <= n;i++) {
		if(v[i].size() < 2) continue;
		for(int j : v[i]) merge(v[i][0],j), dfs(j);
	}
	ll ans = 0;
	for(pi i : edge) {
		if(Find(i.x)^Find(i.y)) ans++;
	}
	for(int i = 1;i <= n;i++) {
		if(i^Find(i)) continue;
		ans += 1LL*cnt[i]*(cnt[i]-1);
	}
	cout << ans;
}