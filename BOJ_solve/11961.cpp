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
int n,m,c[100005];
int a[50005],b[50005];
int sl[50005],sr[50005];

struct Tree {
	int lmax,rmax,sum;
}t[400005];

Tree f(Tree L,Tree R) {
	Tree ret;
	ret.lmax = max(L.lmax,L.sum+R.lmax);
	ret.rmax = max(R.rmax,R.sum+L.rmax);
	ret.sum = L.sum+R.sum;
	return ret;
}

void update(int x,int l,int r,int wi,int val) {
	if(wi < l||r < wi) return;
	if(l == r) {
		t[x] = {val,val,val};
		return;
	}
	int mid = (l + r) >> 1;
	update(x*2,l,mid,wi,val), update(x*2+1,mid+1,r,wi,val);
	t[x] = f(t[x*2],t[x*2+1]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); 
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i], c[a[i]] = 1;
	for(int i = 1;i <= 2*n;i++) {
		if(!c[i]) b[++m] = i;
	}
	for(int i = 1;i <= n;i++) update(1,1,2*n,b[i],-1);
	for(int i = 1;i <= n;i++) {
		update(1,1,2*n,a[i],1);
		sl[i] = i-max(0,t[1].rmax);
	}
	for(int i = 1;i <= n;i++) update(1,1,2*n,a[i],0);
	for(int i = n;i >= 1;i--) {
		update(1,1,2*n,a[i],1);
		sr[i] = n-i+1-max(0,t[1].lmax);
	}
	int ans = 0;
	for(int i = 0;i <= n;i++) {
		ans = max(ans,sl[i]+sr[i+1]);
	}
	cout << ans;
}