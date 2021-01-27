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
const long long llINF = 1e18;
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
int n,m,B,k;

struct Square {
	int x1,y1,x2,y2;
}a[1005];


vecpi v1[1000005],v2[1000005];

struct Tree {
	int lmax,rmax,amax,sum,have;
}t[4000005];

Tree f(int have,Tree L,Tree R) {
	if(L.have) L.lmax = L.rmax = L.amax = 0;
	if(R.have) R.lmax = R.rmax = R.amax = 0;
	Tree ret;
	if(L.lmax == L.sum) ret.lmax = L.sum+R.lmax;
	else ret.lmax = L.lmax;
	if(R.rmax == R.sum) ret.rmax = R.sum+L.rmax;
	else ret.rmax = R.rmax;
	ret.amax = max({L.amax,R.amax,L.rmax+R.lmax});
	ret.sum = L.sum+R.sum;
	ret.have = have;
	return ret;
}

void build(int x,int l,int r) {
	if(l == r) {
		t[x] = {1,1,1,1,0};
		return;
	}
	int mid = (l + r) >> 1;
	build(x*2,l,mid), build(x*2+1,mid+1,r);
	t[x] = f(0,t[x*2],t[x*2+1]);
}

void update(int x,int l,int r,int rl,int rr,int val) {
	if(rl > r||l > rr) return;
	if(rl <= l&&r <= rr) {
		t[x].have += val;
		return;
	}
	int mid = (l + r) >> 1;
	update(x*2,l,mid,rl,rr,val), update(x*2+1,mid+1,r,rl,rr,val);
	t[x] = f(t[x].have,t[x*2],t[x*2+1]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> B >> k;
	for(int i = 1;i <= k;i++) {
		int C;
		cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2 >> C;
		v1[a[i].x1].pb({a[i].y1,a[i].y2});
		v2[a[i].x2+1].pb({a[i].y1,a[i].y2});
	}
	build(1,1,m);
	int ans = 0;
	for(int i = 1,j = 1;i <= n;i++) {
		for(pi x : v2[i]) update(1,1,m,x.x,x.y,-1);
		while(j <= n+1&&(t[1].have ? 0 : t[1].amax) >= j-i) {
			ans = max(ans,j-i);
			for(pi x : v1[j]) update(1,1,m,x.x,x.y,1);
			j++;
		}
	}
	cout << ans;
}