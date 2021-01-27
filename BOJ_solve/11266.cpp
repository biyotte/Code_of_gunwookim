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
const int MAXN = 10000;
const int MAXM = 100000;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,m,co,now[MAXN+5],low[MAXN+5];
vecpi v[MAXN+5];
vec AVans;

void AVdfs(int x,int la,int isroot) {
	now[x] = low[x] = ++co;
	int sub = 0;
	for(pi i : v[x]) {
		int nx = i.x, idx = i.y;
		if(nx == la) continue;
		if(now[nx]) low[x] = min(low[x],now[nx]);
		else {
			AVdfs(nx,x,0);
			sub++;
			if(isroot&&sub > 1) AVans.pb(x);
			else if(!isroot&&low[nx] >= now[x]) AVans.pb(x);
			low[x] = min(low[x],low[nx]);
		}
	}
}

vec Articulation_Vertex() {
	memset(now,0,sizeof(now));
	memset(low,0,sizeof(low));
	co = 0, AVans.clear();
	for(int i = 1;i <= n;i++) if(!now[i]) AVdfs(i,-1,1);
	sort(all(AVans)), AVans.erase(unique(all(AVans)),AVans.end());
	return AVans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= m;i++) {
		int x,y; cin >> x >> y;
		v[x].pb({y,i}), v[y].pb({x,i});
	}
	vec ans = Articulation_Vertex();
	cout << ans.size() << '\n';
	for(int i : ans) cout << i << ' ';
}