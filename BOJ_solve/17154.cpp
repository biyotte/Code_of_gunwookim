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
const long long mod = 1e18;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,m,ind[500005],del[500005];
int c[500005],cnt[500005],ecnt,vcnt;
int p[500005];
vec v[500005];
vecpi ans;
vec tr;

void dfs(int x) {
	if(c[x]) return;
	c[x] = 1;
	vcnt++;
	tr.pb(x);
	for(int i : v[x]) ecnt++, dfs(i);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= m;i++) {
		int x,y; cin >> x >> y;
		v[x].pb(y), v[y].pb(x);
		ind[x]++, ind[y]++;
	}
	for(int st = 1;st <= n;st++) {
		if(c[st]) continue;
		tr.clear(), vcnt = ecnt = 0;
		dfs(st);
		if((vcnt-1)*2 == ecnt) { // tree
			for(int i : tr) {
				if(ind[i] == 1) ans.pb({i,v[i][0]});
			}
		}
		else {
			queue <int> q;
			for(int i : tr) if(ind[i] == 1) q.push(i); 
			while(!q.empty()) {
				int x = q.front(); q.pop();
				del[x] = 1;
				for(int i : v[x]) {
					if(del[i]) continue;
					if(++cnt[i] == ind[i]-1) q.push(i);
				}
			}
			for(int i : tr) {
				if(del[i]) continue;
				for(int j : v[i]) {
					if(del[j]) ans.pb({i,j});
				}
			}
		}
	}
	sort(all(ans));
	cout << ans.size() << '\n';
	for(pi i : ans) cout << i.x << ' ' << i.y << '\n';
}