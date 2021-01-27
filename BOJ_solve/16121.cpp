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
const long long mod = 998244353;
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
int n,m,k,p[300005],ism[300005];
int sz[300005],isk[300005];
int c[300005],dep[300005];
vec v[300005],rv[300005];
ll ans;

struct Struct {
	ll cntm,depm,depm2;
	ll cntk,depk,depk2;
};

int dfs_centroid(int x,int pr,int cap) {
	for(int i : v[x]) {
		if(i == pr||c[i]||sz[i] <= cap) continue;
		return dfs_centroid(i,x,cap);
	}
	return x;
}

void getsz(int x,int pr) {
	sz[x] = 1;
	for(int i : v[x]) {
		if(i == pr||c[i]) continue;
		getsz(i,x), sz[x] += sz[i];
	}
}

int make_centroid(int x) {
	getsz(x,-1);
	int cent = dfs_centroid(x,-1,sz[x]/2);
	c[cent] = 1;
	for(int i : v[cent]) {
		if(c[i]) continue;
		int nxcent = make_centroid(i);
		p[nxcent] = cent;
		rv[cent].pb(nxcent);
	}
	return cent;
}

Struct dfs(int x,int pr,int depth) {
	dep[x] = depth;
	ll isM = dep[x]*ism[x], isK = dep[x]*isk[x];
	Struct ret = {ism[x],isM,isM*isM%mod,isk[x],isK,isK*isK%mod};
	for(int i : v[x]) {
		if(i == pr||c[i]) continue;
		Struct tmp = dfs(i,x,depth+1);
		ret.cntm += tmp.cntm, ret.cntk += tmp.cntk;
		ret.depm += tmp.depm, ret.depk += tmp.depk;
		ret.depm2 += tmp.depm2, ret.depk2 += tmp.depk2;
		ret.depm %= mod, ret.depk %= mod;
		ret.depm2 %= mod, ret.depk2 %= mod;
	}
	return ret;
}

void getAns(int x) {
	c[x] = 1;
	Struct ret = {ism[x],0,0,isk[x],0,0};
	for(int i : v[x]) {
		if(c[i]) continue;
		Struct tmp = dfs(i,x,1);
		ans = (ans+ret.cntk*tmp.depm2%mod+ret.cntm*tmp.depk2)%mod;
		ans = (ans+ret.depm2*tmp.cntk%mod+ret.depk2*tmp.cntm)%mod;
		ans = (ans+2*ret.depk*tmp.depm%mod+2*ret.depm*tmp.depk%mod)%mod;
		ret.cntm += tmp.cntm, ret.cntk += tmp.cntk;
		ret.depm += tmp.depm, ret.depk += tmp.depk;
		ret.depm2 += tmp.depm2, ret.depk2 += tmp.depk2;
	}
	for(int i : rv[x]) {
		if(c[i]) continue;
		getAns(i);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i < n;i++) {
		int x,y; cin >> x >> y;
		v[x].pb(y), v[y].pb(x);
	}
	cin >> m;
	for(int i = 1;i <= m;i++) {
		int x; cin >> x; ism[x] = 1;
	}
	cin >> k;
	for(int i = 1;i <= k;i++) {
		int x; cin >> x; isk[x] = 1;
	}
	int stcent = make_centroid(1);
	memset(c,0,sizeof(c));
	getAns(stcent);
	cout << ans;
}