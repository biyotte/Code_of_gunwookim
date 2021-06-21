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
const long long llINF = 1e18+10;
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
int n,d[100005];
vec v[100005];

void dfs(int x,int pr) {
	for(int i : v[x]) {
		if(i == pr) continue;
		d[i] = d[x]+1;
		dfs(i,x);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i < n;i++) {
		int x,y; cin >> x >> y;
		v[x].pb(y), v[y].pb(x);
	}
	dfs(1,-1);
	int mx = 1;
	for(int i = 1;i <= n;i++) {
		if(d[mx] < d[i]) mx = i;
	}
	d[mx] = 0;
	dfs(mx,-1);
	mx = 1;
	for(int i = 1;i <= n;i++) {
		if(d[mx] < d[i]) mx = i;
	}
	cout << d[mx]+1;
}
