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
int sz[100005],dep[1000005];
int n,k,ans,up[100005],l[100005];
vec v[100005];
vec an;

void dfs(int x,int depth) {
	l[x] = 1, dep[x] = depth;
	for(int &i : v[x]) {
		dfs(i,depth+1);
		l[x] = max(l[x],l[i]+1);
		if(l[i] > l[v[x][0]]) swap(i,v[x][0]);
	}
}

void dfs2(int x,int la) {
	up[x] = la;
	if(v[x].empty()) an.pb(dep[x]-dep[la]+1);
	for(int i : v[x]) {
		if(i == v[x][0]) dfs2(i,la);
		else dfs2(i,i);
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	cin >> n >> k;
	for(int i = 2;i <= n;i++) {
		int x; cin >> x;
		v[x].pb(i);
	}
	dfs(1,1), dfs2(1,1);
	sort(all(an)), reverse(all(an));
	for(int i = 0;i < min(k,(int)an.size());i++) {
		ans += an[i];
	}
	cout << ans;
}  
