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
int n,sz[100005];
int p[100005];

struct Edge {
    int x,y,z;
};
vector <Edge> v;

bool cmp(Edge x,Edge y) {
    return x.z > y.z;
}

int Find(int x) {return (x^p[x] ? p[x] = Find(p[x]) : x);}

void merge(int x,int y) {
    x = Find(x), y = Find(y);
    if(x == y) return;
    p[y] = x, sz[x] += sz[y];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for(int i = 1;i < n;i++) {
        int x,y,z; cin >> x >> y >> z;
        v.pb({x,y,z});
    }
    sort(all(v),cmp);
    for(int i = 1;i <= n;i++) p[i] = i, sz[i] = 1;
    ll ans = 0;
    for(Edge i : v) {
        merge(i.x,i.y);
        ans = max(ans,1LL*(sz[Find(i.x)]-1)*i.z);
    }
    cout << ans;
}
 