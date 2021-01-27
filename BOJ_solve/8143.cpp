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
int n,m,p[1000005],hole[1000005];
int ans,a[1005][1005];
vec q[1005];
vecpi op[1005];

int f(int x,int y) {return (x-1)*m+y;}
int Find(int x) {return (x^p[x] ? p[x] = Find(p[x]) : x);}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= m;j++) {
			cin >> a[i][j];
			p[f(i,j)] = f(i,j);
			if(a[i][j] > 0) q[a[i][j]].pb(f(i,j));
		}
	}
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= m;j++) {
			if(i < n) op[max(abs(a[i][j]),abs(a[i+1][j]))].pb({f(i,j),f(i+1,j)});
			if(j < m) op[max(abs(a[i][j]),abs(a[i][j+1]))].pb({f(i,j),f(i,j+1)});
		}
	}
	for(int i = 1;i <= 1000;i++) {
		for(pi j : op[i]) {
			if(Find(j.x) == Find(j.y)) continue;
			hole[p[j.x]] |= hole[p[j.y]];
			p[p[j.y]] = p[j.x];
		}
		for(int j : q[i]) {
			if(!hole[Find(j)]) ans++, hole[p[j]] = 1;
		}
	}
	cout << ans;
}