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
const long long llINF = 1e18;
const int mod = 998244353;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,Q,p[100005],sz[100005],c[100005];
int a[100005],ans[100005],mx = 0;
pi q[100005];
vecpi qu[200005];
vec rev,un[200005];

int Find(int x) {return (x^p[x] ? p[x] = Find(p[x]) : x);}

void merge(int x,int y) {
	x = Find(x), y = Find(y);
	if(x == y) return;
	p[y] = x;
	sz[x] += sz[y];
	mx = max(mx,sz[x]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> Q;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
		p[i] = i, sz[i] = 1;
		rev.pb(a[i]);
	}
	for(int i = 1;i <= Q;i++) {
		cin >> q[i].x >> q[i].y;
		rev.pb(q[i].x);
	}
	sort(all(rev)), rev.erase(unique(all(rev)),rev.end());
	for(int i = 1;i <= n;i++) {
		a[i] = lower_bound(all(rev),a[i])-rev.begin()+1;
		un[a[i]].pb(i);
	}
	for(int i = 1;i <= Q;i++) {
		q[i].x = lower_bound(all(rev),q[i].x)-rev.begin()+1;
		qu[q[i].x].pb({q[i].y,i});
	}
	for(int i = rev.size();i >= 1;i--) {
		for(pi j : qu[i]) {
			if(j.x > mx) ans[j.y] = 1;
		}
		for(int j : un[i]) {
			if(c[j-1]) merge(j-1,j);
			if(c[j+1]) merge(j,j+1);
			mx = max(mx,1);
			c[j] = 1;
		}
	}
	for(int i = 1;i <= Q;i++) cout << ans[i] << '\n';
}