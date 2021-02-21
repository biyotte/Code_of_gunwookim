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
const long long mod = 11092019;
const long long hashmod = 100003;
const int MAXN = 20000;
const int MAXM = 4000000;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,co,a[1000005];
int dep[1000005],sz[1000005],tpos[1000005];
int p[1000005],par[1000005],up[1000005];
ll mx[4000005],cnt[4000005],lamx[4000005],lacnt[4000005];
ll ans_mx[1000005],ans_cnt[1000005];
vec v[1000005];

void dfs(int x) {
	sz[x] = 1;
	for(int &i : v[x]) {
		dep[i] = dep[x]+1;
		dfs(i);
		sz[x] += sz[i];
		if(sz[i] > sz[v[x][0]]) swap(i,v[x][0]);
	}
}

void dfs2(int x,int pr) {
	tpos[x] = ++co;
	up[x] = pr;
	for(int i : v[x]) {
		if(i == v[x][0]) dfs2(i,pr);
		else dfs2(i,i);
	}
}

void build(int x,int l,int r) {
	if(l == r) {
		mx[x] = cnt[x] = 1;
		return;
	}
	int mid = (l + r) >> 1;
	build(x*2,l,mid), build(x*2+1,mid+1,r);
	mx[x] = 1, cnt[x] = cnt[x*2]+cnt[x*2+1];
}

void push(int x,int l,int r) {
	if(lacnt[x]) {
		if(mx[x] < lamx[x]) {
			mx[x] = lamx[x];
			cnt[x] = lacnt[x];
		}
		else if(mx[x] == lamx[x]) {
			cnt[x] += lacnt[x];
			cnt[x] %= mod;
		}
		if(l^r) {
			if(lamx[x*2] < lamx[x]) {
				lamx[x*2] = lamx[x];
				lacnt[x*2] = lacnt[x];
			}
			else if(lamx[x*2] == lamx[x]) lacnt[x*2] += lacnt[x];
			if(lamx[x*2+1] < lamx[x]) {
				lamx[x*2+1] = lamx[x];
				lacnt[x*2+1] = lacnt[x];
			}
			else if(lamx[x*2+1] == lamx[x]) lacnt[x*2+1] += lacnt[x];
			lacnt[x*2] %= mod, lacnt[x*2+1] %= mod;
		}
		lamx[x] = lacnt[x] = 0;
	}
}

void update(int x,int l,int r,int rl,int rr,ll dp,ll sum) {
	push(x,l,r);
	if(rl > r||l > rr) return;
	if(rl <= l&&r <= rr) {
		lamx[x] = dp, lacnt[x] = sum;
		push(x,l,r); return;
	}
	int mid = (l + r) >> 1;
	update(x*2,l,mid,rl,rr,dp,sum), update(x*2+1,mid+1,r,rl,rr,dp,sum);
	mx[x] = max(mx[x*2],mx[x*2+1]);
	cnt[x] = cnt[x*2]*(mx[x] == mx[x*2])+cnt[x*2+1]*(mx[x] == mx[x*2+1]);
	cnt[x] %= mod;
}


void updateLCA(int x,ll dp,ll sum) {
	while(x) {
		update(1,1,n,tpos[up[x]],tpos[x],dp,sum);
		x = par[up[x]];
	}
}

bool cmp(int x,int y) {
	if(a[x] == a[y]) return dep[x] > dep[y];
	return a[x] > a[y];
}

int query(int x,int l,int r,int wi) {
	push(x,l,r);
	if(wi < l||r < wi) return 0;
	if(l == r) return x;
	int mid = (l + r) >> 1;
	return max(query(x*2,l,mid,wi),query(x*2+1,mid+1,r,wi));
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i], p[i] = i;
	for(int i = 2;i <= n;i++) {
		cin >> par[i];
		v[par[i]].pb(i);
	}
	dep[1] = 1, dfs(1), dfs2(1,1);
	sort(p+1,p+n+1,cmp);
	build(1,1,n);
	ll Ans_mx = 0,Ans_cnt = 0;
	for(int i = 1;i <= n;i++) {
		int now = p[i];
		int Q = query(1,1,n,tpos[now]);
		ll Mx = mx[Q],Cnt = cnt[Q];
		ans_mx[now] = Mx, ans_cnt[now] = Cnt;
		updateLCA(now,Mx+1,Cnt);
		Ans_mx = max(Ans_mx,ans_mx[now]);
	}
	for(int i = 1;i <= n;i++) if(ans_mx[i] == Ans_mx) Ans_cnt = (Ans_cnt+ans_cnt[i])%mod;
	cout << Ans_mx << ' ' << Ans_cnt << '\n';
}
