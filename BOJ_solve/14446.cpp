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
int n,co,a[100005],in[100005],out[100005];
int tpos[100005];
vec t[400005],v[100005];

void dfs(int x) {
	in[x] = ++co;
	for(int i : v[x]) dfs(i);
	out[x] = co;
}

void build(int x,int l,int r) {
	if(l == r) {
		t[x].pb(a[tpos[l]]);
		return;
	}
	int mid = (l + r) >> 1;
	build(x*2,l,mid), build(x*2+1,mid+1,r);
	for(int i : t[x*2]) t[x].pb(i);
	for(int i : t[x*2+1]) t[x].pb(i);
	sort(all(t[x]));
}

int query(int x,int l,int r,int rl,int rr,int L) {
	if(rl > r||l > rr) return 0;
	if(rl <= l&&r <= rr) {
		int itl = lower_bound(all(t[x]),L)-t[x].begin();
		return (int)t[x].size()-itl;
	}
	int mid = (l + r) >> 1;
	return query(x*2,l,mid,rl,rr,L)+query(x*2+1,mid+1,r,rl,rr,L);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);   
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 2;i <= n;i++) {
		int x; cin >> x;
		v[x].pb(i);
	}
	dfs(1);
	for(int i = 1;i <= n;i++) tpos[in[i]] = i;
	build(1,1,n);
	for(int i = 1;i <= n;i++) {
		cout << query(1,1,n,in[i],out[i],a[i]+1) << '\n';
	}
}