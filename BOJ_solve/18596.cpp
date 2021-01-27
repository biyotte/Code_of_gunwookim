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
const int MAXN = 100000;
const int MAXM = 1000000;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int T,n,c[100005],pa[100005],p[100005];
vec v[100005];

struct Monster {
	ll a,b,idx;

	bool operator < (const Monster &r) const {
		ll upx = b-a, upy = r.b-r.a;
		if(upx < 0&&upy < 0) return b < r.b;
		else if(upx >= 0&&upy < 0) return 0;
		else if(upx < 0&&upy >= 0) return 1;
		else return a > r.a;
	}

}a[100005];

priority_queue <Monster> q;

void dfs(int x,int pr) {
	for(int i : v[x]) {
		if(i == pr) continue;
		dfs(i,x);
		pa[i] = x;
	}
}

int Find(int x) {return (x^p[x] ? p[x] = Find(p[x]) : x);}

void merge(int x,int y) {
	x = Find(x), y = Find(y);
	if(x == y) return;
	p[y] = x;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	while(T--) {
		cin >> n;
		a[1] = {0,0,1};
		for(int i = 1;i <= n;i++) v[i].clear(), p[i] = i;
		for(int i = 2;i <= n;i++) {
			cin >> a[i].a >> a[i].b;
			a[i].idx = i;
			c[i] = 0;
			q.push(a[i]);
		}
		for(int i = 1;i < n;i++) {
			int x,y; cin >> x >> y;
			v[x].pb(y), v[y].pb(x);
		}
		dfs(1,-1);
		while(!q.empty()) {
			auto now = q.top(); q.pop();
			int x = now.idx;
			if(c[x]) continue;
			c[x] = 1;
			int y = Find(pa[x]);
			ll na = min(-a[y].a,-a[y].a+a[y].b-a[x].a);
			ll nb = -a[y].a+a[y].b-a[x].a+a[x].b-na;
			a[y].a = -na, a[y].b = nb;
			p[x] = y;
			if(y^1) q.push(a[y]);
		}
		cout << a[1].a << '\n';
	}
}