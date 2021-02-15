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
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,m,a[1000005];
int b[1000005],idx[1000005];
vec v[1000005];
ll add[4000005],t[4000005];

void update(int x,int l,int r,int rl,int rr,int val) {
	if(rl > r||l > rr) return;
	if(rl <= l&&r <= rr) {
		add[x] += val;
		t[x] += val;
		return;
	}
	int mid = (l + r) >> 1;
	update(x*2,l,mid,rl,rr,val), update(x*2+1,mid+1,r,rl,rr,val);
	t[x] = max(t[x*2],t[x*2+1])+add[x];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
		v[a[i]].pb(i);
	}
	for(int i = 1;i <= m;i++) v[i].pb(n+1);
	for(int i = 1;i <= m;i++) cin >> b[i];
	for(int i = 1;i <= m;i++) {
		if(v[i].size() >= 2) update(1,1,n,v[i][0],v[i][1]-1,b[i]);
	}
	ll ans = t[1];
	for(int i = 1;i <= n;i++) {
		int now = a[i];
		update(1,1,n,v[now][idx[now]],v[now][idx[now]+1]-1,-b[now]);
		if(++idx[now] <= (int)v[now].size()-2) {
			update(1,1,n,v[now][idx[now]],v[now][idx[now]+1]-1,b[now]);
		}
		ans = max(ans,t[1]);
	}
	cout << ans;
}
