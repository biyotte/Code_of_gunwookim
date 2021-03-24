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
const long long llINF = 1e16;
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
int n,d[200005],p[200005];
vec vx;

// not solved

struct Array {
	int x,y,idx;
}a[200005];

bool cmp(Array x,Array y) {
	return x.x < y.x;
}

struct Tree {
	int mx,idx,widx;
}t[800005];

Tree f(Tree L,Tree R) {
	if(L.mx > R.mx) return L;
	if(L.mx < R.mx) return R;
	if(L.idx < R.idx) return L;
	return R;
}

void update(int x,int l,int r,int wi) {
	if(wi < l||r < wi) return;
	if(l == r) {
		t[x] = {d[wi],a[wi].idx,wi};
		return;
	}
	int mid = (l + r) >> 1;
	update(x*2,l,mid,wi), update(x*2+1,mid+1,r,wi);
	t[x] = f(t[x*2],t[x*2+1]);
}

Tree query(int x,int l,int r,int rl,int rr) {
	if(rl > rr) return {0,0,0};
	if(rl > r||l > rr) return {0,0,0};
	if(rl <= l&&r <= rr) return t[x];
	int mid = (l + r) >> 1;
	return f(query(x*2,l,mid,rl,rr),query(x*2+1,mid+1,r,rl,rr));
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) {
		cin >> a[i].x >> a[i].y;
		a[i].idx = i;
	}
	sort(a+1,a+n+1,cmp);
	for(int i = 1;i <= n;i++) vx.pb(a[i].x);
	int wi = n;
	for(int i = n;i >= 1;i--) {
		int it = upper_bound(all(vx),a[i].y)-vx.begin()+1;
		Tree ret = query(1,1,n,it,n);
		p[i] = ret.widx;
		d[i] = ret.mx+1;
		if(d[wi] < d[i]) 
	}
}