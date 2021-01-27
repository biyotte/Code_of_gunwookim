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
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,m,c[200005];
int p[200005],o[200005],g;
vec v[200005];

struct Ans {int x,y,z;};
vector <Ans> ans;

int Find(int x) {return (p[x]^x ? p[x] = Find(p[x]) : x);}

int dfs(int x,int pr) {
    int st = 0;
    c[x] = 1;
    for(int i : v[x]) {
        if(i == pr) continue;
        int tmp = dfs(i,x);
        if(tmp) {
            if(st) ans.pb({o[st],o[x],o[i]}), st = 0;
            else st = i;
        }
    }
    if(st&&pr != -1) {
        ans.pb({o[st],o[x],o[pr]});
        return 0;
    }
    return 1;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> n >> m; g = n;
    for(int i = 1;i <= n;i++) p[i] = o[i] = i;
    for(int i = 1;i <= m;i++) {
        int x,y; cin >> x >> y;
        if(Find(x)^Find(y)) v[x].pb(y), v[y].pb(x), p[Find(y)] = Find(x);
        else v[x].pb(++g), v[g].pb(x), o[g] = y;
    }
    for(int i = 1;i <= g;i++) {
        if(!c[i]) dfs(i,-1);
    }
    cout << ans.size() << '\n';
    for(Ans i : ans) cout << i.x << ' ' << i.y << ' ' << i.z << '\n';
}
