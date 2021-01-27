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
const long long llINF = 1e18;
const int mod = 1e9+7;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,m,sx,sy,ex,ey;
char a[505][505];
int nd[4][505][505],c[505][505];
int nx[4] = {1,0,-1,0}, ny[4] = {0,1,0,-1};
priority_queue <pair<int,pi>> q;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        cin >> a[i]+1;
        for(int j = 1;j <= m;j++) {
            if(a[i][j] == 'C') sx = i, sy = j;
            if(a[i][j] == 'F') ex = i, ey = j;
        }
    }
    for(int i = 1;i <= m;i++) {
        int la = -2;
        for(int j = 1;j <= n;j++) {
            if(a[j][i] == '#') la = j;
            nd[2][j][i] = la+1;
        }
    }
    for(int i = 1;i <= m;i++) {
        int la = 0;
        for(int j = n;j >= 1;j--) {
            if(a[j][i] == '#') la = j;
            nd[0][j][i] = la-1;
        }
    }
    for(int i = 1;i <= n;i++) {
        int la = 0;
        for(int j = 1;j <= m;j++) {
            if(a[i][j] == '#') la = j;
            nd[3][i][j] = la+1;
        }
    }
    for(int i = 1;i <= n;i++) {
        int la = -2;
        for(int j = m;j >= 1;j--) {
            if(a[i][j] == '#') la = j;
            nd[1][i][j] = la-1;
        }
    }
    q.push({0,{sx,sy}});
    while(!q.empty()) {
        auto tmp = q.top(); q.pop();
        int dist = -tmp.x;
        int x = tmp.y.x, y = tmp.y.y;
        if(c[x][y]) continue;
        c[x][y] = 1;
        if(ex == x&&ey == y) {
            cout << dist;
            return 0;
        }
        int dx,dy,isnear = 0;
        for(int i = 0;i < 4;i++) {
            dx = x+nx[i], dy = y+ny[i];
            if(a[dx][dy] == '#') isnear = 1;
        }
        for(int i = 0;i < 4;i++) {
            dx = x+nx[i], dy = y+ny[i];
            if(a[dx][dy] == '#'||dx < 1||dx > n||dy < 1||dy > m) continue;
            q.push({-dist-1,{dx,dy}});
            for(int j = 0;j < 4;j++) {
                if(nd[j][x][y] != -1&&nd[i][x][y] != -1) {
                    int di;
                    if(j % 2) di = abs(y-nd[j][x][y]);
                    else di = abs(x-nd[j][x][y]);
                    if(i % 2) q.push({-dist-di-1,{x,nd[i][x][y]}});
                    else q.push({-dist-di-1,{nd[i][x][y],y}});
                }
            }
        }
    }
    cout << "nemoguce";
}
