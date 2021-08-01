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
int n,m,k,S,T,c[2005];
int fp[2005],rvfp[2005];
int p[2005];
vecpi v[2005];
vec ds,dt,Add[2005],Del[2005];

struct Edge {
    int x,y,val;
}edge[100005];

vec Dijk(int x) {
    vec ret(n+1,INF);
    ret[x] = 0;
    memset(c,0,sizeof(c));
    priority_queue <pi> q;
    q.push({0,x});
    while(!q.empty()) {
        pi x = q.top(); q.pop();
        if(c[x.y]) continue;
        c[x.y] = 1;
        ret[x.y] = -x.x;
        for(pi i : v[x.y]) q.push({x.x-i.y,i.x});
    }
    return ret;
}

void dfs(int x) {
    c[x] = 1;
    for(pi i : v[x]) {
        if(!c[i.x]&&!rvfp[i.x]&&ds[x]+i.y == ds[i.x]) {
            p[i.x] = p[x];
            dfs(i.x);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m >> S >> T;
    for(int i = 1;i <= m;i++) {
        int x,y,z; cin >> x >> y >> z;
        v[x].pb({y,z}), v[y].pb({x,z});
        edge[i] = {x,y,z};
    }
    cin >> k;
    for(int i = 1;i <= k;i++) cin >> fp[i], rvfp[fp[i]] = i;
    ds = Dijk(S), dt = Dijk(T);
    memset(c,0,sizeof(c));
    for(int i = 1;i <= k;i++) {
        p[fp[i]] = fp[i];
        dfs(fp[i]);
    }
    priority_queue <int> add,del;
    for(int i = 1;i <= m;i++) {
        int x = edge[i].x, y = edge[i].y, val = edge[i].val;
        if(rvfp[p[x]] > rvfp[p[y]]) swap(x,y);
        if(rvfp[p[x]] < rvfp[p[y]]&&!(p[x] == x&&p[y] == y&&rvfp[x]+1 == rvfp[y])) {
            int cost = ds[x]+val+dt[y];
            Add[rvfp[p[x]]].pb(cost), Del[rvfp[p[y]]].pb(cost);
        }
    }
    for(int i = 1;i < k;i++) {
        for(int j : Add[i]) add.push(-j);
        for(int j : Del[i]) del.push(-j);
        while(!add.empty()&&!del.empty()&&add.top() == del.top()) add.pop(), del.pop();
        cout << (add.empty() ? -1 : -add.top()) << '\n';
    }
}
