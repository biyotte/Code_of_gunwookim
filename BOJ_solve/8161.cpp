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
const long long llINF = 3e18+10;
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
int n,mn,mx;
int p[1000005];
int d[1000005][2];
int dp[1000005][2];
int leaf;
bool iscyc[1000005],c[1000005];
vec v[1000005];
int cyc[1000005],sz;

void getCycle(int x) {
    if(c[x]) {
        cyc[sz++] = x;
        iscyc[x] = 1;
        for(int i = p[x];i != x;i = p[i]) iscyc[i] = 1, cyc[sz++] = i;
        return;
    }
    c[x] = 1;
    getCycle(p[x]);
}

void dfs(int x) {
    if(!iscyc[x]||p[x] == x) leaf = 1;
    c[x] = 1;
    bool cn = (p[x] == x);
    d[x][0] = d[x][1] = 0;
    for(int i : v[x]) {
        if(iscyc[i]) continue;
        dfs(i);
        cn = 1;
        d[x][0] = min(d[x][0]+d[i][1],INF);
        d[x][1] = min(d[x][1]+min(d[i][0],d[i][1]),INF);
    }
    d[x][1] = min(INF,d[x][1]+1);
    if(!cn) d[x][0] = 0, d[x][1] = INF;
    if(!iscyc[x]) mx += cn;
}

void Comp(int x) {
    leaf = 0;
    sz = 0;
    getCycle(x);
    int i;
    for(i = 0;i < sz;i++) {
        dfs(cyc[i]);
        if(d[cyc[i]][1] == INF) d[cyc[i]][1] = 1;
    }
    dp[0][0] = d[cyc[0]][0], dp[0][1] = INF;
    for(i = 1;i < sz;i++) {
        dp[i][0] = min(INF,dp[i-1][1]+d[cyc[i]][0]);
        dp[i][1] = min(INF,min(dp[i-1][0],dp[i-1][1])+d[cyc[i]][1]);
    }
    int ret = dp[sz-1][1];
    dp[0][0] = INF, dp[0][1] = d[cyc[0]][1];
    for(i = 1;i < sz;i++) {
        dp[i][0] = min(INF,dp[i-1][1]+d[cyc[i]][0]);
        dp[i][1] = min(INF,min(dp[i-1][0],dp[i-1][1])+d[cyc[i]][1]);
    }
    ret = min({ret,dp[sz-1][0],dp[sz-1][1]});
    mn += ret;
    mx += (leaf ? sz : sz-1);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> p[i], v[p[i]].pb(i);
    for(int i = 1;i <= n;i++) {
        if(!c[i]) Comp(i);
    }
    cout << mn << ' ' << mx;
}