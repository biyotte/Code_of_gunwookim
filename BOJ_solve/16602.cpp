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
const long long llINF = 5e18;
const long long mod = 1e9+7;
const long long hmod1 = 1e9+409;
const long long hmod2 = 1e9+433;
const long long base = 257;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,ti,ans,t[400005],ind[400005];
vec v[400005];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) {
		int x,y; cin >> t[i] >> x;
		for(;x--;) cin >> y, v[i].pb(y), ind[y]++;
	}
	priority_queue <pi> q;
	for(int i = 1;i <= n;i++) {
		if(!ind[i]) q.push({-t[i],i});
	}
	while(!q.empty()) {
		pi x = q.top(); q.pop();
		ans = max(ans,n-ti-1-x.x), ti++;
		for(int i : v[x.y]) {
			if(!--ind[i]) q.push({-t[i],i});
		}
	}
	cout << ans;
}