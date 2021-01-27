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
int n,m;
ll k,d;

struct Tree {
	ll lmax,rmax,amax,sum;
}t[800005];

Tree f(Tree L,Tree R) {
	Tree ret;
	ret.lmax = max(L.lmax,L.sum+R.lmax);
	ret.rmax = max(R.rmax,R.sum+L.rmax);
	ret.amax = max({L.amax,R.amax,L.rmax+R.lmax});
	ret.sum = L.sum+R.sum;
	return ret;
}

void build(int x,int l,int r) {
	if(l == r) {
		t[x] = {-k,-k,-k,-k};
		return;
	}
	int mid = (l + r) >> 1;
	build(x*2,l,mid), build(x*2+1,mid+1,r);
	t[x] = f(t[x*2],t[x*2+1]);
}

void update(int x,int l,int r,int wi,ll val) {
	if(wi < l||r < wi) return;
	if(l == r) {
		t[x].lmax += val;
		t[x].rmax += val;
		t[x].amax += val;
		t[x].sum += val;
		return;
	}
	int mid = (l + r) >> 1;
	update(x*2,l,mid,wi,val), update(x*2+1,mid+1,r,wi,val);
	t[x] = f(t[x*2],t[x*2+1]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> k >> d;
	build(1,1,n);
	while(m--) {
		int x,y; cin >> x >> y;
		update(1,1,n,x,y);
		if(t[1].amax > k*d) cout << "NIE\n";
		else cout << "TAK\n";
	}
}