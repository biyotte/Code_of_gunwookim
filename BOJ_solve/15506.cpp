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
const int MAXN = 20000;
const int MAXM = 4000000;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pl;
typedef pair <ll,ll> pi;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,Q,k,idx,er[1000005],wtidx[1000005];
int sz[400005];
priority_queue <pl> q[400005];

// not solved

void add(int x,int l,int r,int wi,ll val) {
	if(wi < l||r < wi) return;
	q[x].push({val,idx});
	sz[x]++;
	if(l == r) {wtidx[idx] = x; return;}
	int mid = (l + r) >> 1;
	add(x*2,l,mid,wi,val), add(x*2+1,mid+1,r,wi,val);
}

void Erase(int x) {
	while(x) sz[x]--, x /= 2;
}

void del(int x,int l,int r,int rl,int rr,ll val) {
	if(rl > r||l > rr) return;
	if(rl <= l&&r <= rr) {
		while(!q[x].empty()&&(er[q[x].top().y]||q[x].top().x > val)) {
			if(er[q[x].top().y]) {q[x].pop(); continue;}
			er[q[x].top().y] = 1, Erase(wtidx[q[x].top().y]), q[x].pop();
		}
		return;
	}
	int mid = (l + r) >> 1;
	del(x*2,l,mid,rl,rr,val), del(x*2+1,mid+1,r,rl,rr,val);
	while(!q[x].empty()&&er[q[x].top().y]) q[x].pop();
}

int query(int x,int l,int r,int rl,int rr) {  
	while(!q[x].empty()&&er[q[x].top().y]) q[x].pop();
	if(rl > r||l > rr) return 0;
	if(rl <= l&&r <= rr) {
		return sz[x];
	}
	int mid = (l + r) >> 1;
	return query(x*2,l,mid,rl,rr)+query(x*2+1,mid+1,r,rl,rr);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> Q >> k;
	for(int i = 1;i <= Q;i++) {
		int op,t,l,r,h; cin >> op >> t >> l >> r;
		idx = i;
		if(op == 1) add(1,1,n,l,(ll)r-(ll)t*k);
		else if(op == 2) cin >> h, del(1,1,n,l,r,(ll)h-(ll)t*k);
		else cout << query(1,1,n,l,r) << '\n';
	}
}
