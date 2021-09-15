#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast")
#pragma gcc optimize("unroll-loops")
using namespace std;
const int INF = 1e9;
const int TMX = 1 << 18;
const long long llINF = 1e18;
const long long mod = 1e9+7;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,m,k;
bool hole[15][25];
char a[15][25],na[15][25];
int di[15][25];
int nx[4] = {1,-1,0,0}, ny[4] = {0,0,1,-1};
int ans,sx,sy,ch,stx,sty;
char an[15][25];

void Change(int dist) {
    if(ans < dist) {
        ch = 1;
        ans = dist;
        cout << ans << '\n';
        if(!stx) cout << "0 " << sty*2-1 << '\n';
        if(!sty) cout << stx*2-1 << " 0" << '\n';
        if(stx == n+1) cout << stx*2-2 << ' ' << sty*2-1 << '\n';
        if(sty == m+1) cout << stx*2-1 << ' ' << sty*2-2 << '\n';
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= m;j++) {
                if(a[i][j] == '?') cout << ".";
                else cout << (an[i][j] = a[i][j]);
            }
            cout << '\n';
        }
        cout << "\n\n";
    }
}

void dfs(int x,int y,int dir,int dist) {
    if(hole[x][y]) Change(dist-2);
    if(a[x][y] == '?') {
        a[x][y] = '.';
        dfs(x+nx[dir],y+ny[dir],dir,dist+2);
        if(dir < 2) a[x][y] = '-';
        else a[x][y] = '|';
        Change(dist+1);
        a[x][y] = '/';
        int ndir = 3-dir;
        dfs(x+nx[ndir],y+ny[ndir],ndir,dist+2);
        a[x][y] = '\\';
        ndir = dir^2;
        dfs(x+nx[ndir],y+ny[ndir],ndir,dist+2);
        a[x][y] = '?';
    }
    else if(a[x][y] == '.') dfs(x+nx[dir],y+ny[dir],dir,dist+2);
    else if(a[x][y] == '\\') {
        int ndir = dir^2;
        dfs(x+nx[ndir],y+ny[ndir],ndir,dist+2);
    }
    else if(a[x][y] == '/') {
        int ndir = 3-dir;
        dfs(x+nx[ndir],y+ny[ndir],ndir,dist+2);
    }
    else if(a[x][y] == '@') return;
    else if(a[x][y] == '-') {
        if(dir < 2) Change(dist+1);
    }
    else {
        if(dir >= 2) Change(dist+1);
    }
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i]+1;
    for(int i = 0;i <= n+1;i++) a[i][0] = a[i][m+1] = '@';
    for(int i = 0;i <= m+1;i++) a[0][i] = a[n+1][i] = '@';
    for(int i = 0;i < n+1;i++) {
        for(int j = 0;j <= m+1;j++) na[i][j] = a[i][j];
    }
    cin >> k;
    for(int i = 1;i <= k;i++) {
        int x,y; cin >> x >> y;
        swap(x,y);
        if(!x) hole[0][y/2+1] = 1, di[0][y/2+1] = 0;
        if(x == 2*n) hole[n+1][y/2+1] = 1, di[n+1][y/2+1] = 1;
        if(!y) hole[x/2+1][0] = 1, di[x/2+1][0] = 2;
        if(y == 2*m) hole[x/2+1][m+1] = 1, di[x/2+1][m+1] = 3;
    }
    vecpi v;
    for(int i = 0;i <= n+1;i++) {
        for(int j = 0;j <= m+1;j++) {
            if(hole[i][j]) {
                v.pb({i,j});
            }
        }
    }
    int i = 10, j = 1;
    ch = 0;
    cout << "Start : " << i << ' ' << j << '\n';
    stx = i, sty = j;
    dfs(i+nx[di[i][j]],j+ny[di[i][j]],di[i][j],2);
    if(ch) sx = i, sy = j;
    cout << ans << '\n';
    swap(sx,sy);
    if(!sx) cout << "0 " << sy*2-1 << '\n';
    if(!sy) cout << sx*2-1 << " 0" << '\n';
    if(sx == n+1) cout << sx*2-2 << ' ' << sy*2-1 << '\n';
    if(sy == m+1) cout << sx*2-1 << ' ' << sy*2-2 << '\n';
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            if(an[i][j] == '?') an[i][j] = '.';
            cout << an[i][j];
        }
        cout << '\n';
    }
}
