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
const long long llINF = 1e18+10;
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
int n,m,nam[100005];
int p[1005],sz[1005];
int chl[1000005],chr[1000005];
int ch[1000005];
vec t[400025];
vector <ll> s[400025];

struct Edge {
	int x,y;
	int val;
};
vector <Edge> v;

bool cmp(Edge x,Edge y) {
	return x.val < y.val;
}

int Find(int x) {return (x^p[x] ? p[x] = Find(p[x]) : x);}

int merge(int x,int y) {
	x = Find(x), y = Find(y);
	if(x^y) {
		if(sz[x] < sz[y]) swap(x,y);
		p[y] = x;
		sz[x] += sz[y];
		return 1;
	}
	return 0;
}

void build(int x,int l,int r) {
	t[x].clear(), s[x].clear();
	if(l == r) return;
	int mid = (l + r) >> 1;
	build(x*2,l,mid), build(x*2+1,mid+1,r);
}

void update(int x,int l,int r,int wi,int val) {
	if(wi < l||r < wi) return;
	t[x].pb(val);
	s[x].pb((ll)(s[x].empty() ? 0LL : s[x].back())+ch[val]);
	if(l == r) return;
	int mid = (l + r) >> 1;
	update(x*2,l,mid,wi,val), update(x*2+1,mid+1,r,wi,val);
}

int query(int x,int l,int r,int rl,int rr) {
	if(rl < l) return 0;
	if(r <= rl) {
		int lit = lower_bound(all(t[x]),rl)-t[x].begin();
		int rit = upper_bound(all(t[x]),rr)-t[x].begin()-1;
		if(lit > rit) return 0;
		return s[x][rit]-(lit ? s[x][lit-1] : 0);
	}
	int mid = (l + r) >> 1;
	return query(x*2,l,mid,rl,rr)+query(x*2+1,mid+1,r,rl,rr);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while(T--) {
		cin >> n >> m;
		vec rv;
		v.clear();
		for(int i = 1;i <= m;i++) {
			int x,y,z; cin >> x >> y >> z;
			rv.pb(z);
			v.pb({x,y,z});
		}
		sort(all(rv)), rv.erase(unique(all(rv)),rv.end());
		memset(chl,0,sizeof(chl)), memset(chr,0,sizeof(chr));
		for(int i = 0;i < rv.size();i++) {
			chl[rv[i]] = chr[rv[i]] = i+1;
			ch[i+1] = rv[i];
		}
		chl[MAXM+1] = MAXM+1;
		for(int i = MAXM;i >= 1;i--) {
			if(!chl[i]) chl[i] = chl[i+1];
		}
		for(int i = 1;i <= MAXM;i++) {
			if(!chr[i]) chr[i] = chr[i-1];
		}
		for(int i = 0;i < v.size();i++) {
			v[i].val = chl[v[i].val];
		}
		sort(all(v),cmp);
		vecpi tmp, la, la2;
		for(int i = chr[MAXM], g = (int)v.size()-1;i >= 1;i--) {
			tmp.clear(), la2.clear();
			while(g >= 0&&v[g].val >= i) {
				tmp.pb({v[g].val,g});
				g--;
			}
			reverse(all(tmp));
			for(int j = 1;j <= n;j++) p[j] = j, sz[j] = 1;
			for(pi j : tmp) {
				if(merge(v[j.y].x,v[j.y].y)) la2.pb(j);
				else nam[j.y] = i+1;
			}
			for(pi j : la) {
				if(merge(v[j.y].x,v[j.y].y)) la2.pb(j);
				else nam[j.y] = i+1;
			}
			la = la2;
		}
		for(pi j : la) nam[j.y] = 1;
		build(1,1,chr[MAXM]);
		for(int i = 0;i < m;i++) {
			update(1,1,chr[MAXM],nam[i],v[i].val);
		}
		int Q,ans = 0; cin >> Q;
		while(Q--) {
			int x,y; cin >> x >> y;
			x -= ans, y -= ans;
			x = chl[x], y = chr[y];
			if(x > y) ans = 0, cout << "0\n";
			else cout << (ans = query(1,1,chr[MAXM],x,y)) << '\n';
		}
	}
}
