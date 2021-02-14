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
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,Q,cnt,cent,sp[100005][20];
int dep[100005],sz[100005];
int pc[100005],vis[100005];
int c[100005],idx[100005],idxsz[100005];
vecpi v[100005];
vec vc[100005];
vector <priority_queue<pi>> sub[100005];
set <pi> mx[100005],ans;

void dfs(int x,int pr) {
	for(pi i : v[x]) {
		if(i.x == pr) continue;
		dep[i.x] = dep[x]+i.y;
		sp[i.x][0] = x;
		dfs(i.x,x);
	}
}

int get_sz(int x,int pr) {
	sz[x] = 1;
	for(pi i : v[x]) {
		if(!vis[i.x]&&i.x^pr) sz[x] += get_sz(i.x,x);
	}
	return sz[x];
}

int get_cent(int x,int pr,int cap) {
	for(pi i : v[x]) {
		if(!vis[i.x]&&i.x^pr&&sz[i.x] > cap) return get_cent(i.x,x,cap);
	}
	return x;
}

int make_cent(int x) {
	int cap = get_sz(x,-1), now_cent = get_cent(x,-1,cap/2);
	vis[now_cent] = 1;
	for(pi i : v[now_cent]) {
		if(vis[i.x]) continue;
		int child_cent = make_cent(i.x);
		pc[child_cent] = now_cent;
		vc[now_cent].pb(child_cent);
		idx[child_cent] = idxsz[now_cent];
		idxsz[now_cent]++;
		sub[now_cent].pb({});
	}
	return now_cent;
}

int LCA(int x,int y) {
	if(dep[x] < dep[y]) swap(x,y);
	for(int i = 19;i >= 0;i--) {
		if(dep[y]+(1 << i) <= dep[x]) x = sp[x][i];
	}
	if(x == y) return x;
	for(int i = 19;i >= 0;i--) {
		if(sp[x][i]^sp[y][i]) x = sp[x][i], y = sp[y][i];
	}
	return sp[x][0];
}

int dist(int x,int y) {
	return dep[x]+dep[y]-2*dep[LCA(x,y)];
}

void update(int x) {
	c[x] ^= 1;
	if(!c[x]) cnt--;
	else cnt++;
	int st = x,di,la = -1;
	while(x) {
		if(la >= idxsz[x]) exit(-1);
		if(mx[x].size() >= 2) {
			if(ans.find({mx[x].begin()->x+next(mx[x].begin())->x,x}) == ans.end()) exit(-1);
			ans.erase(ans.find({mx[x].begin()->x+next(mx[x].begin())->x,x}));
		}
		if(la == -1) {
			if(c[st]) mx[x].insert({0,x});
			else {
				if(mx[x].find({0,x}) == mx[x].end()) exit(-1);
				mx[x].erase(mx[x].find({0,x}));
			}
		}
		else {
			if(!sub[x][la].empty()) {
				if(mx[x].find({-sub[x][la].top().x,sub[x][la].top().y}) == mx[x].end()) exit(-1);
				mx[x].erase(mx[x].find({-sub[x][la].top().x,sub[x][la].top().y}));
			}
			while(!sub[x][la].empty()&&!c[sub[x][la].top().y]) sub[x][la].pop();
			if(c[st]) sub[x][la].push({dist(x,st),st});
			if(!sub[x][la].empty()) mx[x].insert({-sub[x][la].top().x,sub[x][la].top().y});
		}
		if(mx[x].size() >= 2) ans.insert({mx[x].begin()->x+next(mx[x].begin())->x,x});
		la = idx[x], x = pc[x];

	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i < n;i++) {
		int x,y,z; cin >> x >> y >> z;
		v[x].pb({y,z}), v[y].pb({x,z});
	}
	dep[1] = 0, dfs(1,-1), cent = make_cent(1);
	for(int i = 1;i < 20;i++) {
		for(int j = 1;j <= n;j++) sp[j][i] = sp[sp[j][i-1]][i-1];
	}
	for(int i = 1;i <= n;i++) update(i);
	cin >> Q;
	for(int i = 1,x,y;i <= Q;i++) {
		cin >> x;
		if(x & 1) cin >> y, update(y);
		else {
			if(!ans.empty()) cout << max(0,-ans.begin()->x) << '\n';
			else if(cnt) {
				if(cnt != 1) return -1;
				cout << "0\n";
			}
			else cout << "-1\n";
		}
	}
}
