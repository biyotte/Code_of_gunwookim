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
const long long llINF = 1e16;
const long long mod = 998244353;
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
map <int,int> sz[500005];
int idx[500005],ans;
int n,k,co[500005],mx[500005];
vec v[500005];

int dfs(int x,int pr) {
	int sum = 0; idx[x] = x;
	if(++sz[x][co[x]] == mx[co[x]]) sz[x].erase(co[x]);
	for(int i : v[x]) {
		if(i == pr) continue;
		sum += dfs(i,x);
		if(sz[idx[x]].size() < sz[idx[i]].size()) swap(idx[x],idx[i]);
		for(auto i : sz[idx[i]]) {
			sz[idx[x]][i.x] += i.y;
			if(sz[idx[x]][i.x] == mx[i.x]) sz[idx[x]].erase(i.x);
		}
	}
	if(!sz[idx[x]].empty()) return sum;
	sum += (x != 1), ans += (sum == 1);
	return (sum > 0);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	for(int i = 1;i < n;i++) {
		int x,y; cin >> x >> y;
		v[x].pb(y), v[y].pb(x);
	}
	for(int i = 1;i <= n;i++) {
		cin >> co[i];
		mx[co[i]]++;
	}
	dfs(1,-1);
	cout << (ans+1)/2;
}