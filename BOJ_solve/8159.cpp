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
int n,P,Q,tx,ty;
int a[2000005],sum[2000005];
int t[8000005];
char in[1000005];

void build(int x,int l,int r) {
	if(l == r) {
		t[x] = sum[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(x*2,l,mid), build(x*2+1,mid+1,r);
	t[x] = min(t[x*2],t[x*2+1]);
}

int query(int x,int l,int r,int rl,int rr) {
	if(rl > r||l > rr) return INF*2;
	if(rl <= l&&r <= rr) return t[x];
	int mid = (l + r) >> 1;
	return min(query(x*2,l,mid,rl,rr),query(x*2+1,mid+1,r,rl,rr));
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); 
    cin >> n >> P >> Q >> tx >> ty >> in+1;
    for(int i = 1;i <= n;i++) {
    	a[i] = (in[i] == '+' ? 1 : -1);
    	a[i+n] = a[i];
    }
	for(int i = 1;i <= 2*n;i++) {
		sum[i] = sum[i-1]+a[i];
	}
	build(1,1,2*n);
	ll ans = llINF;
	for(int i = n+1;i >= 2;i--) {
		int mn = query(1,1,2*n,i,i+n-1)-sum[i-1];
		mn += P;
		int la = 0,nam = sum[i+n-1]-sum[i-1]+P;
		if(mn < 0) la += (abs(mn)+1)/2;
		la *= 2, nam += la;
		ans = min(ans,1LL*(n+1-i)*ty+1LL*((abs(nam-Q))/2+la/2)*tx);
	}
	cout << ans;
}
