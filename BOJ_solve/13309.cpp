#include <bits/stdc++.h>
#define MAXN 200005
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
const long long mod = 998244353;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,Q,co,t[MAXN*4];
int dep[MAXN],p[MAXN],up[MAXN];
int sz[MAXN],tpos[MAXN];
vec v[MAXN];

bool cmp(int x,int y) {
	return sz[x] > sz[y];
}

void dfs1(int x,int depth) {
	sz[x] = 1, dep[x] = depth;
	for(int &i : v[x]) {
		if(sz[i]) continue;
		dfs1(i,depth+1);
		sz[x] += sz[i];
		p[i] = x;
	}
}

void dfs2(int x,int la) {
	tpos[x] = ++co;
	up[x] = la;
	sort(all(v[x]),cmp);
	int ch = 0;
	for(int i : v[x]) {
		if(tpos[i]) continue;
		if(!ch) dfs2(i,la), ch = 1;
		else dfs2(i,i);
	}
}

void update(int x,int l,int r,int wi) {
	if(wi < l||r < wi) return;
	if(l == r) {
		t[x] = 1;
		return;
	}
	int mid = (l + r) >> 1;
	update(x*2,l,mid,wi), update(x*2+1,mid+1,r,wi);
	t[x] = t[x*2]|t[x*2+1];
}

int query(int x,int l,int r,int rl,int rr) {
	if(rl > r||l > rr) return 0;
	if(rl <= l&&r <= rr) return t[x];
	int mid = (l + r) >> 1;
	return query(x*2,l,mid,rl,rr)|query(x*2+1,mid+1,r,rl,rr);
}

bool isConnect(int x,int y) {
	int ret = 0;
	while(up[x]^up[y]) {
		if(dep[up[x]] < dep[up[y]]) swap(x,y);
		ret |= query(1,1,n,tpos[up[x]],tpos[x]);
		x = p[up[x]];
	}
	if(dep[x] > dep[y]) swap(x,y);
	if(x^y) ret |= query(1,1,n,tpos[x]+1,tpos[y]);
	return !ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); 
	cin >> n >> Q;
	for(int i = 2;i <= n;i++) {
		int x; cin >> x;
		v[x].pb(i), v[i].pb(x);
	}
	dfs1(1,1), dfs2(1,1);
	while(Q--) {
		int x,y,op;
		cin >> x >> y >> op;
		bool is = isConnsect(x,y);
		cout << (is ? "YES\n" : "NO\n");
		if(op) {
			if(is) {
				if(x^1) update(1,1,n,tpos[x]);
			}
			else {
				if(y^1) update(1,1,n,tpos[y]);
			}
		}
	}
}
