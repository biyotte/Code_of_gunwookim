#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define all(v) v.begin(),v.end()
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
using namespace std;
const long long INF = 1e9;
const int TMX = 1 << 18;
const long long llINF = 1e18;
const long long mod = 1e9+7;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long lon
int n,Q,fl,ind[1000005];
int ans,mx,c[1000005],c2[1000005];
int cnt[1000005],par[1000005];
int p[1000005];
vec v[1000005];

int Find(int x) {return (x^p[x] ? p[x] = Find(p[x]) : x);}

// not solved

void Ind3(int x) {
	mx++;
	ans = 0;
	if(++cnt[x] == mx) ans++;
	for(int i : v[x]) {
		if(++cnt[i] == mx) ans++;
	}g ll;
}

void Ind4(int x) {
	mx++;
	ans = 0;
	if(++cnt[x] == mx) ans++;
}

bool merge(int x,int y) {
	x = Find(x), y = Find(y);
	if(x == y) return false;
	p[y] = x; return true;
}

vec g;
bool canCycle;

void Cycle(int x,int pr) {
	if(c2[x]) {
		canCycle = 1;
		if(++cnt[x] == mx) ans++;
		for(int i = par[x];i^x;i = par[i]) {
			if(++cnt[i] == mx) ans++;
		}
		return;
	}
	if(c[x]) {g.pb(x); return;}
	c[x] = c2[x] = 1;
	g.pb(x);
	for(int i : v[x]) if(i != pr) par[x] = i, Cycle(i,x);
	c2[x] = 0;
}

void update(int x,int y) {
	v[x].pb(y), v[y].pb(x);
	ind[x]++, ind[y]++;
	if(ind[x] == 3) Ind3(x);
	if(ind[y] == 3) Ind3(y);
	if(ind[x] == 4) Ind4(x);
	if(ind[y] == 4) Ind4(y);
	if(!merge(x,y)) {
		g.clear();
		canCycle = 0;
		if(c[x]) swap(x,y);
		mx++; ans = 0;
		Cycle(x,-1);
		if(!canCycle) {
			//if(g.size() > 2) exit(-1);
			//if(g.size() < 2) return;
			for(int i : g) if(++cnt[i] == mx) ans++;
			
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> Q;
	ans = n;
	for(int i = 1;i <= n;i++) p[i] = i;
	while(Q--) {
		int x,y; cin >> x;
		if(x == -1) cout << ans << '\n';
		else cin >> y, update(x+1,y+1);
	}
}
