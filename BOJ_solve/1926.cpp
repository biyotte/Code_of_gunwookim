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
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,m;
int a[505][505],c[505][505];
int nx[4] = {1,0,-1,0}, ny[4] = {0,1,0,-1};

int dfs(int x,int y) {
	if(c[x][y]) return 0; c[x][y] = 1;
	int cnt = 1;
	for(int i = 0;i < 4;i++) {
		if(a[x+nx[i]][y+ny[i]]) cnt += dfs(x+nx[i],y+ny[i]);
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); 
	cin >> n >> m;
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= m;j++) cin >> a[i][j];
	}
	int ans1 = 0,ans2 = 0;
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= m;j++) {
			if(!c[i][j]&&a[i][j]) ans1++, ans2 = max(ans2,dfs(i,j));
		}
	}
	cout << ans1 << '\n' << ans2;
}