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
const long long mod = 998244353;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n;
vec v[100005],no[2];
int c[100005],c2[100005];
ll ans,g,sum,tk,cnt[2];

struct Edge {int x,y,z;};
vector <Edge> edge,q;

bool cmp(Edge x,Edge y) {
    return x.z > y.z;
}

void f(int x,int y) {
    if(c[x]||c2[x] == g) return;
    c2[x] = g;
    cnt[y]++;
    no[y].pb(x);
    q.pb({y,x,0});
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); 
    cin >> n, sum = n;
    for(int i = 1;i < n;i++) {
        int x,y,z; cin >> x >> y >> z;
        v[x].pb(y), v[y].pb(x);
        edge.pb({x,y,z});
    }
    sort(all(edge),cmp);
    for(auto i : edge) {
        int x = i.x, y = i.y, z = i.z;
        if(c[x]||c[y]) continue;
        cnt[0] = cnt[1] = 0;
        no[0].clear(), no[1].clear();
        g++;
        q.clear();
        f(x,0), f(y,1);
        for(int i = 0;1;i++) {
            if(!cnt[0]||!cnt[1]) break;
            Edge tmp = q[i];
            if(tmp.z >= (int)v[tmp.y].size()) cnt[tmp.x]--;
            else {
                f(v[tmp.y][tmp.z],tmp.x);
                q.pb({tmp.x,tmp.y,tmp.z+1});
            }
        }
        if((int)no[0].size() > (int)no[1].size()) swap(no[0],no[1]);
        int lsz = (int)no[0].size(), rsz = sum-lsz;
        if(lsz+tk >= rsz-1) {
            ans += 1LL*(sum-tk-1)*(1LL << z);
            break;
        }
        else {
            ans += 2LL*lsz*(1LL << z);
            tk += lsz, sum -= lsz;
            for(int i : no[0]) c[i] = 1;
        }
    }
    cout << ans;
}
(N * N * 2 + N * 30 + 38) * N
