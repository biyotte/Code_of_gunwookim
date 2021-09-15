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
int n,m,c[2005];
pi a[2005];
int path[2005];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i].x, a[i].y = i;
    int la = 0;
    do {
        memset(c,0,sizeof(c));
        int g = 1;
        for(int idx = la;1;g++) {
            idx = (idx+m-1)%n+1;
            if(c[idx]) break;
            path[g] = idx;
            c[idx] = 1;
        }
        g--;
        int mn = 1;
        for(int i = 1;i <= g;i++) {
            if(a[path[mn]].x > a[path[i]].x) mn = i;
        }
        int val = a[path[mn]].x;
        for(int i = 1;i <= g;i++) a[path[i]].x -= val-(i > mn);
        for(int i = path[mn]+1;i <= n;i++) a[i-1] = a[i];
        la = path[mn]-1;
    }while(--n > 1);
    cout << a[1].y;
}
