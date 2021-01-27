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
int n,k,cnt,len;
int isd[300005];
int nam[300005],dist[300005];
vec v[300005];

void dfs(int x,int pr) {
	dist[x] = -INF*(1-isd[x]);
	nam[x] = -INF;
	for(int i : v[x]) {
		if(i == pr) continue;
		dfs(i,x);
		dist[x] = max(dist[x],dist[i]+1);
		nam[x] = max(nam[x],nam[i]-1);
	}
	if(nam[x] >= dist[x]) dist[x] = -INF;
	if(dist[x] >= len) {
		cnt++;
		dist[x] = -INF;
		nam[x] = len;
	}
}

bool isok(int mid) {
	len = mid, cnt = 0;
	dfs(1,-1);
	if(dist[1] >= 0) cnt++;
	return (cnt <= k);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	for(int i = 1;i <= n;i++) cin >> isd[i];
	for(int i = 1;i < n;i++) {
		int x,y; cin >> x >> y;
		v[x].pb(y), v[y].pb(x);
	}
	int l = 0, r = n;
	while(l < r) {
		int mid = (l + r) >> 1;
		if(isok(mid)) r = mid;
		else l = mid+1;
	}
	cout << l;
}