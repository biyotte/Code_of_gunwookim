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
int n,Q;
pi a[200005];

struct Tree {
	int l,r,v0,v1;
}t[800005];

Tree f(Tree L,Tree R) {
	Tree ret;
	ret.l = L.l, ret.r = R.r;
	if(L.v0 == -1||R.v0 == -1) ret.v0 = ret.v1 = -1;
	else {
		if(L.v0 <= a[R.l].x) ret.v0 = R.v0;
		else if(L.v0 <= a[R.l].y&&R.v1 != -1) ret.v0 = R.v1;
		else ret.v0 = -1;

		if(L.v1 == -1) ret.v1 = -1;
		else if(L.v1 <= a[R.l].x) ret.v1 = R.v0;
		else if(L.v1 <= a[R.l].y&&R.v1 != -1) ret.v1 = R.v1;
		else ret.v1 = -1;
	}
	return ret;
}

void build(int x,int l,int r) {
	if(l == r) {
		t[x] = {l,r,a[l].x,a[l].y};
		return;
	}
	int mid = (l + r) >> 1;
	build(x*2,l,mid), build(x*2+1,mid+1,r);
	t[x] = f(t[x*2],t[x*2+1]);
}

void update(int x,int l,int r,int wi) {
	if(wi < l||r < wi) return;
	if(l == r) {
		t[x] = {l,r,a[l].x,a[l].y};
		return;
	}
	int mid = (l + r) >> 1;
	update(x*2,l,mid,wi), update(x*2+1,mid+1,r,wi);
	t[x] = f(t[x*2],t[x*2+1]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) {
		cin >> a[i].x >> a[i].y;
		if(a[i].x > a[i].y) swap(a[i].x,a[i].y);
	}
	build(1,1,n);
	cin >> Q;
	while(Q--) {
		int x,y; cin >> x >> y;
		swap(a[x],a[y]);
		update(1,1,n,x), update(1,1,n,y);
		if(t[1].v0 != -1) cout << "TAK\n";
		else cout << "NIE\n";
	}
}