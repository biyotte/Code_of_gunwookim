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
const int MAXN = 20000;
const int MAXM = 4000000;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
ll x,c;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> x >> c;
	vector <pl> g;
	g.pb({x-c/2,x+(c-2)/2});
	g.pb({-(c-1)/2-x,(c-1)/2-x});
	sort(all(g));
	if(g[0].y < g[1].x) cout << g[0].y-g[0].x+1+g[1].y-g[1].x+1;
	else cout << g[1].y-g[0].x+1;
}
