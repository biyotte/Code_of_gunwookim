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
const long long llINF = 5e18;
const long long mod = 1e9+7;
const long long hmod1 = 1e9+409;
const long long hmod2 = 1e9+433;
const long long base = 257;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n;
int a[300005];
int cnt[4000005];
ll ans;
vecpi rev;

struct Tree {
	int lmax,rmax,lmin,rmin,sum;
}t[1200005];

void updateCnt(int x,int l,int r,int wi) {
	if(wi < l||r < wi) return;
	if(l == r) {
		cnt[x]++;
		return;
	}
	int mid = (l + r) >> 1;
	updateCnt(x*2,l,mid,wi), updateCnt(x*2+1,mid+1,r,wi);
	cnt[x] = cnt[x*2]+cnt[x*2+1];
}

int queryCnt(int x,int l,int r,int rl,int rr) {
	if(rl <= l&&r <= rr) return cnt[x];
	if(rl > r||l > rr) return 0;
	int mid = (l + r) >> 1;
	return queryCnt(x*2,l,mid,rl,rr)+queryCnt(x*2+1,mid+1,r,rl,rr);
}

Tree f(Tree L,Tree R) {
	Tree ret;
	ret.lmax = max(L.lmax,L.sum+R.lmax);
	ret.rmax = max(R.rmax,R.sum+L.rmax);
	ret.lmin = min(L.lmin,L.sum+R.lmin);
	ret.rmin = min(R.rmin,R.sum+L.rmin);
	ret.sum = L.sum+R.sum;
	return ret;
}

void build(int x,int l,int r) {
	if(l == r) {
		t[x] = {-1,-1,-1,-1,-1};
		return;
	}
	int mid = (l + r) >> 1;
	build(x*2,l,mid), build(x*2+1,mid+1,r);
	t[x] = f(t[x*2],t[x*2+1]);
}

void update(int x,int l,int r,int wi) {
	if(wi < l||r < wi) return;
	if(l == r) {
		t[x].lmax++, t[x].rmax++, t[x].lmin++, t[x].rmin++, t[x].sum++;
		return;
	}
	int mid = (l + r) >> 1;
	update(x*2,l,mid,wi), update(x*2+1,mid+1,r,wi);
	t[x] = f(t[x*2],t[x*2+1]);
}

Tree query(int x,int l,int r,int rl,int rr) {
	if(rl > r||l > rr||rl > rr) return {0,0,0,0,0};
	if(rl <= l&&r <= rr) return t[x];
	int mid = (l + r) >> 1;
	return f(query(x*2,l,mid,rl,rr),query(x*2+1,mid+1,r,rl,rr));
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) {
		int x; cin >> x; a[i] = x;
		if(x^1000000) ans += queryCnt(1,1,1000000,x+1,1000000);
		updateCnt(1,1,1000000,x);
		rev.pb({a[i],i});
	}
	sort(all(rev)), rev.erase(unique(all(rev)),rev.end());
	build(1,1,n);
	for(int i = 1;i <= n;i++) {
		a[i] = lower_bound(all(rev),make_pair(a[i],i))-rev.begin()+1;
		update(1,1,n,a[i]);
		Tree L = query(1,1,n,1,a[i]), R = query(1,1,n,a[i],n);
		cout << ans-max(-L.rmin,R.lmax) << ' ';
		update(1,1,n,a[i]);
	}
}
