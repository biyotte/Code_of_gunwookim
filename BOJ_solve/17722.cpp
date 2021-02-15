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
int up[100005],t[400005],la[400005];
vec v[100005];

struct Query {
	int op,x,y;
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

void push(int x,int l,int r) {
	if(la[x]) {
		t[x] = r-l+1;
		if(l^r) la[x*2] = la[x*2+1] = 1;
		la[x] = 0;
	}
}

void update(int x,int l,int r,int rl,int rr) {
	push(x,l,r);
	if(rl > r||l > rr) return;
	if(rl <= l&&r <= rr) {
		la[x] = 1, push(x,l,r);
		return;
	}
	int mid = (l + r) >> 1;
	update(x*2,l,mid,rl,rr), update(x*2+1,mid+1,r,rl,rr);
	t[x] = t[x*2]+t[x*2+1];
}

int query(int x,int l,int r,int rl,int rr) {
	push(x,l,r);
	if(rl > r||l > rr) return 0;
	if(rl <= l&&r <= rr) return r-l+1-t[x];
	int mid = (l + r) >> 1;
	return query(x*2,l,mid,rl,rr)+query(x*2+1,mid+1,r,rl,rr);
}

int queryLCA(int x,int y,int op) {
	int ret = 0;
	while(up[x]^up[y]) {
		if(dep[up[x]] < dep[up[y]]) swap(x,y);
		if(op == 2) ret += query(1,1,n,tpos[up[x]],tpos[x]);
		else update(1,1,n,tpos[up[x]],tpos[x]);
		x = sp[up[x]][0];
	}
	if(dep[x] > dep[y]) swap(x,y);
	if(op == 2) return ret+(x == y ? 0 : query(1,1,n,tpos[x]+1,tpos[y]));
	else if(x^y) update(1,1,n,tpos[x]+1,tpos[y]);
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> Q;
	for(int i = 1;i <= n;i++) p[i] = i;
	for(int i = 1;i <= Q;i++) {
		cin >> q[i].op >> q[i].x >> q[i].y;
		if(q[i].op == 1) {
			if(Find(q[i].x) == Find(q[i].y)) continue;
			p[p[q[i].y]] = p[q[i].x];
			v[q[i].x].pb(q[i].y), v[q[i].y].pb(q[i].x);
		}
	}
	for(int i = 1;i <= n;i++) if(!dep[i]) dep[i] = 1, dfs(i,-1), dfs2(i,i);
	for(int i = 1;i < 20;i++) {
		for(int j = 1;j <= n;j++) sp[j][i] = sp[sp[j][i-1]][i-1];
	}
	for(int i = 1;i <= n;i++) p[i] = i;
	for(int i = 1;i <= Q;i++) {
		int x = q[i].x, y = q[i].y;
		if(q[i].op & 1) {
			if(Find(x) == Find(y)) queryLCA(x,y,1);
			else p[p[y]] = p[x];
		}
		else {
			if(Find(x) == Find(y)) cout << queryLCA(x,y,2) << '\n';
			else cout << "-1\n";
		}
	}
}
