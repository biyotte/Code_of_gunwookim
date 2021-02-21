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
const long long mod = 11092019;
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
int n,Q,co,sp[100005][20];
int dep[100005],sz[100005];
int tpos[100005],up[100005];
bool t[400005];
vec v[100005];

struct Query {
	int x,y,lca;
}q[100005];

bool cmp(int x,int y) {return sz[x] > sz[y];}
bool cmp2(Query x,Query y) {return dep[x.lca] > dep[y.lca];}

void dfs(int x,int pr) {
	sz[x] = 1;
	for(int i : v[x]) {
		if(i == pr) continue;
		dep[i] = dep[x]+1;
		dfs(i,x);
		sz[x] += sz[i];
		sp[i][0] = x;
	}
}

void dfs2(int x,int pr) {
	tpos[x] = ++co;
	up[x] = pr;
	sort(all(v[x]),cmp);
	bool fl = 0;
	for(int i : v[x]) {
		if(tpos[i]) continue;
		if(!fl) dfs2(i,pr), fl = 1;
		else dfs2(i,i);
	}
}

int LCA(int x,int y) {
	if(dep[x] < dep[y]) swap(x,y);
	for(int i = 19;i >= 0;i--) {
		if(dep[x] >= dep[y]+(1 << i)) x = sp[x][i];
	}
	if(x == y) return x;
	for(int i = 19;i >= 0;i--) {
		if(sp[x][i]^sp[y][i]) x = sp[x][i], y = sp[y][i];
	}
	return sp[x][0];
}

void update(int x,int l,int r,int wi) {
	if(wi < l||r < wi) return;
	if(l == r) {t[x] = 1; return;}
	int mid = (l + r) >> 1;
	update(x*2,l,mid,wi), update(x*2+1,mid+1,r,wi);
	t[x] = t[x*2]|t[x*2+1];
}

bool query(int x,int l,int r,int rl,int rr) {
	if(rl > r||l > rr) return false;
	if(rl <= l&&r <= rr) return t[x];
	int mid = (l + r) >> 1;
	return query(x*2,l,mid,rl,rr)|query(x*2+1,mid+1,r,rl,rr);
}

bool isHave(int x,int y) {
	bool ret = false;
	while(up[x]^up[y]) {
		if(dep[up[x]] < dep[up[y]]) swap(x,y);
		ret |= query(1,1,n,tpos[up[x]],tpos[x]);
		x = sp[up[x]][0];
	}
	if(dep[x] > dep[y]) swap(x,y);
	ret |= query(1,1,n,tpos[x],tpos[y]);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i < n;i++) {
		int x,y; cin >> x >> y;
		v[x].pb(y), v[y].pb(x);
	}
	cin >> Q;
	for(int i = 1;i <= Q;i++) {
		cin >> q[i].x >> q[i].y;
	}
	dep[1] = 1, dfs(1,-1), dfs2(1,1);
	for(int i = 1;i < 20;i++) {
		for(int j = 1;j <= n;j++) sp[j][i] = sp[sp[j][i-1]][i-1];
	}
	for(int i = 1;i <= Q;i++) {
		q[i].lca = LCA(q[i].x,q[i].y);
	}
	sort(q+1,q+Q+1,cmp2);
	vec ans;
	for(int i = 1;i <= Q;i++) {
		if(!isHave(q[i].x,q[i].y)) ans.pb(q[i].lca), update(1,1,n,tpos[q[i].lca]);
	}
	cout << ans.size() << '\n';
	for(int i : ans) cout << i << ' ';
}
