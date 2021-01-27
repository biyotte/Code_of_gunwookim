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
const long long mod = 998244353;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,Q;
int la[2000005];

struct Tree {
	int lmax,rmax,sum,amax,dl,dr;
}t[2000005];

Tree f(Tree L,Tree R) {
	Tree ret;
	ret.lmax = L.lmax;
	if(L.lmax == L.dr-L.dl+1) ret.lmax += R.lmax;
	ret.rmax = R.rmax;
	if(R.rmax == R.dr-R.dl+1) ret.rmax += L.rmax;
	ret.sum = L.sum+R.sum;
	ret.amax = max({L.amax,R.amax,L.rmax+R.lmax});
	ret.dl = L.dl, ret.dr = R.dr;
	return ret;
}

void build(int x,int l,int r) {
	if(l == r) {
		t[x] = {1,1,1,1,l,l};
		return;
	}
	int mid = (l + r) >> 1;
	build(x*2,l,mid), build(x*2+1,mid+1,r);
	t[x] = f(t[x*2],t[x*2+1]);
}

void push(int x,int l,int r) {
	if(la[x]) {
		if(la[x] == -1) t[x] = {r-l+1,r-l+1,r-l+1,r-l+1,l,r};
		else t[x] = {0,0,0,0,l,r};
		if(l^r) la[x*2] = la[x*2+1] = la[x];
		la[x] = 0;
	}
}

void update(int x,int l,int r,int rl,int rr,int val) {
	push(x,l,r);
	if(rl > r||l > rr) return;
	if(rl <= l&&r <= rr) {
		la[x] = val, push(x,l,r);
		return;
	}
	int mid = (l + r) >> 1;
	update(x*2,l,mid,rl,rr,val), update(x*2+1,mid+1,r,rl,rr,val);
	t[x] = f(t[x*2],t[x*2+1]);
}

int query(int x,int l,int r,int k) {
	if(l == r) return l;
	int mid = (l + r) >> 1;
	push(x,l,r), push(x*2,l,mid), push(x*2+1,mid+1,r);
	if(t[x*2].amax >= k) return query(x*2,l,mid,k);
	if(t[x*2].rmax&&t[x*2].rmax+t[x*2+1].lmax >= k) return t[x*2].dr-t[x*2].rmax+1;
	if(t[x*2+1].amax >= k) return query(x*2+1,mid+1,r,k);
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); 
	cin >> n >> Q;
	build(1,1,n);
	int ans = 0;
	while(Q--) {
		char op;
		int x,y;
		cin >> op >> x;
		if(op == 'L') {
			cin >> y;
			update(1,1,n,x,y,-1);
		}
		else {
			int tmp = query(1,1,n,x);
			if(!tmp) {ans++; continue;}
			update(1,1,n,tmp,tmp+x-1,1);
		}
	}
	cout << ans;
}