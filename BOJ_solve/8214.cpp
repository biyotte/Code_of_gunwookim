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
int n,m,c[3005];
int d[3005][3005];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        int x,y; cin >> x >> y;
        d[x][y] = d[y][x] = 1;
    }
    int cnt = 0;
    for(int i = 1;i <= n;i++) {
        for(int j = i+1;j <= n;j++) {
            if(!d[i][j]&&!c[i]&&!c[j]) {
                c[i] = c[j] = 1;
            }
        }
    }
    for(int i = 1,cnt = 0;i <= n;i++) {
        if(!c[i]) {
            cout << i << ' ';
            cnt++;
            if(cnt >= n/3) return 0;
        }
    }
}
