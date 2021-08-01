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
const long long llINF = 1e18+10;
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
int n,k;
int cost[1005][1005];
int d[1005][2][1005],sz[1005];
int t[2][1005];
vec rv[1005],v[1005],ans;

struct Path {
    int nxx,ci,coi,nx,cj,coj;
};
vector <Path> p[1005][2][1005];

void pre_dfs(int x,int pr) {
    for(int i : rv[x]) {
        if(i == pr) continue;
        v[x].pb(i);
        pre_dfs(i,x);
    }
}

void dfs(int x) {
    sz[x] = 1;
    for(int i = 0;i <= n;i++) d[x][0][i] = d[x][1][i] = INF;
    d[x][0][0] = d[x][1][1] = 0;
    for(int i = 0;i <= n;i++) {
        p[x][0][i].resize((int)v[x].size());
        p[x][1][i].resize((int)v[x].size());
    }
    for(int idx = 0;idx < v[x].size();idx++) {
        int nx = v[x][idx];
        dfs(nx);
        for(int i = 0;i <= sz[x]+sz[nx];i++) t[0][i] = t[1][i] = INF;
        for(int i = 0;i <= sz[x]*2+1;i++) {
            for(int j = 0;j <= sz[nx]*2+1;j++) {
                int ci = i % 2, coi = i/2, cj = j % 2, coj = j/2;
                if(t[ci][coi+coj] > d[x][ci][coi]+d[nx][cj][coj]+(ci^cj ? 0 : cost[x][nx])) {
                    t[ci][coi+coj] = d[x][ci][coi]+d[nx][cj][coj]+(ci^cj ? 0 : cost[x][nx]);
                    p[x][ci][coi+coj][idx] = {idx-1,ci,coi,nx,cj,coj};
                }
            }
        }
        sz[x] += sz[nx];
        for(int i = 0;i <= sz[x];i++) d[x][0][i] = t[0][i], d[x][1][i] = t[1][i];
    }
}

void go(int x,int y,int z) {
    if(y) ans.pb(x);
    for(int i = (int)v[x].size()-1;i >= 0;i--) {
        int nx = v[x][i];
        auto now = p[x][y][z][i];
        go(nx,now.cj,now.coj);
        y = now.ci, z = now.coi;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k;
    for(int i = 1;i < n;i++) {
        int x,y,z; cin >> x >> y >> z;
        rv[x].pb(y), rv[y].pb(x);
        cost[x][y] = cost[y][x] = z; 
    }
    pre_dfs(1,-1);
    dfs(1);
    int idx = (d[1][1][k] < d[1][0][k]);
    go(1,idx,k);
    cout << d[1][idx][k] << '\n';
    sort(all(ans));
    for(int i : ans) cout << i << ' ';
}