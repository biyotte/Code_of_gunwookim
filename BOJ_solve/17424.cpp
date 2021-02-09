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
typedef long long ll;
int n,Q;
int a[100005][2];

struct Tree {
	ll b[4][4];
	bool isl;
}t[400005];

Tree f(Tree L,Tree R) {
	Tree ret;
	ret.isl = 0;
	for(int i = 0;i < 4;i++) {
		for(int j = 0;j < 4;j++) {
			ll &ans = ret.b[i][j]; ans = 0;
			for(int k = 0;k < 4;k++) {
				if((L.isl&&(i&k) != k)||(R.isl&&(j&k) != k)) continue;
				ans = (ans+L.b[(L.isl ? i-k : i)][(L.isl ? i-k : 3-k)]*R.b[(R.isl ? j-k : 3-k)][(R.isl ? j-k : j)])%mod;
			}
		}
	}
	return ret;
}

void build(int x,int l,int r) {
	if(l == r) {
		t[x].b[0][0] = t[x].b[3][3] = 1;
		t[x].isl = 1;
		return;
	}
	int mid = (l + r) >> 1;
	build(x*2,l,mid), build(x*2+1,mid+1,r);
	t[x] = f(t[x*2],t[x*2+1]);
}

void update(int x,int l,int r,int wi,int y) {
	if(wi < l||r < wi) return;
	if(l == r) {
		a[l][y] ^= 1;
		t[x].b[0][0] = t[x].b[1][1] = t[x].b[2][2] = t[x].b[3][3] = 0;
		if(a[l][0]&&a[l][1]) t[x].b[3][3] = 1;
		else if(!a[l][0]&&!a[l][1]) t[x].b[0][0] = t[x].b[3][3] = 1;
		else if(!a[l][0]&&a[l][1]) t[x].b[1][1] = 1;
		else t[x].b[2][2] = 1;
		return;
	}
	int mid = (l + r) >> 1;
	update(x*2,l,mid,wi,y), update(x*2+1,mid+1,r,wi,y);
	t[x] = f(t[x*2],t[x*2+1]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> Q;
	build(1,1,n);
	while(Q--) {
		int op,x,y; cin >> op >> y >> x;
		update(1,1,n,x,y-1);
		cout << t[1].b[3][3] << '\n';
	}
}
