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
int n,m,a[105],c[105];
int arrow[10005],ch[10005];
pi edge[10005];
vecpi v[105];

void dfs(int x) {
	c[x] = 1;
	for(pi i : v[x]) {
		if(!ch[abs(i.y)]) {
			if(i.y > 0) arrow[i.y] = 1;
			else arrow[-i.y] = 0;
			ch[abs(i.y)] = 1;
		}
		if(!c[i.x]) dfs(i.x);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= m;i++) {
		int x,y; cin >> x >> y;
		edge[i] = {x,y};
	}
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= m;i++) {
		int x = edge[i].x, y = edge[i].y;
		if(a[x] < a[y]) arrow[i] = 0;
		else if(a[x] > a[y]) arrow[i] = 1;
		else v[x].pb({y,i}), v[y].pb({x,-i});
	}
	for(int i = 1;i <= n;i++) {
		if(!c[i]) dfs(i);
	}
	for(int i = 1;i <= m;i++) {
		if(arrow[i]) cout << "->\n";
		else cout << "<-\n";
	}
}