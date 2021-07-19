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
const long long llINF = 4e18+10;
const long long mod = 20070713;
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
int n,m,issp[200005],dep[200005];
int p[200005],sp[20][200005],va[20][200005];
vecpi v[200005];
ll valSum;

struct Edge {
    int x,y,idx;
    ll val;
};
vector <Edge> edge,ted;

bool cmp(Edge x,Edge y) {return x.val < y.val;}
bool cmpIdx(Edge x,Edge y) {return x.idx < y.idx;}
int Find(int x) {return (x^p[x] ? p[x] = Find(p[x]) : x);}

void dfs(int x,int la) {
    for(pi i : v[x]) {
        if(i.x == la) continue;
        sp[0][i.x] = x;
        va[0][i.x] = i.y;
        dep[i.x] = dep[x]+1;
        dfs(i.x,x);
    }
}

int Cost(int x,int y) {
    int ret = -INF;
    if(dep[x] < dep[y]) swap(x,y);
    for(int i = 19;i >= 0;i--) {
        if(dep[x]-(1 << i) >= dep[y]) {
            ret = max(ret,va[i][x]);
            x = sp[i][x];
        }
    }
    if(x == y) return ret;
    for(int i = 19;i >= 0;i--) {
        if(sp[i][x] != sp[i][y]) {
            ret = max({ret,va[i][x],va[i][y]});
            x = sp[i][x], y = sp[i][y];
        }
    }
    ret = max({ret,va[0][x],va[0][y]});
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        int x,y,val; cin >> x >> y >> val;
        edge.pb({x,y,i-1,val});
    }
    sort(all(edge),cmp);
    for(int i = 1;i <= n;i++) p[i] = i;
    for(Edge i : edge) {
        if(Find(i.x) == Find(i.y)) continue;
        p[p[i.y]] = p[i.x];
        valSum += i.val;
        ted.pb(i);
        issp[i.idx] = 1;
    }
    for(Edge i : ted) {
        v[i.x].pb({i.y,i.val});
        v[i.y].pb({i.x,i.val});
    }
    sp[0][1] = 1;
    dfs(1,-1);
    for(int i = 1;i < 20;i++) {
        for(int j = 1;j <= n;j++) {
            sp[i][j] = sp[i-1][sp[i-1][j]];
            va[i][j] = max(va[i-1][j],va[i-1][sp[i-1][j]]);
        }
    }
    sort(all(edge),cmpIdx);
    for(int i = 0;i < m;i++) {
        if(issp[i]) cout << valSum << '\n';
        else cout << valSum-Cost(edge[i].x,edge[i].y)+edge[i].val << '\n';
    }
}