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
int n,m,k,sz,szk,nope[100005];
vecpi g;
vec go,l,r,mn,mx;

bool cmp(pi x,pi y) {
    if(x.y == y.y) return x.x > y.x;
    return x.y < y.y;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k >> m;
    for(int i = 1;i <= m;i++) {
        int x,y,z; cin >> x >> y >> z;
        if(z) g.pb({x,y});
        else nope[x]++, nope[y+1]--;
    }
    for(int i = 1;i <= n;i++) {
        nope[i] += nope[i-1];
        if(!nope[i]) go.pb(i);
    }
    sort(all(g),cmp); sz = g.size();
    for(int i = 0,la = 0,lp = 0,rp = 0;i < sz;i++) {
        if(g[i].x > la) {
            la = g[i].x;
            for(;go[lp] < g[i].x;lp++);
            for(;rp < go.size()&&go[rp] <= g[i].y;rp++);
            if(lp == go.size()||rp == 0) return -1;
            mn.pb(go[lp]), mx.pb(go[rp-1]);
        }
    }
    szk = mn.size();
    for(int i = 0,la = 0;i < szk;i++) {
        if(la < mn[i]) {
            la = mx[i];
            l.pb(la);
        }
    }
    for(int i = szk-1,la = INF;i >= 0;i--) {
        if(la > mx[i]) {
            la = mn[i];
            r.pb(la);
        }
    }
    int have = 0;
    if(l.size() != r.size()) return -1;
    if(go.size() == k) {
        for(int i : go) cout << i << '\n';
        return 0;
    }
    if(l.size() == k) {
        for(int i = 0;i < l.size();i++) {
            if(l[i] == r[l.size()-1-i]) have = 1, cout << l[i] << '\n';
        }
        if(!have) cout << -1;
        return 0;
    }
    for(int i = 0;i < szk;i++) {
        if(mn[i] == mx[i]) have = 1, cout << mn[i] << '\n';
    }
    if(!have) cout << -1;
}