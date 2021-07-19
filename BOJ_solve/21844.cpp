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
const int MAXN = 100000;
const int MAXM = 1000000;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,m,g,a[1000005];
vec v[1000005];

int dfs(int x,int op) {
    if(c[x]) {
        if(c[x]^op) {
            cout << "impossible";
            exit(0);
        }
        return 0;
    }
    c[x] = op;
    int ret = (op & 1 ? -1 : 1);
    for(int i : v[x]) {
        ret += dfs(i,3-op);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    while(m--) {
        int cn,x,y; cin >> cn >> x; cn--;
        while(cn--) {
            cin >> y;
            v[x].pb(y), v[y].pb(x);
            x = y;
        }
    }
    for(int i = 1;i <= n;i++) {
        if(c[i]) continue;
        int ret = dfs(i,1);
        a[++g] = abs(ret);
    }
}