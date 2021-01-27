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
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,m,H;
int used[100005];
int t[1200005],lz[1200005];
vec rev,hi;

struct Tree {
	int lmax,rmax,sum;
	int dl,dr;
}t2[1200005];

struct Ultari {
	int h,l,r,idx;
}a[100005];
vector <Ultari> g[100005];

bool cmp(Ultari x,Ultari y) {
	if(x.l == y.l) return x.r > y.r;
	return x.l < y.l;
}

Tree f(Tree L,Tree R) {
	Tree ret;
	ret.lmax = L.lmax+(L.sum == L.dr-L.dl+1)*R.lmax;
	ret.rmax = R.rmax+(R.sum == R.dr-R.dl+1)*L.rmax;
	ret.sum = L.sum+R.sum;
	ret.dl = L.dl, ret.dr = R.dr;
	return ret;
}

void Gpush(int x,int l,int r) {
	if(lz[x]) {
		t2[x] = {r-l+1,r-l+1,r-l+1,t2[x].dl,t2[x].dr};
		if(l^r) lz[x*2] = lz[x*2+1] = 1;
		lz[x] = 0;
	}
}

void build(int x,int l,int r) {
	t2[x] = {0,0,0,l,r};
	if(l == r) return;
	int mid = (l + r) >> 1;
	build(x*2,l,mid), build(x*2+1,mid+1,r);
}

void Gupdate(int x,int l,int r,int rl,int rr) {
	Gpush(x,l,r);
	if(rl > r||l > rr) return;
	if(rl <= l&&r <= rr) {
		lz[x] = 1, Gpush(x,l,r);
		return;
	}
	int mid = (l + r) >> 1;
	Gupdate(x*2,l,mid,rl,rr), Gupdate(x*2+1,mid+1,r,rl,rr);
	t2[x] = f(t2[x*2],t2[x*2+1]);
}

Tree Gquery(int x,int l,int r,int rl,int rr) {
	Gpush(x,l,r);
	if(rl > r||l > rr) return {r-l+1,r-l+1,r-l+1,l,r};
	if(rl <= l&&r <= rr) return t2[x];
	int mid = (l + r) >> 1;
	return f(Gquery(x*2,l,mid,rl,rr),Gquery(x*2+1,mid+1,r,rl,rr));
}

void push(int x,int l,int r) {
	if(t[x]) {
		if(l^r) t[x*2] = t[x*2+1] = 1;
	}
}

void update(int x,int l,int r,int rl,int rr) {
	push(x,l,r);
	if(rl > r||l > rr) return;
	if(rl <= l&&r <= rr) {
		t[x] = 1, push(x,l,r);
		return;
	}
	int mid = (l + r) >> 1;
	update(x*2,l,mid,rl,rr), update(x*2+1,mid+1,r,rl,rr);
	t[x] = t[x*2]&t[x*2+1];
}

int query(int x,int l,int r,int rl,int rr) {
	push(x,l,r);
	if(rl > r||l > rr) return 1;
	if(rl <= l&&r <= rr) return t[x];
	int mid = (l + r) >> 1;
	return query(x*2,l,mid,rl,rr)&query(x*2+1,mid+1,r,rl,rr);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); 
	cin >> n;
	for(int i = 1;i <= n;i++) {
		int x; cin >> a[i].l >> x >> a[i].h;
		a[i].r = a[i].l+x-1;

		a[i].idx = i;
		rev.pb(a[i].l), rev.pb(a[i].r);
		rev.pb(a[i].l-1), rev.pb(a[i].l+1);
		rev.pb(a[i].r-1), rev.pb(a[i].r+1);
		hi.pb(a[i].h);
	}
	sort(all(rev)), rev.erase(unique(all(rev)),rev.end());
	sort(all(hi)), hi.erase(unique(all(hi)),hi.end());
	m = rev.size(), H = hi.size();
	for(int i = 1;i <= n;i++) {
		a[i].l = lower_bound(all(rev),a[i].l)-rev.begin()+1;
		a[i].r = lower_bound(all(rev),a[i].r)-rev.begin()+1;
		a[i].h = lower_bound(all(hi),a[i].h)-hi.begin()+1;
		g[a[i].h].pb(a[i]);
	}
	build(1,1,m);
	for(int co = H;co >= 1;co--) {
		vector <Ultari> tmp;
		for(Ultari &i : g[co]) {
			auto ret = Gquery(1,1,m,i.l,i.r);
			if(ret.lmax+1 <= m-ret.rmax) tmp.pb({i.h,ret.lmax+1,m-ret.rmax,i.idx});
		}
		g[co] = tmp;
		sort(all(g[co]),cmp);
		int la = g[co][0].r,pv = 1;
		used[g[co][0].idx] = !query(1,1,m,g[co][0].l,g[co][0].r);
		update(1,1,m,g[co][0].l,g[co][0].r);
		Gupdate(1,1,m,g[co][0].l,g[co][0].r);
		
		while(pv < (int)g[co].size()) {
			int mx = -1,idx = -1;
			while(pv < (int)g[co].size()&&g[co][pv].l <= la+1) {
				if(mx < g[co][pv].r) {
					mx = g[co][pv].r;
					idx = pv;
				}
				pv++;
			}
			if(la < mx) {
				used[g[co][idx].idx] = !query(1,1,m,g[co][idx].l,g[co][idx].r);
				update(1,1,m,g[co][idx].l,g[co][idx].r);
				Gupdate(1,1,m,g[co][idx].l,g[co][idx].r);
				la = mx;
			}
			else {
				if(pv == (int)g[co].size()) continue;
				used[g[co][pv].idx] = !query(1,1,m,g[co][pv].l,g[co][pv].r);
				update(1,1,m,g[co][pv].l,g[co][pv].r);
				Gupdate(1,1,m,g[co][pv].l,g[co][pv].r);
				la = g[co][pv].r;
				pv++;
			}
		}
	}
	vec ans;
	for(int i = 1;i <= n;i++) {
		if(used[i]) ans.pb(i);
	}
	cout << ans.size() << '\n';
	for(int i : ans) cout << i << ' ';
}