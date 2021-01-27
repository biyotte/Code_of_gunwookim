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
const int MAXM = 1000000;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,m,c[100005];
double a[100005];
vecpi v[100005];

// not solved

struct Edge {
	int x,y; double w;
};
vector <Edge> edge;

void dfs(int x) {
	c[x] = 1;
	for(pi i : v[x]) {
		if(c[i.x]) continue;
		a[i.x] = (double)i.y-a[x];
		dfs(i.x);
	}
}

bool Iscorrect(double st) {
	memset(a,0,sizeof(a));
	memset(c,0,sizeof(c));
	a[1] = st;
	dfs(1);
	for(Edge i : edge) {
		if(a[i.x]+a[i.y] != i.w) return false;
	}
	cout << "YES\n";
	for(int i = 1;i <= n;i++) cout << a[i] << ' ';
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= m;i++) {
		int x,y,z; cin >> x >> y >> z;
		edge.pb({x,y,(double)z});
		v[x].pb({y,z});
		v[y].pb({x,z});
	}
	for(double i = -2;i <= 2;i += 0.1) {
		if(Iscorrect(i)) return 0;
	}
	cout << "NO";
}