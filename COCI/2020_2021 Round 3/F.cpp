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
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,Q;
int a[300005];
int t[1200005];

void build(int x,int l,int r) {
	if(l == r) {
		t[x] = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(x*2,l,mid), build(x*2+1,mid+1,r);
	t[x] = t[x*2]^t[x*2+1];
}

void update(int x,int l,int r,int wi,int val) {
	if(wi < l||r < wi) return;
	if(l == r) {
		t[x] ^= val;
		return;
	}
	int mid = (l + r) >> 1;
	update(x*2,l,mid,wi,val), update(x*2+1,mid+1,r,wi,val);
	t[x] = t[x*2]^t[x*2+1];
}

int query(int x,int l,int r,int rl,int rr) {
	if(rl > r||l > rr) return 0;
	if(rl <= l&&r <= rr) return t[x];
	int mid = (l + r) >> 1;
	return query(x*2,l,mid,rl,rr)^query(x*2+1,mid+1,r,rl,rr);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); 
	cin >> n >> Q;
	for(int i = 1;i <= n;i++) cin >> a[i];
	build(1,1,n);
	while(Q--) {
		int op,x,y;
		cin >> op >> x >> y;
		if(op & 1) update(1,1,n,x,y);
		else cout << query(1,1,n,x,y) << '\n';
	}
}