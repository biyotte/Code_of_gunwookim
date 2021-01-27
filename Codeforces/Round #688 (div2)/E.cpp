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
const long long llINF = 1e18;
const long long mod = 998244353;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,m,c[200005],dep[200005],ans;
vec v[200005];
vec d;

void dfs(int x,int pr) {
	dep[x] = INF;
	vec v2;
	for(int i : v[x]) {
		//?
		if(i == pr) continue;
		dfs(i,x);
		dep[x] = min(dep[i]+1,dep[x]);
		v2.pb(dep[i]);
	}
	if(dep[x] == INF) {
		dep[x] = 0;
		return;
	}
	sort(all(v2));
	for(int i = 0;i < (int)v2.size()-1;i++) {
		ans = max(ans,v2[i]+2);
	}
	if(x^1) ans = max(ans,v2.back()+2);
	else ans = max(ans,v2.back()+1);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--) {
    	cin >> n;
    	for(int i = 1;i <= n;i++) v[i].clear();
    		ans = 0;
    	for(int i = 1;i < n;i++) {
    		int x,y; cin >> x >> y;
    		v[x].pb(y), v[y].pb(x);
    	}
    	dfs(1,-1);
    	cout << ans << '\n';
    }
}