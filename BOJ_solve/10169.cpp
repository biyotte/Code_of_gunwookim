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
const long long mod = 998244353;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,m,co,p[100005],isinc[300005];
vec v[100005];
vecpi v2[100005];
ll rans,t[400005];
int dep[100005],up[100005],tpos[100005];
int sz[100005];

struct Edge {
	int x,y,val,idx;
}e[300005];
vector <Edge> inc,rinc;

int Find(int x) {return (x^p[x] ? p[x] = Find(p[x]) : x);}
bool cmp(pi x,pi y) {return sz[x.x] > sz[y.x];}
bool cmpval(Edge x,Edge y) {return x.val < y.val;}
bool cmpidx(Edge x,Edge y) {return x.idx < y.idx;}

void dfs(int x,int pr) {
	sz[x] = 1;
	if(x == 1) p[x] = -1, dep[x] = 1;
	for(pi i : v2[x]) {
		if(i.x == pr) continue;
		p[i.x] = x;
		dep[i.x] = dep[x]+1;
		dfs(i.x,x);
		sz[x] += sz[i.x];
	}
}

void dfs2(int x,int pr,int hi) {
	sort(all(v2[x]),cmp);
	int ch = 1;
	tpos[x] = ++co;
	up[x] = hi;
	for(pi i : v2[x]) {
		if(i.x == pr) continue;
		if(ch) dfs2(i.x,x,hi), ch = 0;
		else dfs2(i.x,x,i.x);
	}
}

void update(int x,int l,int r,int rl,int rr,int val) {
	if(rl > r||l > rr) return;
	if(rl <= l&&r <= rr) {
		t[x] = val; return;
	}
	int mid = (l + r) >> 1;
	update(x*2,l,mid,rl,rr,val), update(x*2+1,mid+1,r,rl,rr,val);
}

ll query(int x,int l,int r,int wi) {
	if(wi < l||r < wi) return llINF;
	if(l == r) return t[x];
	int mid = (l + r) >> 1;
	return min({query(x*2,l,mid,wi),query(x*2+1,mid+1,r,wi),t[x]});
} 

void updateLCA(int x,int y,int val) {
	while(up[x]^up[y]) {
		if(dep[up[x]] < dep[up[y]]) swap(x,y);
		update(1,1,n,tpos[up[x]],tpos[x],val);
		x = p[up[x]];
	}
	if(dep[x] > dep[y]) swap(x,y);
	if(x^y) update(1,1,n,tpos[x]+1,tpos[y],val);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); 
	cin >> n >> m;
	for(int i = 1;i <= n;i++) p[i] = i;
	for(int i = 1;i <= m;i++) {
		int x,y,z; cin >> x >> y >> z;
		v[x].pb(y), v[y].pb(x);
		e[i] = {x,y,z,i};
	}
	sort(e+1,e+m+1,cmpval);
	for(int i = 1;i <= m;i++) {
		int x = e[i].x, y = e[i].y;
		if(Find(x) == Find(y)) continue;
		p[p[y]] = p[x];
		v2[x].pb({y,i}), v2[y].pb({x,i});
		rans += e[i].val;
		isinc[e[i].idx] = 1;
	}
	dfs(1,-1), dfs2(1,-1,1);
	sort(e+1,e+m+1,cmpidx);
	for(int i = 1;i <= m;i++) {
		if(isinc[i]) inc.pb(e[i]);
		else rinc.pb(e[i]);
	}
	sort(all(rinc),cmpval), reverse(all(rinc));
	for(int i = 1;i <= n*4;i++) t[i] = llINF;
	for(Edge now : rinc) updateLCA(now.x,now.y,now.val);
	for(int i = 1;i <= m;i++) {
		if(!isinc[i]) cout << rans << '\n';
		else {
			int x = e[i].x, y = e[i].y;
			if(dep[x] < dep[y]) swap(x,y);
			ll val = rans-e[i].val+query(1,1,n,tpos[x]);
			cout << (val >= llINF ? -1 : val) << '\n';
			
		}
	}
}