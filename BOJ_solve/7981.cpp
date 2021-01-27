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
int n,c[200005],c2[200005];
ll sm[200005],lr[200005],d[200005];
vec v[200005];

ll dfs(int x) {
	if(c[x]) return llINF;
	if(c2[x]) return d[x];
	c[x] = c2[x] = 1;
	ll push_small = sm[x];
	for(int i : v[x]) {
		push_small = min(llINF,push_small+dfs(i));
	}
	c[x] = 0;
	return d[x] = min(push_small,lr[x]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) {
		cin >> sm[i] >> lr[i];
		int x; cin >> x;
		while(x--) {
			int y; cin >> y;
			v[i].pb(y);
		}
	}
	cout << dfs(1);
}
