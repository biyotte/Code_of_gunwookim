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
int n,m,k;
int c[5005],cost[5005][5005];
vecpi v[5005];
vecpi qq[20];
priority_queue <pair <ll,int>> q;
ll ans = llINF,d[5005];

void dij(vec st,vec en) {
    for(int i = 1;i <= n;i++) d[i] = llINF;
    memset(c,0,sizeof(c));
    for(int i : st) q.push({-v[1][i].y,v[1][i].x});
    while(!q.empty()) {
        ll x = -q.top().x; int now = q.top().y; q.pop();
        if(c[now]) continue;
        c[now] = 1, d[now] = x;
        for(pi i : v[now]) if(i.x^1) q.push({-x-i.y,i.x});
    }
    for(int i : en) ans = min(ans,d[v[1][i].x]+cost[v[1][i].x][1]);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        int x,y,z,zz;
        cin >> x >> y >> z >> zz;
        v[x].pb({y,z});
        v[y].pb({x,zz});
        cost[x][y] = z, cost[y][x] = zz;
    }
    k = v[1].size();
    qq[0].pb({0,k-1});
    for(int b = 0;b < 19;b++) {
        vec st,en;
        for(pi i : qq[b]) {
            if(i.x == i.y) continue;
            int mid = (i.x + i.y) >> 1;
            qq[b+1].pb({i.x,mid}), qq[b+1].pb({mid+1,i.y});
            for(int j = i.x;j <= mid;j++) st.pb(j);
            for(int j = mid+1;j <= i.y;j++) en.pb(j);
        }
        dij(st,en), dij(en,st);
    }
    cout << ans;
}
