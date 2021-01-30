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
int n,Q,bc[800005],wc[800005];
int la[800005];
char a[200005],b[200005];
int l[200005],r[200005];

void build(int x,int l,int r) {
	la[x] = -1;
	if(l == r) {
		bc[x] = (b[l] == '0');
		wc[x] = (b[l] == '1');
		return;
	}
	int mid = (l + r) >> 1;
	build(x*2,l,mid), build(x*2+1,mid+1,r);
	bc[x] = bc[x*2]+bc[x*2+1];
	wc[x] = wc[x*2]+wc[x*2+1];
}

void push(int x,int l,int r) {
	if(la[x] != -1) {
		if(la[x]) wc[x] = (r-l+1), bc[x] = 0;
		else bc[x] = (r-l+1), wc[x] = 0;
		if(l^r) la[x*2] = la[x*2+1] = la[x];
		la[x] = -1;
	}
}

void update(int x,int l,int r,int rl,int rr,int val) {
	push(x,l,r);
	if(rl > r||l > rr) return;
	if(rl <= l&&r <= rr) {
		la[x] = val; push(x,l,r);
		return;
	}
	int mid = (l + r) >> 1;
	update(x*2,l,mid,rl,rr,val), update(x*2+1,mid+1,r,rl,rr,val);
	bc[x] = bc[x*2]+bc[x*2+1];
	wc[x] = wc[x*2]+wc[x*2+1];
}

pi query(int x,int l,int r,int rl,int rr) {
	push(x,l,r);
	if(rl > r||l > rr) return {0,0};
	if(rl <= l&&r <= rr) return {bc[x],wc[x]};
	int mid = (l + r) >> 1;
	pi L = query(x*2,l,mid,rl,rr), R = query(x*2+1,mid+1,r,rl,rr);
	return {L.x+R.x,L.y+R.y};
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while(T--) {
		cin >> n >> Q >> a+1 >> b+1;
		build(1,1,n);
		for(int i = 1;i <= Q;i++) {
			cin >> l[i] >> r[i];
		}
		int nope = 0;
		for(int i = Q;i >= 1;i--) {
			auto now = query(1,1,n,l[i],r[i]);
			int BC = now.x, WC = now.y;
			if(BC == WC) {
				nope = 1;
				break;
			}
			if(BC > WC) {
				update(1,1,n,l[i],r[i],0);
			}
			else {
				update(1,1,n,l[i],r[i],1);
			}
		}
		for(int i = 1;i <= n;i++) {
			auto now = query(1,1,n,i,i);
			int x;
			if(now.x) x = 0;
			else x = 1;
			if(a[i] != x+'0') nope = 1;
		}
		if(nope) cout << "NO\n";
		else cout << "YES\n";
	}
}
