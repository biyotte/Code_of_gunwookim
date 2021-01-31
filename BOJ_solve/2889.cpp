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
const long long mod = 1999;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,m,rm,coo,ind[200005],ans[200005];
int ne[200005],c[200005];
vecpi v[200005];

void dfs(int x,int co) {
    for(pi i : v[x]) {
        if(c[i.y]) continue;
        c[i.y] = 1;
        ans[i.y] = co;
        dfs(i.x,co^3);
    }
}

void dfs2(int x) {
    if(ne[x]) return;
    ne[x] = coo;
    for(pi i : v[x]) dfs2(i.x);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m; rm = m;
    for(int i = 1;i <= m;i++) {
        int x,y; cin >> x >> y;
        v[x].pb({y,i}), v[y].pb({x,i});
        ind[x]++, ind[y]++;
    }
    coo = n;
    for(int i = 1;i <= n;i++) {
        if(!ne[i]) ++coo, dfs2(i);
    }
    for(int i = 1;i <= n;i++) {
        if(ind[i] % 2) v[i].pb({ne[i],++rm}), v[ne[i]].pb({i,rm});
    }
    for(int i = 1;i <= coo;i++) dfs(i,1);
    for(int i = 1;i <= n;i++) {
        int fl = 0,cnt = 0;
        for(pi j : v[i]) {
            if(j.x <= n) cnt++, fl |= ans[j.y];
        }
    }
    for(int i = 1;i <= m;i++) cout << ans[i] << '\n';
}
