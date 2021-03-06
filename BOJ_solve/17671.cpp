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
const long long mod = 998244353;
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
int n,Q,ql[200005],qr[200005],ans[200005];
int h[200005],L[200005],R[200005];
int now[800005],mx[800005],la[800005];
vec add[200005],del[200005],qu[200005];

void push(int x,int l,int r) {
	if(la[x] != -INF) {
		mx[x] = max(mx[x],now[x]+la[x]);
		if(l^r) la[x*2] = max(la[x*2],la[x]), la[x*2+1] = max(la[x*2+1],la[x]);
		la[x] = -INF;
	}
}

void update_ad(int x,int l,int r,int wi,int val) {
	push(x,l,r);
	if(wi < l||r < wi) return;
	if(l == r) {
		now[x] = val;
		return;
	}
	int mid = (l + r) >> 1;
	update_ad(x*2,l,mid,wi,val), update_ad(x*2+1,mid+1,r,wi,val);
	now[x] = max(now[x*2],now[x*2+1]);
	mx[x] = max(mx[x*2],mx[x*2+1]);
}

void update_front(int x,int l,int r,int rl,int rr,int val) {
	push(x,l,r);
	if(rl > r||l > rr) return;
	if(rl <= l&&r <= rr) {
		la[x] = val;
		push(x,l,r);
		return;
	}
	int mid = (l + r) >> 1;
	update_front(x*2,l,mid,rl,rr,val), update_front(x*2+1,mid+1,r,rl,rr,val);
	now[x] = max(now[x*2],now[x*2+1]);
	mx[x] = max(mx[x*2],mx[x*2+1]);
}

int query(int x,int l,int r,int rl,int rr) {
	push(x,l,r);
	if(rl > r||l > rr) return -INF;
	if(rl <= l&&r <= rr) return mx[x];
	int mid = (l + r) >> 1;
	return max(query(x*2,l,mid,rl,rr),query(x*2+1,mid+1,r,rl,rr));
}

void go() {
	for(int i = 1;i <= 4*n;i++) now[i] = mx[i] = la[i] = -INF;
	for(int i = 1;i <= n;i++) {
		for(int idx : add[i]) update_ad(1,1,n,idx,-h[idx]);
		for(int idx : del[i]) update_ad(1,1,n,idx,-INF);
		if(i-L[i] > 0) update_front(1,1,n,max(1,i-R[i]),i-L[i],h[i]);
		for(int idx : qu[i]) {
			ans[idx] = max(ans[idx],query(1,1,n,ql[idx],n));
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) {
		cin >> h[i] >> L[i] >> R[i];
		add[min(n+1,i+L[i])].pb(i);
		del[min(n+1,i+R[i]+1)].pb(i);
	}
	cin >> Q;
	for(int i = 1;i <= Q;i++) {
		cin >> ql[i] >> qr[i];
		qu[qr[i]].pb(i);
		ans[i] = -INF;
	}
	go();
	for(int i = 1;i <= n;i++) h[i] *= -1; // A-B, B-A 둘다 해보기 위함
	go();
	for(int i = 1;i <= Q;i++) cout << (ans[i] < 0 ? -1 : ans[i]) << '\n';
}