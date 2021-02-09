#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define all(v) v.begin(),v.end()
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
using namespace std;
const long long INF = 1e9;
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
int n;
int p[200005];
ll dep[200005],a[200005],d[200005];
ll ans;
vecpi v[200005];
set <pair<pl,int>> s[200005];

void dfs(int x) {
	for(pi i : v[x]) {
		dep[i.x] = dep[x]+i.y;
		dfs(i.x);
	}
}

int merge(int x,int y) {
	if(s[x].size() < s[y].size()) swap(x,y);
	for(auto i : s[y]) s[x].insert(i);
	return x;
}

int go(int x) {
	int now = x;
	for(pi i : v[x]) {
		int idx = go(i.x);
		now = merge(now,idx);
	}
	if(d[x] == -1) s[now].insert({{dep[x],a[x]},x});
	else {
		vector <pair<pl,int>> er;
		auto it = s[now].upper_bound({{dep[x]+d[x]+1,0},0});
		int nam = a[x];
		while(it != s[now].begin()&&nam) {
			it--;
			er.pb(*it);
			if(it->x.y <= nam) {
				ans += it->x.y;
				nam -= it->x.y;
			}
			else {
				ans += nam;
				s[now].insert({{it->x.x,it->x.y-nam},it->y});
				nam = 0;
			}
		}
		for(auto i : er) s[now].erase(i);
	}
	return now;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= n;i++) cin >> d[i];
	for(int i = 2;i <= n;i++) cin >> p[i];
	for(int i = 2;i <= n;i++) {
		int x; cin >> x;
		v[p[i]].pb({i,x});
	}
	dfs(1);
	int idx = go(1);
	cout << ans;
}
