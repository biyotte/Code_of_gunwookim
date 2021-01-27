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
int n,c[200005],co,p[200005],isc[200005];
ll d[200005],ans,cnt[200005];
vec v[200005];
vec cycle;

struct Edge {
	int x,y,idx;
};
vector <Edge> edge;

int find_cycle(int x,int pr) {
	if(c[x]) {
		for(int i = pr;i != x;i = p[i]) cycle.pb(i);
		cycle.pb(x);
		return 1;
	}
	c[x] = 1;
	p[x] = pr;
	for(int i : v[x]) {
		if(i == pr) continue;
		if(find_cycle(i,x)) return 1;
	}
	return 0;
}

void go(int x,int pr) {
	if(c[x]) return;
	c[x] = cnt[x] = 1;
	for(int i : v[x]) {
		if(i == pr||isc[i]) continue;
		go(i,x);
		cnt[x] += cnt[i];
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int T; cin >> T;
	//int T = 1;
	while(T--) {
		cin >> n;
		for(int i = 1;i <= n;i++) v[i].clear(), isc[i] = c[i] = 0;
		cycle.clear();
		for(int i = 1;i <= n;i++) {
			int x,y; cin >> x >> y;
			v[x].pb(y), v[y].pb(x);
		}	
		find_cycle(1,-1);
		for(int i = 1;i <= n;i++) c[i] = cnt[i] = 0;
		for(int i : cycle) isc[i] = 1;
		for(int i : cycle) go(i,-1);
		ll tot = 0;
		for(int i : cycle) {
			tot += cnt[i];
		}
		ans = 0;
		for(int i : cycle) {
			ans += (tot-cnt[i])*cnt[i];
		}
		cout << ans/2+1LL*n*(n-1)/2 << '\n';
	}
}
