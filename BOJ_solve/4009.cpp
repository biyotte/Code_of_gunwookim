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
int n,k,dist[100005];
int p[100005],ans;
int c[100005],st;
int mx[100005],mx2[100005];
vec v[100005];

void find_long(int x,int pr) {
    for(int i : v[x]) {
        if(i == pr) continue;
        dist[i] = dist[x]+1;
        p[i] = x;
        find_long(i,x);
    }
}

int mx_dfs(int x,int pr) {
    int fmx = -INF,smx = -INF;
    for(int i : v[x]) {
        if(i == pr) continue;
        int ret = mx_dfs(i,x);
        if(c[x]&&c[i]) continue;
        ret++;
        if(fmx > ret) smx = max(smx,ret);
        else {
            smx = fmx;
            fmx = ret;
        }
    }
    if(v[x].size() == 1) {
        if(fmx >= 0) exit(-1);
        fmx = 0;
    }
    mx[x] = fmx;
    mx2[x] = smx;
    return fmx;
}

priority_queue <pi> up,down;

int use_dfs() {
    for(int i = st,cnt = 0;i;cnt++, i = p[i]) {
        up.push({max(0,mx[i])-cnt,i});
    }
    int x = st,ret = -INF,cnt = 0;
    while(x) {
        c[x] = 0;
        while(!up.empty()&&!c[up.top().y]) up.pop();
        ret = max({ret,(up.empty() ? -INF : up.top().x+cnt)+max(0,mx[x]),(x == st ? -INF : down.top().x-cnt)+max(0,mx[x]),(up.empty() ? -INF : up.top().x+cnt)+(x == st ? -INF : down.top().x-cnt)});
        down.push({max(0,mx[x])+cnt,x});
        x = p[x];
        cnt++;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k;
    for(int i = 1;i < n;i++) {
        int x,y; cin >> x >> y;
        v[x].pb(y), v[y].pb(x);
    }
    find_long(1,-1);
    int root = 1;
    for(int i = 1;i <= n;i++) {
        if(dist[i] > dist[root]) root = i;
    }
    p[root] = 0;
    dist[root] = 0;
    find_long(root,-1);
    int nx = 1;
    for(int i = 1;i <= n;i++) {
        if(dist[i] >= dist[nx]) nx = i;
    }
    if(k == 1) {
        cout << 2*n-1-dist[nx];
        return 0;
    }
    st = nx;
    while(nx) {
        c[nx] = 1;
        nx = p[nx];
    }
    ans = 2*n-dist[st];
    mx_dfs(root,-1);
    //cout << root << ' ' << st << '\n';
    int no_mx = -INF;
    for(int i = 1;i <= n;i++) no_mx = max(no_mx,max(0,mx[i])+max(0,mx2[i]));
    int use_mx = use_dfs();
    //if(use_mx == no_mx) return 1;
    cout << ans-max(no_mx,use_mx);
}