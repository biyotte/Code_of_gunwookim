#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define sz(v) v.size()
#define all(v) v.begin(),v.end()
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
using namespace std;
const int INF = 1e9;
const int TMX = 1 << 18;
const long long llINF = 1e18+10;
const long long mod = 1e9+433;
const long long hmod1 = 1e9+409;
const long long hmod2 = 1e9+433;
const long long base = 257;
const int MAXN = 100000;
const int MAXM = 1000000;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,ans[1000005];
int a[1000005][2];
pi g[1000005][2];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n*2;i++) cin >> a[i][0];
    for(int i = 1;i <= n*2;i++) cin >> a[i][1];
    for(int i = 1;i <= n*2;i++) {
        g[i][0] = {INF,-INF}, g[i][1] = {INF,-INF};
    }
    g[1][0] = {1,1}, g[1][1] = {-1,-1};
    for(int i = 2;i <= n*2;i++) {
        for(int j : {0,1}) {
            for(int k : {0,1}) {
                if(a[i-1][k] <= a[i][j]) g[i][j] = {min(g[i][j].x,g[i-1][k].x+(j?-1:1)),max(g[i][j].y,g[i-1][k].y+(j?-1:1))};
            }
        }
    }
    int st = (g[n*2][0].x <= 0&&0 <= g[n*2][0].y ? 0 : g[n*2][1].x <= 0&&0 <= g[n*2][1].y ? 1 : -1);
    if(st == -1) {
        cout << -1;
        return 0;
    }
    for(int i = 2*n,j = st,val = 0;i >= 1;i--) {
        ans[i] = j;
        int nx;
        val -= (j?-1:1);
        for(int k : {0,1}) {
            if(g[i-1][k].x <= val&&val <= g[i-1][k].y&&a[i-1][k] <= a[i][j]) nx = k;
        }
        j = nx;
    }
    for(int i = 1;i <= 2*n;i++) cout << (ans[i] ? "B" : "A");
}