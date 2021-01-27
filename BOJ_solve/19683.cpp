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
int n,Q,co,tpos[100005],rtpos[100005],p[100005],up[100005];
int dep[100005],sz[100005];
int root,a[100005],ans;
int t0[400005],t1[400005];
int lazy[400005],leaf;
int isleaf[100005];
int cn[100005];
vec v[100005];

void dfs(int x,int pr,int depth) {
	sz[x] = 1, dep[x] = depth;
	for(int i : v[x]) {
		if(i == pr) continue;
		dfs(i,x,depth+1);
		p[i] = x;
		sz[x] += sz[i];
	}
}

bool cmp(int x,int y) {return sz[x] > sz[y];}

void dfs2(int x,int pr,int la) {
	sort(all(v[x]),cmp);
	tpos[x] = ++co, up[x] = la;
	rtpos[co] = x;
	int ch = 1;
	for(int i : v[x]) {
		if(i == pr) continue;
		if(ch) {dfs2(i,x,la), ch = 0;}
		else dfs2(i,x,i);
	}
}

int dfs3(int x,int pr) {
	int sum = (v[x].size() == 1);
	leaf += sum;
	isleaf[x] = sum;
	for(int i : v[x]) {
		if(i == pr) continue;
		int tmp = dfs3(i,x);
		if(tmp) ans++;
		else ans += 2;
		a[i] = tmp;
		sum += tmp;
	}
	sum %= 2;
	return sum;
}

void build(int x,int l,int r) {
	if(l == r) {
		t0[x] = (a[rtpos[l]] == 0);
		t1[x] = (a[rtpos[l]] == 1);
		return;
	}
	int mid = (l + r) >> 1;
	build(x*2,l,mid), build(x*2+1,mid+1,r);
	t0[x] = t0[x*2]+t0[x*2+1];
	t1[x] = t1[x*2]+t1[x*2+1];
}

void push(int x,int l,int r) {
	if(lazy[x]) {
		swap(t0[x],t1[x]);
		if(l^r) lazy[x*2] ^= 1, lazy[x*2+1] ^= 1;
		lazy[x] = 0;
	}
}

void update(int x,int l,int r,int rl,int rr) {
	push(x,l,r);
	if(rl > r||l > rr) return;
	if(rl <= l&&r <= rr) {
		lazy[x] ^= 1, push(x,l,r);
		return;
	}
	int mid = (l + r) >> 1;
	update(x*2,l,mid,rl,rr), update(x*2+1,mid+1,r,rl,rr);
	t0[x] = t0[x*2]+t0[x*2+1];
	t1[x] = t1[x*2]+t1[x*2+1];
}

pi query(int x,int l,int r,int rl,int rr) {
	push(x,l,r);
	if(rl > r||l > rr) return {0,0};
	if(rl <= l&&r <= rr) return {t0[x],t1[x]};
	int mid = (l + r) >> 1;
	pi L = query(x*2,l,mid,rl,rr), R = query(x*2+1,mid+1,r,rl,rr);
	return {L.x+R.x,L.y+R.y};
}

pi queryLCA(int x,int y) {
	pi ret = {0,0};
	while(up[x]^up[y]) {
		if(dep[up[x]] < dep[up[y]]) swap(x,y);
		pi tmp = query(1,1,n,tpos[up[x]],tpos[x]);
		update(1,1,n,tpos[up[x]],tpos[x]);
		ret.x += tmp.x, ret.y += tmp.y;
		x = p[up[x]];
	}
	if(x^y) {
		if(dep[x] > dep[y]) swap(x,y);
		pi tmp = query(1,1,n,tpos[x]+1,tpos[y]);
		update(1,1,n,tpos[x]+1,tpos[y]);
		ret.x += tmp.x, ret.y += tmp.y;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> Q;
	for(int i = 1;i < n;i++) {
		int x,y; cin >> x >> y;
		v[x].pb(y), v[y].pb(x);
	}
	for(int i = 1;i <= n;i++) {
		if(v[i].size() >= 2) root = i;
	}
	dfs(root,-1,1);
	dfs2(root,-1,root);
	dfs3(root,-1);
	build(1,1,n);
	while(Q--) {
		int cnt,x;
		int tans,tleaf;
		tans = ans, tleaf = leaf;
		cin >> cnt;
		vec q,rq;
		for(int i = 1;i <= cnt;i++) {
			cin >> x; q.pb(x);
			cn[x]++;
			tans++;
		}
		for(int i : q) {
			if(v[i].size() != 1) tleaf += cn[i], rq.pb(i);
			else {
				if(cn[i]) tleaf += cn[i]-1;
				if(cn[i]&&cn[i] % 2 == 0) rq.pb(i);
			}
			cn[i] = 0;
		}
		for(int i : rq) {
			pi tmp = queryLCA(i,root);
			tans += tmp.y-tmp.x;
		}
		if(tleaf % 2) cout << "-1\n";
		else cout << tans << '\n';
		for(int i : rq) queryLCA(i,root);
		for(int i : q) cn[i] = 0;
	}
}