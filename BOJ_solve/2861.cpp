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
int n,m,nam[200005],ans;
int c[200005],iscyc[200005];
pi a[200005];
vec v[200005];
vec cyc[200005];

void dfs_out(int x) {
    if(iscyc[x]||c[x]) return;
    c[x] = 1;
    for(int i : v[x]) dfs_out(i);
    ans += max(0,a[x].y-nam[x]);
    nam[a[x].x] += a[x].y;
}

void dfs_in(int st) {
    if(!iscyc[st]) return;
    int mn = INF*2+1,wi,co = iscyc[st];
    for(int i : cyc[co]) {
        iscyc[i] = 0;
        int tmp = max(a[i].y-nam[i],0);
        if(tmp < mn) {
            mn = tmp;
            wi = i;
        }
    }
    ans += mn;
    nam[a[wi].x] += a[wi].y;
    for(int j = a[wi].x;j^wi;j = a[j].x) {
        ans += max(0,a[j].y-nam[j]);
        nam[a[j].x] += a[j].y;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i].x >> a[i].y;
        v[a[i].x].pb(i);
    }
    for(int i = 1;i <= n;i++) {
        int j;
        for(j = i;!c[j];j = a[j].x) c[j] = i;
        if(c[j] != i) continue;
        m++;
        for(;!iscyc[j];j = a[j].x) {
            iscyc[j] = m;
            cyc[m].pb(j);
        }
    }
    memset(c,0,sizeof(c));
    for(int i = 1;i <= n;i++) dfs_out(i);
    for(int i = 1;i <= n;i++) dfs_in(i);
    cout << ans;
}
