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
int n,g,sz[200005],id;
int L[400005],R[400005],val[400005];
int lc[400005],rc[400005];
int t[20][200001];
vec a[20];
ll ans[20];
queue <int> q;

void update(int wi,int x,int val) {
	for(;x <= n;x += x&-x) t[wi][x] += val;
}

int query(int wi,int l,int r) {
	int ret = 0;
	for(r;r;r -= r&-r) ret += t[wi][r];
	for(l--;l;l -= l&-l) ret -= t[wi][l];
	return ret;
}

int merge(int x,int y) {
	if(a[x].size() < a[y].size()) swap(x,y);
	ll ansx = 0,ansy = 0;
	for(int i : a[y]) {
		ansx += query(x,1,i-1);
		ansy += query(x,i+1,n);
	}
	ans[x] += ans[y]+min(ansx,ansy);
	ans[y] = 0;
	for(int i : a[y]) a[x].pb(i), update(y,i,-1), update(x,i,1);
	a[y].clear(), q.push(y);
	return x;
}

int dfs(int ix) {
	int x = 0;
	if(L[ix] == R[ix]) x = val[ix];
	if(x) {
		int idx = q.front(); q.pop();
		update(idx,x,1);
		a[idx].pb(x);
		return idx;
	}
	else {
		int Lidx;
		int Ridx;
		if(R[lc[ix]]-L[lc[ix]] > R[rc[ix]]-L[rc[ix]]) {
			Lidx = dfs(lc[ix]);
			Ridx = dfs(rc[ix]);
		}
		else {
			Ridx = dfs(rc[ix]);
			Lidx = dfs(lc[ix]);
		}
		return merge(Lidx,Ridx);
	}
}

int dfs2() {
	int x; cin >> x;
	if(x) {
		g++;
		L[g] = R[g] = g;
		val[g] = x;
		return g;
	}
	else {
		int Lidx = dfs2();
		int idx = ++g;
		L[idx] = L[Lidx];
		int Ridx = dfs2();
		R[idx] = R[Ridx];
		lc[idx] = Lidx, rc[idx] = Ridx;
		return idx;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i <= 19;i++) q.push(i);
	cout << ans[dfs(dfs2())];
}