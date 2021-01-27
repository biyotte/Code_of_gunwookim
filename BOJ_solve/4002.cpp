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
int n,l[100005];
ll sum[100005],m;
ll ans;
vec v[100005];
priority_queue <int> q[100001];

int dfs(int x) {
	int now = x;
	q[now].push(sum[x]);
	for(int i : v[x]) {
		int nx = dfs(i);
		sum[x] += sum[i];
		if(q[now].size() < q[nx].size()) swap(now,nx);
		while(!q[nx].empty()) q[now].push(q[nx].top()), q[nx].pop();
	}
	while(sum[x] > m) sum[x] -= q[now].top(), q[now].pop();
	ans = max(ans,(ll)l[x]*(ll)q[now].size());
	return now;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) {
		int x; cin >> x >> sum[i] >> l[i];
		v[x].pb(i);
	}
	dfs(1);
	cout << ans;
}