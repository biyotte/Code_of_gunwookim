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
const int MAXN = 20000;
const int MAXM = 4000000;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,d[100005],p[100005],sz[100005];
vec v[100005];

bool cmp(int x,int y) {return (sz[x]-d[x])-d[x] < (sz[y]-d[y])-d[y];}

// not solved

void dfs(int x) {
	sz[x] = 1;
	for(int i : v[x]) dfs(i), sz[x] += sz[i];
	sort(all(v[x]),cmp);
	int ta = 0;
	for(int i = 0;i < v[x].size();i++) {
		if(i % 2 == 0) ta += sz[v[x][i]]-d[v[x][i]];
		else ta += d[v[x][i]];
	}
	d[x] = sz[x]-ta;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 2;i <= n;i++) {
		cin >> p[i];
		v[p[i]].pb(i);
	}
	dfs(1);
	//for(int i = 1;i <= n;i++) cout << d[i] << ' ';
	cout << d[1];
}
