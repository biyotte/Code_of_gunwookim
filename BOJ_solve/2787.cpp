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
const long long mod = 1e9+7;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,Q,l[205],r[205],hi[205],lo[205],c[205],c2[205];
vec v[205];

int dfs(int x) {
	if(c[x]) return 0;
	c[x] = 1;
	for(int i : v[x]) {
		if(!c2[i]||dfs(c2[i])) {
			c2[i] = x;
			return 1;
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> Q;
	for(int i = 1;i <= n;i++) l[i] = lo[i] = 1, r[i] = hi[i] = n;
	for(int i = 1;i <= Q;i++) {
		int op,x,y,z;
		cin >> op >> x >> y >> z;
		l[z] = max(l[z],x), r[z] = min(r[z],y);
		for(int j = x;j <= y;j++) {
			if(op & 1) hi[j] = min(hi[j],z);
			else lo[j] = max(lo[j],z);
		}
	}
	for(int i = 1;i <= n;i++) {
		for(int j = lo[i];j <= hi[i];j++) {
			if(l[j] <= i&&i <= r[j]) v[j].pb(i);
		}
	}
	int ans = 0;
	for(int i = 1;i <= n;i++) {
		memset(c,0,sizeof(c));
		ans += dfs(i);
	}
	if(ans^n) cout << -1;
	else for(int i = 1;i <= n;i++) cout << c2[i] << ' ';
}
