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
const int MAXM = 100000;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pl;
typedef pair <ll,ll> pi;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,m,co,num,d[MAXN+5];
int p[MAXN+5],c[MAXM+5];
int pidx[MAXN+5];
bool isCactus = true;
vecpi v[MAXN+5];

void dfs(int x = 1,int pr = -1) {
	d[x] = ++num;
	p[x] = pr;
	for(pi j : v[x]) {
		int i = j.x, idx = j.y;
		if(i == pr) continue;
		if(!d[i]) pidx[i] = idx, dfs(i,x);
		else if(d[i] < d[x]) {
			for(int go = x;go^i;go = p[go]) {
				if(c[pidx[go]]) isCactus = false;
				c[pidx[go]] = 1;
			}
			if(c[idx]) isCactus = false;
			c[idx] = 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= m;i++) {
		int x,y; cin >> x >> y;
		v[x].pb({y,i}), v[y].pb({x,i});
	}
	dfs();
	cout << (isCactus ? "Cactus" : "Not cactus");
}