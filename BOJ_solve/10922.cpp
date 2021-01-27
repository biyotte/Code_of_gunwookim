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
const long long llINF = 5e18;
const long long mod = 1e9+7;
const long long hmod1 = 1e9+409;
const long long hmod2 = 1e9+433;
const long long base = 257;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,Q;
ll X[500005],Y[500005];

struct Tree {
	ll ans,x,y;
	double logX,logY,sum;
}t[2000005];

Tree f(Tree L,Tree R) {
	Tree ret;
	ret.logX = L.logX+R.logX, ret.x = L.x*R.x%mod;
	if(L.sum < L.logX+R.sum) ret.sum = L.logX+R.sum, ret.ans = L.x*R.ans%mod;
	else ret.sum = L.sum, ret.ans = L.ans;
	return ret;
}

void update(int x,int l,int r,int wi,ll X,ll Y) {
	if(wi < l||r < wi) return;
	if(l == r) {
		if(X) t[x].x = X, t[x].logX = log(X); 
		if(Y) t[x].y = Y, t[x].logY = log(Y);
		t[x].sum = t[x].logX+t[x].logY;
		t[x].ans = t[x].x*t[x].y%mod;
		return;
	}
	int mid = (l + r) >> 1;
	update(x*2,l,mid,wi,X,Y), update(x*2+1,mid+1,r,wi,X,Y);
	t[x] = f(t[x*2],t[x*2+1]);
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> X[i];
	for(int i = 1;i <= n;i++) {
		cin >> Y[i];
		update(1,1,n,i,X[i],Y[i]);
	}
	cout << t[1].ans << '\n';
	cin >> Q;
	while(Q--) {
		ll op,x,y;
		cin >> op >> x >> y, x++;
		if(op & 1) update(1,1,n,x,y,0);
		else update(1,1,n,x,0,y);
		cout << t[1].ans << '\n';
	}
}
