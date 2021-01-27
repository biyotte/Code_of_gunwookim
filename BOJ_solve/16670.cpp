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
int Q;
ll d[4000005],t[4000005],la[4000005];
pi q[4000005];

void updateD(int x,int l,int r,int wi,ll val) {
	if(wi < l||r < wi) return;
	if(l == r) {
		d[x] += val;
		return;
	}
	int mid = (l + r) >> 1;
	updateD(x*2,l,mid,wi,val), updateD(x*2+1,mid+1,r,wi,val);
	d[x] = d[x*2]+d[x*2+1];
}

ll queryD(int x,int l,int r,int rl,int rr) {
	if(rl > r||l > rr) return 0;
	if(rl <= l&&r <= rr) return d[x];
	int mid = (l + r) >> 1;
	return queryD(x*2,l,mid,rl,rr)+queryD(x*2+1,mid+1,r,rl,rr);
}

void push(int x,int l,int r) {
	if(la[x]) {
		t[x] += la[x];
		if(l^r) la[x*2] += la[x], la[x*2+1] += la[x];
		la[x] = 0;
	}
}

void updateT(int x,int l,int r,int wi,ll val) {
	push(x,l,r);
	if(wi < l||r < wi) return;
	if(l == r) {
		t[x] = val;
		return;
	}
	int mid = (l + r) >> 1;
	updateT(x*2,l,mid,wi,val), updateT(x*2+1,mid+1,r,wi,val);
	t[x] = max(t[x*2],t[x*2+1]);
}

void updateTD(int x,int l,int r,int rl,int rr,ll val) {
	push(x,l,r);
	if(rl > r||l > rr) return;
	if(rl <= l&&r <= rr) {
		la[x] = val;
		push(x,l,r);
		return;
	}
	int mid = (l + r) >> 1;
	updateTD(x*2,l,mid,rl,rr,val), updateTD(x*2+1,mid+1,r,rl,rr,val);
	t[x] = max(t[x*2],t[x*2+1]);
}

ll queryT(int x,int l,int r,int rl,int rr) {
	push(x,l,r);
	if(rl > r||l > rr) return 0;
	if(rl <= l&&r <= rr) return t[x];
	int mid = (l + r) >> 1;
	return max(queryT(x*2,l,mid,rl,rr),queryT(x*2+1,mid+1,r,rl,rr));
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> Q;
	for(int tc = 1;tc <= Q;tc++) {
		char op; int x,y;
		cin >> op >> x;
		if(op == '+') {
			cin >> y;
			q[tc] = {x,y};
			updateT(1,1,MAXM,x,x+queryD(1,1,MAXM,x,MAXM));
			updateD(1,1,MAXM,x,y);
			updateTD(1,1,MAXM,1,x,y);
		}
		if(op == '-') {
			y = q[x].y, x = q[x].x;
			updateD(1,1,MAXM,x,-y);
			updateTD(1,1,MAXM,1,x,-y);
			updateT(1,1,MAXM,x,0);
		}
		if(op == '?') {
			cout << max(0LL,queryT(1,1,MAXM,1,x)-queryD(1,1,MAXM,x+1,MAXM)-x) << '\n';
		}
	}
}