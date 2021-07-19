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
int n,m,ind[1005],is[1005];
int st,en,k,d[1005][1005];
vec v[1005],rv[1005];

queue <int> q;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= m;i++) {
		int x,y; cin >> x >> y;
		v[x].pb(y), ind[y]++;
		rv[y].pb(x);
	}
	cin >> st >> en >> k;
	for(int i = 1;i <= k;i++) {
		int x; cin >> x;
		is[x] = 1;
	}
	for(int i = 1;i <= n;i++) {
		if(!ind[i]) q.push(i);
	}
	d[st][is[st]] = 1;
	while(!q.empty()) {
		int x = q.front(); q.pop();
		for(int y : rv[x]) {
			for(int i = 0;i <= k;i++) {
				if(is[x]) d[x][i] += (i ? d[y][i-1] : 0);
				else d[x][i] += d[y][i];
			}
		}
		if(x == en) {
			cout << d[x][k];
			return 0;
		}
		for(int i : v[x]) {
			if(!--ind[i]) q.push(i);
		}
	}
}
