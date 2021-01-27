#include <bits/stdc++.h>
#define MAXN 200005
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
const long long mod = 998244353;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,m,dep[300005];
int all[300005],sub[300005];
int con[300005];
vec v[300005],v2[300005];

void dfs(int x,int pr,int depth) {
	dep[x] = depth;
	for(int i : v2[x]) {
		if(i == pr) continue;
		if(dep[i]) {
			if(dep[x] > dep[i]) all[i]++, sub[x]++;
			continue;
		}
		v[x].pb(i);
		int tmp = all[x];
		dfs(i,x,depth+1);
		con[i] = all[x]-tmp;
		all[x] += all[i];
		sub[x] += sub[i];
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); 
	cin >> n >> m;
	for(int i = 1;i <= m;i++) {
		int x,y; cin >> x >> y;
		v2[x].pb(y), v2[y].pb(x);
	}
	dfs(1,-1,1);
	ll ans = 0;
	for(int i = 1;i <= n;i++) {
		int can = 1;
		for(int j : v[i]) {
			if(all[j]||sub[j]-con[j] >= 2) {
				can = 0;
				break;
			}
		}
		if(m-n+1-sub[i]) can = 0;
		ans += i*can;
	}
	cout << ans;
}
