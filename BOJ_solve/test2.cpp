#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define all(v) v.begin(),v.end()
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
using namespace std;
const long long INF = 1e9;
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
int n,m,down[1005][1005];
char a[1005][1005];
int d[1005][1005];
pi st,en;

struct V {
    int x,y,co;
};
vector <V> v[1005][1005];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        cin >> a[i]+1;
    }
    for(int i = n;i >= 1;i--) {
        for(int j = 1;j <= m;j++) {
            d[i][j] = INF;
            if(a[i][j] == 'X') {
                down[i][j] = down[i+1][j];
                if(j > 1&&a[i][j-1] != 'D') v[i][j-1].pb({down[i][j],j,4});
                if(j < m&&a[i][j+1] != 'D') v[i][j+1].pb({down[i][j],j,4});
            }
            else {
                down[i][j] = i;
                if(j > 1&&a[i][j-1] != 'D') v[i][j-1].pb({i,j,1});
                if(j < m&&a[i][j+1] != 'D') v[i][j+1].pb({i,j,1});
            }
        }
    }
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            if(a[i][j] == 'C') st = {i,j};
            if(a[i][j] == 'E') en = {i,j};
            if(a[i][j] == 'L') {
                v[i][j].pb({i-1,j,2}), v[i-1][j].pb({i,j,2});
            }
        }
    }
    priority_queue <pair<int,pi>> q;
    q.push({0,st});
    d[st.x][st.y] = 0;
    while(!q.empty()) {
        auto Q = q.top(); q.pop();
        int co = -Q.x, x = Q.y.x, y = Q.y.y;
        if(d[x][y] < co) continue;
        if(x == en.x&&y == en.y) {
            cout << co;
            return 0;
        }
        for(V i : v[x][y]) {
            if(d[i.x][i.y] > co+i.co) {
                d[i.x][i.y] = co+i.co;
                q.push({-co-i.co,{i.x,i.y}});
            }
        }
    }
    cout << "dodo sad";
}