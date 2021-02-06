#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define all(v) v.begin(),v.end()
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
using namespace std;
const long long INF = 1e9;
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
int n,m,c[1005],c2[1005];
char a[1005][1005];
vec va[1005],vb[1005],cyc;

// not solved

int dfsA(int x) {
	if(c2[x]) return 1;
	if(c[x]) return 0;
	c2[x] = c[x] = 1;
	for(int i : va[x]) {
		if(dfsA(i)) {
			cyc.pb(x);
			return 1;
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while(T--) {
		cin >> n >> m;
		for(int i = 1;i <= n;i++) {
			cin >> a[i]+1;
			va[i].clear(), vb[i].clear();
			for(int j = 1;j <= n;j++) {
				if(i^j) {
					if(a[i][j] == 'a') va[i].pb(j);
					else vb[i].pb(j);
				}
			}
		}
		if(m % 2) {
			for(int i = 1;i <= m;i++) cout << 1+(i%2) << ' ';
			continue;
		}
		int fl = 0;
		cyc.clear();
		for(int i = 1;i <= n;i++) c[i] = c2[i] = 0;
		for(int i = 1;i <= n;i++) {
			if(c[i]) continue;
			int tmp = dfsA(i);
			if(tmp) {
				for(int j = 1;j <= m;j++) {
					cout << cyc[j%((int)cyc.size())] << ' ';
				}
				break;
			}
		}
		cyc.clear();
		for(int i = 1;i <= n;i++) c[i] = c2[i] = 0;
	}
}
