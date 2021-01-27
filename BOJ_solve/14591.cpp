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
const long long mod = 1e18;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,c[2005];
vec v[2005],ans;

void dfs(int x) {
	if(c[x]++) return;
	for(int i : v[x]) dfs(i);
	ans.pb(x);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) {
			int x; cin >> x;
			if(x) v[i].pb(j);
		}
	}
	dfs(1);
	reverse(all(ans));
	cout << ans.size() << '\n';
	for(int i : ans) cout << i << ' ';
}