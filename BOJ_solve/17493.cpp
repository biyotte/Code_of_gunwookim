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
const long long llINF = 1e16;
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
int n,m,c[200005];
ll d[200005][3];
vec v[200005];

/*
d[i][j] : i노드에서 j인 경우에서 최소 개수
j=0 : 자식 중 한명이 전단지
j=1 : 내 자신이 전단지
j=2 : 부모가 전단지

d[i][0] = d[v][1]+SUM( min(d[j][0],d[j][1]) ) ;
d[i][1] += min(d[j][0],d[j][1],d[j][2]);
d[i][2] += min(d[j][0],d[j][1]);
*/

void go(int x,int pr) {
    c[x] = 1;
    ll sum = 0;
    for(int i : v[x]) {
        if(i == pr) continue;
        go(i,x);
        d[x][1] += min({d[i][0],d[i][1],d[i][2]});
        d[x][2] += min({d[i][0],d[i][1]});
        sum += min({d[i][0],d[i][1]});
    }
    d[x][0] = INF;
    d[x][1]++;
    for(int i : v[x]) {
        if(i == pr) continue;
        d[x][0] = min(d[x][0],sum-min(d[i][0],d[i][1])+d[i][1]);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        int x,y; cin >> x >> y;
        v[x].pb(y), v[y].pb(x);
    }
    int ans = 0;
    for(int i = 1;i <= n;i++) {
        if(c[i]) continue;
        go(i,-1);
        ans += min(d[i][0],d[i][1]);
    }
    cout << ans;
}