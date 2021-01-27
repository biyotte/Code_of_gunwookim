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
int n,Q,a[200005];

struct Tree {
	int l,r;
	int all,sum,L,R;
}t[800005];

Tree f(Tree tl,Tree tr) {
	Tree ret;
	ret.l = tl.l+(tl.sum == tl.all&&tl.R != tr.L ? tr.l : 0);
	ret.r = tr.r+(tr.sum == tr.all&&tl.R != tr.L ? tl.r : 0);
	ret.all = max(tl.all,tr.all);
	if(tl.R != tr.L) ret.all = max(ret.all,tl.r+tr.l);
	ret.sum = tl.sum+tr.sum;
	ret.L = tl.L, ret.R = tr.R;
	return ret;
}

void build(int x,int l,int r) {
	if(l == r) {
		t[x] = {1,1,1,1,1,1};
		return;
	}
	int mid = (l + r) >> 1;
	build(x*2,l,mid), build(x*2+1,mid+1,r);
	t[x] = f(t[x*2],t[x*2+1]);
}

void update(int x,int l,int r,int wi) {
	if(l > wi||wi > r) return;
	if(l == r) {
		a[wi] ^= 1;
		t[x] = {1,1,1,1,!a[wi],!a[wi]};
		return;
	}
	int mid = (l + r) >> 1;
	update(x*2,l,mid,wi), update(x*2+1,mid+1,r,wi);
	t[x] = f(t[x*2],t[x*2+1]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); 
	cin >> n >> Q;
	build(1,1,n);
	while(Q--) {
		int x; cin >> x;
		update(1,1,n,x); cout << t[1].all << '\n';
	}
}
