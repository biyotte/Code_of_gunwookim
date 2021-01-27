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
int n,m,co;
int l[1005][15],r[1005][15];
char ma[1005][15];
vec v[20005];

int f(int x) {
	if(x <= 10000) return x+10000;
	else return x-10000;
}

void addEdge(int x,int y) {
	v[f(x)].pb(y);
	v[f(y)].pb(x);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); 
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> ma[i]+1;
	for(int i = 1;i <= n;i++) {
		int ch = 0;
		for(int j = 1;j <= m;j++) {
			if(a[i][j] == '.') ch = 0;
			else {
				if(!ch) l[i][j] = ++co, ch = 1;
				else l[i][j] = co;
			}
		}
	}
	for(int i = 1;i <= m;i++) {
		int ch = 0;
		for(int j = 1;j <= n;j++) {
			if(a[j][i] == '.') ch = 0;
			else {
				if(!ch) r[j][i] = ++co, ch = 1;
				else r[j][i] = co;
			}
		}
	}
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= m;j++) {
			if(a[i][j] != '.')
		}
	}
}