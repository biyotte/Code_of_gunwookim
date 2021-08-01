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
int n;
ll canGo[2005],dist[2005][2005];
vector <pl> sv[2005];
vec v[2005];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> canGo[i];
    for(int i = 1;i < n;i++) {
        int x,y; ll val; cin >> x >> y >> val;
        sv[x].pb({y,val}), sv[y].pb({x,val});
    }
    queue <pl> q;
    for(int x = 1;x <= n;x++) {
        for(int i = 1;i <= n;i++) dist[x][i] = llINF;
        q.push({dist[x][x] = 0,x});
        while(!q.empty()) {
            pl now = q.top(); q.pop();
            if(dist[x][now.y] != llINF) continue;
            dist[x][now.y] = now.x;
            if(now.x^x&&dist[x][now.y] <= canGo[x]) v[x].pb(now.y);
            for(pl i : sv[now.y]) q.push({now.x-i.y,i.x});
        }
    }
}