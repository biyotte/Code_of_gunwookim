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
int n,Q,co,p[100005];
int dep[100005],tpos[100005];
int sp[100005][20],sz[100005];
int up[100005];
ll t[400005],ans[100005];
vec v[100005];
pi a[100005];

struct Query {
	int x,y,l,r,idx;
}q[300005];

bool cmp(int x,int y) {return sz[x] > sz[y];}

int Find(int x) {return (x^p[x] ? p[x] = Find(p[x]) : x);}

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
	int fl = 0;
	for(int i : v[x]) {
		if(tpos[i]) continue;
		if(!fl) dfs2(i,pr), fl = 1;
		else dfs2(i,i);
	}
}

void update(int x,int l,int r,int wi,int val) {
	if(wi < l||r < wi) return;
	if(l == r) {t[x] += val; return;}
	int mid = (l + r) >> 1;
	update(x*2,l,mid,wi,val), update(x*2+1,mid+1,r,wi,val);
	t[x] = t[x*2]+t[x*2+1];
}

ll query(int x,int l,int r,int rl,int rr) {
	if(rl > r||l > rr) return 0;
	if(rl <= l&&r <= rr) return t[x];
	int mid = (l + r) >> 1;
	return query(x*2,l,mid,rl,rr)+query(x*2+1,mid+1,r,rl,rr);
}

ll queryLCA(int x,int y) {
	ll ret = 0;
	while(up[x]^up[y]) {
		if(dep[up[x]] < dep[up[y]]) swap(x,y);
		ret += query(1,1,n,tpos[up[x]],tpos[x]);
		x = sp[up[x]][0];
	}
	if(dep[x] > dep[y]) swap(x,y);
	return ret+query(1,1,n,tpos[x],tpos[y]);
}

bool cmpX(Query x,Query y) {return x.l < y.l;}
bool cmpY(Query x,Query y) {return x.r < y.r;}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> Q;
	for(int i = 1;i <= n;i++) cin >> a[i].x, a[i].y = i;
	for(int i = 1;i < n;i++) {
		int x,y; cin >> x >> y;
		v[x].pb(y), v[y].pb(x);
	}
	for(int i = 1;i <= Q;i++) {
		cin >> q[i].x >> q[i].y >> q[i].l >> q[i].r;
		q[i].idx = i;
	}
	dep[1] = 1, dfs(1,-1), dfs2(1,1);
	for(int i = 1;i < 20;i++) {
		for(int j = 1;j <= n;j++) sp[j][i] = sp[sp[j][i-1]][i-1];
	}
	sort(a+1,a+n+1);
	sort(q+1,q+Q+1,cmpX);
	for(int i = 1,pv = 1;i <= Q;i++) {
		while(pv <= n&&a[pv].x < q[i].l) update(1,1,n,tpos[a[pv].y],a[pv].x), pv++;
		ans[q[i].idx] = -queryLCA(q[i].x,q[i].y);
	}
	memset(t,0,sizeof(t));
	sort(q+1,q+Q+1,cmpY);
	for(int i = 1,pv = 1;i <= Q;i++) {
		while(pv <= n&&a[pv].x <= q[i].r) update(1,1,n,tpos[a[pv].y],a[pv].x), pv++;
		ans[q[i].idx] += queryLCA(q[i].x,q[i].y);
	}
	for(int i = 1;i <= Q;i++) cout << ans[i] << '\n';
}
