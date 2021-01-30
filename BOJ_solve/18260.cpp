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
int n,Q,co;
int in[100005],out[100005];
ll t[400005];
vec v[100005];
map <int,int> t2[400005];
vec la[400005];

void push(int x,int l,int r) {
	if(la[x].size()) {
		for(int i : la[x]) {
			t[x] -= 1LL*t2[x][i]*i;
			t2[x][i] = r-l+1;
			t[x] += 1LL*(r-l+1)*i;
			if(l^r) la[x*2].pb(i), la[x*2+1].pb(i);
		}
		la[x].clear();
	}
}

void update(int x,int l,int r,int rl,int rr,int val) {
	push(x,l,r);
	if(rl > r||l > rr) return;
	if(rl <= l&&r <= rr) {
		la[x].pb(val); push(x,l,r);
		return;
	}
	int mid = (l + r) >> 1;
	update(x*2,l,mid,rl,rr,val), update(x*2+1,mid+1,r,rl,rr,val);
	t[x] = t[x*2]+t[x*2+1];
	t2[x][val] = t2[x*2][val]+t2[x*2+1][val];
}

ll query(int x,int l,int r,int rl,int rr) {
	push(x,l,r);
	if(rl > r||l > rr) return 0;
	if(rl <= l&&r <= rr) return t[x];
	int mid = (l + r) >> 1;
	return query(x*2,l,mid,rl,rr)+query(x*2+1,mid+1,r,rl,rr);
}

void dfs(int x,int pr) {
	in[x] = ++co;
	for(int i : v[x]) {
		if(i != pr) dfs(i,x);
	}
	out[x] = co;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> Q;
	for(int i = 1;i < n;i++) {
		int x,y; cin >> x >> y;
		v[x].pb(y), v[y].pb(x);
	}
	dfs(1,-1);
	while(Q--) {
		int op,x,y;
		cin >> op >> x;
		if(op & 1) {
			cin >> y;
			update(1,1,n,in[x],out[x],y);
		}
		else cout << query(1,1,n,in[x],out[x]) << '\n';
	}
}
