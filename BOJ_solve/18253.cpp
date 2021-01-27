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
int n,m,Q,nx[4] = {1,0,-1,0}, ny[4] = {0,1,0,-1};
ll a[6][100005],d[6][100005];
ll ans[100005];

struct Query {
	int x1,y1,x2,y2;
}query[100005];

priority_queue <pair<ll,pi>> qq;

void dij(int l,int r,int mid,int wi) {
	qq.push({0,{wi,mid}});
	for(int i = 1;i <= n;i++) for(int j = l;j <= r;j++) d[i][j] = -1;
	while(!qq.empty()) {
		ll cosat = -qq.top().x; int x = qq.top().y.x, y = qq.top().y.y; qq.pop();
		if(d[x][y] != -1) continue;
		d[x][y] = cost;
		for(int i = 0;i < 4;i++) {
			int dx = x+nx[i], dy = y+ny[i];
			if(dx < 1||dx > n||dy < l||dy > r||d[dx][dy] != -1) continue;
			qq.push({-cost-a[dx][dy],{dx,dy}});
		}
	}
}

void go(int l,int r,vec &q) {
	if(q.empty()||l > r) return;
	int mid = (l + r) >> 1;
	for(int i = 1;i <= n;i++) {
		dij(l,r,mid,i);
		for(int j : q) {
			ans[j] = min(ans[j],d[query[j].x1][query[j].y1]+d[query[j].x2][query[j].y2]+a[i][mid]);
		}
	}
	vec L,R;
	for(int i : q) {
		if(query[i].y2 < mid) L.pb(i);
		if(query[i].y1 > mid) R.pb(i);
	}
	go(l,mid-1,L), go(mid+1,r,R);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= m;j++) cin >> a[i][j];
	}
	vec q;
	cin >> Q;
	for(int i = 1;i <= Q;i++) {
		int x1,y1,x2,y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if(y1 > y2) swap(x1,x2), swap(y1,y2);
		query[i] = {x1,y1,x2,y2};
		q.pb(i), ans[i] = llINF;
	}
	go(1,m,q);
	for(int i = 1;i <= Q;i++) cout << ans[i] << '\n';
}