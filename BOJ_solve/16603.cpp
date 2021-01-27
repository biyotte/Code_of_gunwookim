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
const long long llINF = 5e18;
const long long mod = 1e9+7;
const long long hmod1 = 1e9+409;
const long long hmod2 = 1e9+433;
const long long base = 257;
const long double PI = 3.141592653589793238462643383279502884;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,g;
vec v[1005];
ld x[1005],y[1005];

void dfs(int now,int pr) {
    for(int i : v[now]) {
        if(i == pr) continue;
        x[i] = x[now]+cos(PI*g/n);
        y[i] = y[now]+sin(PI*g/n);
        g++, dfs(i,now);
    }
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> n;
    for(int i = 1;i < n;i++) {
        int x,y; cin >> x >> y;
        v[x].pb(y), v[y].pb(x);
    }
    dfs(1,-1);
    cout << fixed << setprecision(8);
    for(int i = 1;i <= n;i++) cout << x[i] << ' ' << y[i] << '\n';
}
