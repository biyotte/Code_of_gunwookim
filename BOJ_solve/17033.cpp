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
const long long llINF = 1e18;
long long mod;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi; 
typedef long long ll;
int n,Q,co;
int sz[100005],d[100005];
int p[100005],up[100005];
int tpos[100005],revtpos[100005];
int t[400005],a[100005];
vec v[100005];

bool cmp(int x,int y) {return sz[x] > sz[y];}

int dfs(int x,int depth) {
	d[x] = (sz[x] = 1)*depth;
	for(int i : v[x]) {
		if(sz[i]) continue;
		sz[x] += dfs(i,depth+1);
		p[i] = x;
	}
	return sz[x];
}

void dfs2(int x,int la) {
	tpos[x] = ++co;
	revtpos[co] = x;
	up[x] = la;
	sort(all(v[x]),cmp);
	int ch = 1;
	for(int i : v[x]) {
		if(up[i]) continue;
		if(ch) dfs2(i,la), ch = 0;
		else dfs2(i,i);
	}
}

void build(int x,int l,int r) {
	if(l == r) {t[x] = a[revtpos[l]]; return;}
	int mid = (l + r) >> 1;
	build(x*2,l,mid), build(x*2+1,mid+1,r);
	t[x] = t[x*2]^t[x*2+1];
}

void update(int x,int l,int r,int wi,int val) {
	if(wi < l||r < wi) return;
	if(l == r) {t[x] = val; return;}
	int mid = (l + r) >> 1;
	update(x*2,l,mid,wi,val), update(x*2+1,mid+1,r,wi,val);
	t[x] = t[x*2]^t[x*2+1];
}

int query(int x,int l,int r,int rl,int rr) {
	if(rl > r||l > rr) return 0;
	if(rl <= l&&r <= rr) return t[x];
	int mid = (l + r) >> 1;
	return query(x*2,l,mid,rl,rr)^query(x*2+1,mid+1,r,rl,rr);
}

int queryLCA(int x,int y) {
	int ret = 0;
	while(up[x] != up[y]) {
		if(d[up[x]] > d[up[y]]) {
			ret ^= query(1,1,n,tpos[up[x]],tpos[x]);
			x = p[up[x]];
		}
		else {
			ret ^= query(1,1,n,tpos[up[y]],tpos[y]);
			y = p[up[y]];
		}
	}
	if(tpos[x] > tpos[y]) swap(x,y);
	return ret^query(1,1,n,tpos[x],tpos[y]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> Q;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i < n;i++) {
		int x,y; cin >> x >> y;
		v[x].pb(y), v[y].pb(x);
	}
	dfs(1,1), dfs2(1,1);
	build(1,1,n);
	while(Q--) {
		int op,x,y;
		cin >> op >> x >> y;
		if(op & 1) update(1,1,n,tpos[x],y);
		else cout << queryLCA(x,y) << '\n';
	}
}