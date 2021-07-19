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
int n,mx,cu[1000005],dn[1000005];
int a[1000005],p[1000005],now[1000005];
vec rv,d[1000005],c[1000005],Lmx[1000005],Rmx[1000005];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i], rv.pb(a[i]);
    sort(all(rv)), rv.erase(unique(all(rv)),rv.end());
    mx = rv.size();
    for(int i = 1;i <= n;i++) {
        a[i] = lower_bound(all(rv),a[i])-rv.begin()+1;
    }
    n = unique(a+1,a+n+1)-a-1;
    cu[1] = 1;
    for(int i = 1;i < n;i++) {
        if(a[i] > a[i+1]) cu[i+1] = 1;
    }
    for(int i = 1;i <= n;i++) {
        cu[i] += cu[i-1];
        c[a[i]].pb(cu[i]);
    }

    for(int i = 1;i <= mx;i++) {
        d[i].resize(c[i].size(),0);
        Lmx[i].resize(c[i].size(),0);
        Rmx[i].resize(c[i].size(),0);
        for(int j = 0;j < c[i-1].size();j++) {
            p[c[i-1][j]] = j, now[c[i-1][j]] = i;
        }
        int cnt = 0, chh;
        for(int j = 0;j < c[i].size();j++) {
            d[i][j] = dn[i-1];
            if(now[c[i][j]] != i) continue;
            cnt++, chh = j;
            d[i][j] = max({d[i][j],(p[c[i][j]] ? Lmx[i-1][p[c[i][j]]-1] : 0),(p[c[i][j]] == c[i-1].size()-1 ? 0 : Rmx[i-1][p[c[i][j]]+1])})+1;
        }
        if(cnt == 1&&c[i-1].size() == 1) {
            d[i][chh] = max(dn[i-1],Lmx[i-1].back())+1;
        }
        if(i > 1) dn[i] = max(dn[i-1],Lmx[i-1][c[i-1].size()-1]);
        for(int j = 0;j < c[i].size();j++) {
            Lmx[i][j] = max((j ? Lmx[i][j-1] : 0),d[i][j]);
        }
        for(int j = (int)c[i].size()-1;j >= 0;j--) {
            Rmx[i][j] = max((j == (int)c[i].size()-1 ? 0 : Rmx[i][j+1]),d[i][j]);
        }
    }
    cout << n-1-max(dn[mx],Lmx[mx][c[mx].size()-1]);
}