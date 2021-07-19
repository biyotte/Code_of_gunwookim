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
const long long mod = 998244353;
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
int n,m,p[10005],sz[10005];
ll ans;

struct E {
    int x,y;
    ll val;
};
vector <E> vv,ve;

bool cmp(E x,E y) {
    return x.val < y.val;
}

int Find(int x) {return (p[x]^x ? p[x] = Find(p[x]) : x);}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        int x,y,z; cin >> x >> y >> z;
        vv.pb({x,y,z});
    }
    sort(all(vv),cmp);
    vector <E> v;
    for(int i = 1;i <= n;i++) p[i] = i;
    reverse(all(vv));
    int la;
    for(E i : vv) {
        int x = i.x, y = i.y;
        if(Find(x) == Find(y)) continue;
        p[p[y]] = p[x];
        la = i.val;
    }
    reverse(all(vv));
    for(int i = 1;i <= n;i++) p[i] = i;
    for(E i : vv) {
        int x = i.x, y = i.y;
        if(Find(x) == Find(y)||i.val < la) continue;
        p[p[y]] = p[x];
        v.pb(i);
    }
    reverse(all(v));
    for(int i = 1;i <= n;i++) p[i] = i, sz[i] = 1;
    for(E i : v) {
        int x = i.x, y = i.y;
        ans += i.val*sz[Find(x)]*sz[Find(y)];
        sz[p[x]] += sz[p[y]];
        p[p[y]] = p[x];
    }
    cout << ans;
}
