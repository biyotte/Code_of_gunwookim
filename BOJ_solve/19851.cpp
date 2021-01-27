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
int n;
int Q;
char a[1000005];

struct Tree {
	int lmin,rmin,lmax,rmax,sum,la;
}t[4000005];

Tree merge(int la,Tree L,Tree R) {
	Tree ret;
	ret.lmin = min(L.lmin,L.sum+R.lmin);
	ret.rmin = min(R.rmin,R.sum+L.rmin);
	ret.lmax = max(L.lmax,L.sum+R.lmax);
	ret.rmax = max(R.rmax,R.sum+L.rmax);
	ret.sum = L.sum+R.sum;
	ret.la = la;
	return ret;
}

void push(int x,int l,int r) {
	if(t[x].la) {
		if(l^r) t[x*2].la ^= 1, t[x*2+1].la ^= 1;
		swap(t[x].lmax,t[x].lmin), swap(t[x].rmax,t[x].rmin);
		t[x].lmax *= -1, t[x].lmin *= -1, t[x].rmax *= -1, t[x].rmin *= -1;
		t[x].sum = -t[x].sum;
		t[x].la = 0;
	}
}

void build(int x,int l,int r) {
	if(l == r) {
		if(a[l] == '(') t[x] = {1,1,1,1,1,0};
		else t[x] = {-1,-1,-1,-1,-1,0};
		return;
	}
	int mid = (l + r) >> 1;
	build(x*2,l,mid), build(x*2+1,mid+1,r);
	t[x] = merge(t[x].la,t[x*2],t[x*2+1]);
}

void update(int x,int l,int r,int rl,int rr) {
	push(x,l,r);
	if(rl > r||l > rr) return;
	if(rl <= l&&r <= rr) {
		t[x].la = 1, push(x,l,r);
		return;
	}
	int mid = (l + r) >> 1;
	update(x*2,l,mid,rl,rr), update(x*2+1,mid+1,r,rl,rr);
	t[x] = merge(t[x].la,t[x*2],t[x*2+1]);
}

Tree query(int x,int l,int r,int rl,int rr) {
	push(x,l,r);
	if(rl > r||l > rr) return {0,0,0,0,0,0};
	if(rl <= l&&r <= rr) return t[x];
	int mid = (l + r) >> 1;
	return merge(0,query(x*2,l,mid,rl,rr),query(x*2+1,mid+1,r,rl,rr));
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> a+1;
	build(1,1,n);
	cin >> Q;
	while(Q--) {
		int op,l,r;
		cin >> op >> l >> r;
		if(op & 1) update(1,1,n,l,r);
		else {
			Tree ret = query(1,1,n,l,r);
			cout << r-l+1-min(0,ret.lmin)+max(0,ret.rmax) << '\n';
		}
	}
}
