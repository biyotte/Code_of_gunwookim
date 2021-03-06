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
typedef pair <int,int> pl;
typedef pair <ll,ll> pi;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,C,Q,co,sp[200005][20];
int sz[200005],dep[200005],c[200005];
int up[200005],la[800005],tpos[200005];
int cnt[200005],ch[200005];
vec v[200005],t[800005];

struct Query {
	int x,len,co; // x 에서 len만큼 길다
}q[200005];

bool cmp(int x,int y) {return sz[x] > sz[y];}

void dfs(int x,int pr) {
	sz[x] = 1;
	for(int i : v[x]) {
		if(i == pr) continue;
		sp[i][0] = x, dep[i] = dep[x]+1;
		dfs(i,x);
		sz[x] += sz[i];
	}
}

void dfs2(int x,int pr) {
	up[x] = pr;
	tpos[x] = ++co;
	sort(all(v[x]),cmp);
	bool fl = false;
	for(int i : v[x]) {
		if(tpos[i]) continue;
		if(!fl) dfs2(i,pr), fl = 1;
		else dfs2(i,i);
	}
}

int LCA(int x,int y) {
	if(dep[x] < dep[y]) swap(x,y);
	for(int i = 17;i >= 0;i--) {
		if(dep[x] >= dep[y]+(1 << i)) x = sp[x][i];
	}
	if(x == y) return x;
	for(int i = 17;i >= 0;i--) {
		if(sp[x][i]^sp[y][i]) x = sp[x][i], y = sp[y][i];
	}
	return sp[x][0];
}

int Find(int x,int ti) {
	for(int i = 17;i >= 0;i--) {
		if(ti >= (1 << i)) x = sp[x][i], ti -= (1 << i);
	}
	return x;
}

vec er;

void push(int x,int l,int r) {
	if(la[x]) {
		t[x].clear();
		if(l^r) la[x*2] = la[x*2+1] = 1;
		la[x] = 0;
	}
}

void update(int x,int l,int r,int wi,int idx) {
	if(wi < l||r < wi) return;
	push(x,l,r);
	t[x].pb(idx);
	if(l == r) return;
	int mid = (l + r) >> 1;
	update(x*2,l,mid,wi,idx), update(x*2+1,mid+1,r,wi,idx);
}

void query(int x,int l,int r,int rl,int rr) {
	if(rl > r||l > rr) return;
	push(x,l,r);
	if(rl <= l&&r <= rr) {
		for(int i : t[x]) er.pb(i);
		la[x] = 1;
		return;
	}
	int mid = (l + r) >> 1;
	query(x*2,l,mid,rl,rr), query(x*2+1,mid+1,r,rl,rr);
}

void updateLCA(int x,int idx) {
	cnt[c[q[idx].co]]--;
	c[q[idx].co] += q[idx].len;
	cnt[c[q[idx].co]]++;
	while(x) {
		er.clear();
		query(1,1,n,tpos[up[x]],tpos[x]);
		for(int i : er) {
			int lca = LCA(q[i].x,q[idx].x);
			if(q[i].len <= dep[q[i].x]-dep[lca]) continue;
			cnt[c[q[i].co]]--;
			c[q[i].co] -= q[i].len;
			q[i].len = dep[q[i].x]-dep[lca];
			c[q[i].co] += q[i].len;
			cnt[c[q[i].co]]++;
			if(q[i].len) update(1,1,n,tpos[Find(q[i].x,q[i].len-1)],i);
		}
		
		x = sp[up[x]][0];
	}
	update(1,1,n,tpos[Find(q[idx].x,q[idx].len-1)],idx);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> C >> Q;
	cnt[0] = C;
	for(int i = 1;i < n;i++) {
		int x,y; cin >> x >> y;
		v[x].pb(y), v[y].pb(x);
	}
	dep[1] = 1, dfs(1,-1), dfs2(1,1);
	for(int i = 1;i < 18;i++) {
		for(int j = 1;j <= n;j++) sp[j][i] = sp[sp[j][i-1]][i-1];
	}
	for(int i = 1;i <= Q;i++) {
		int x,y,z; cin >> x >> y >> z;
		q[i] = {x,dep[x]-1,y};
		if(q[i].len) updateLCA(x,i);
		cout << cnt[z] << '\n';
	}
}