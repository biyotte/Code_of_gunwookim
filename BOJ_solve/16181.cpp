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
int n,C,Q,co,sp[100005][20];
int sz[100005],dep[100005];
int up[100005],la[400005],tpos[100005];
int cnt[100005];
vec v[100005],t[400005];

struct Query {
	int x,len; // x 에서 len만큼 길다
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
	for(int i = 19;i >= 0;i--) {
		if(dep[x] >= dep[y]+(1 << i)) x = sp[x][i];
	}
	if(x == y) return x;
	for(int i = 19;i >= 0;i--) {
		if(sp[x][i]^sp[y][i]) x = sp[x][i], y = sp[y][i];
	}
	return sp[x][0];
}

int Find(int x,int ti) {
	for(int i = 19;i >= 0;i--) {
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
	push(x,l,r);
	if(wi < l||r < wi) return;
	t[x].pb(idx);
	if(l == r) return;
	int mid = (l + r) >> 1;
	update(x*2,l,mid,wi,idx), update(x*2+1,mid+1,r,wi,idx);
}

void query(int x,int l,int r,int rl,int rr) {
	push(x,l,r);
	if(rl > r||l > rr) return;
	if(rl <= l&&r <= rr) {
		for(int i : t[x]) er.pb(i);
		la[x] = 1; push(x,l,r);
		return;
	}
	int mid = (l + r) >> 1;
	query(x*2,l,mid,rl,rr), query(x*2+1,mid+1,r,rl,rr);
}

void updateLCA(int x,int idx) {
	while(up[x]) {
		er.clear();
		query(1,1,n,tpos[up[x]],tpos[x]);
		for(int i : er) {
			int lca = LCA(q[i].x,q[idx].x);
			cnt[q[i].len]--;
			q[i].len = dep[q[i].x]-lca;
			cnt[q[i].len]++;
			if(q[i].len) update(1,1,n,Find(q[i].x,q[i].len-1),i);
		}
	}
	cnt[0]--, cnt[q[idx].len]++;
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
	for(int i = 1;i < 20;i++) {
		for(int j = 1;j <= n;j++) sp[j][i] = sp[sp[j][i-1]][i-1];
	}
	for(int i = 1;i <= Q;i++) {
		int x,y,z; cin >> x >> y >> z;
		if(dep[x] > dep[y]) swap(x,y);
		q[i] = {x,dep[x]-1};
		updateLCA(x,i);
		cout << cnt[z] << '\n';
	}
}