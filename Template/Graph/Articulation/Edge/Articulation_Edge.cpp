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
const int MAXN = 100000;
const int MAXM = 1000000;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,m,co,now[MAXN+5],low[MAXN+5];
vecpi v[MAXN+5];
vec AEans;
pi edge[MAXM+5];

void AEdfs(int x,int la) {
	now[x] = low[x] = ++co;
	for(pi i : v[x]) {
		int nx = i.x, idx = i.y;
		if(nx == la) continue;
		if(now[nx]) low[x] = min(low[x],now[nx]);
		else {
			AEdfs(nx,x);
			if(low[nx] > now[x]) AEans.pb(idx);
			low[x] = min(low[x],low[nx]);
		}
	}
}

vec Articulation_Edge() {
	memset(now,0,sizeof(now));
	memset(low,0,sizeof(low));
	co = 0, AEans.clear();
	AEdfs(1,-1);
	return AEans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= m;i++) {
		int x,y; cin >> x >> y;
		v[x].pb({y,i}), v[y].pb({x,i});
		if(x > y) swap(x,y);
		edge[i] = {x,y};
	}
	vec ans = Articulation_Edge();
	vecpi ans2;
	for(int i : ans) ans2.pb({edge[i].x,edge[i].y});
	sort(all(ans2));
	cout << ans2.size() << '\n';
	for(pi i : ans2) cout << i.x << ' ' << i.y << '\n';
}