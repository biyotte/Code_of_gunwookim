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
int n,m,ind[200005],a[200005];
int d[200005],ans = -INF*2;
vec v[200005];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= m;i++) {
		int x,y; cin >> x >> y;
		v[x].pb(y), ind[y]++;
	}
	queue <int> q;
	for(int i = 1;i <= n;i++) {
		d[i] = INF*2;
		if(!ind[i]) q.push(i);
	}
	while(!q.empty()) {
		int x = q.front(); q.pop();
		ans = max(ans,a[x]-d[x]);
		for(int i : v[x]) {
			d[i] = min({d[i],d[x],a[x]});
			if(!--ind[i]) q.push(i);
		}
	}
	cout << ans;
}