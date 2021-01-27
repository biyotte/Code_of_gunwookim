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
typedef pair <int,int> pl;
typedef pair <ll,ll> pi;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
#define Point pair<pi,pi>
Point z[1005];
vec v[1005];
int n,c[1005];

ll ccw(pi a,pi b,pi c) {
    ll op = a.x*b.y+b.x*c.y+c.x*a.y;
    op -= (a.y*b.x+b.y*c.x+c.y*a.x);
    if(op > 0) return 1;
    else if(op == 0) return 0;
    else return -1;
}
 
int IsMaching(Point x,Point y) {
    pi a = x.x, b = x.y, c = y.x, d = y.y;
    int ab = ccw(a,b,c)*ccw(a,b,d);
    int cd = ccw(c,d,a)*ccw(c,d,b);
    if(ab == 0&&cd == 0) {
        if(a > b) swap(a,b);
        if(c > d) swap(c,d);
        return c <= b&&a <= d;
    }
    return ab <= 0&&cd <= 0;
}
 
void dfs(int x) {
	if(c[x]) return;
	c[x] = 1;
	for(int i : v[x]) dfs(i);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> z[i].x.x >> z[i].x.y >> z[i].y.x >> z[i].y.y;
	int E = 0, V = n, C = 0;
	for(int i = 1;i <= n;i++) {
		for(int j = i+1;j <= n;j++) {
			if(IsMaching(z[i],z[j])) {
				E++;
				v[i].pb(j), v[j].pb(i);
			}
		}
	}
	for(int i = 1;i <= n;i++) {
		if(c[i]) continue;
		C++;
		dfs(i);
	}
	cout << E-V+C;
}