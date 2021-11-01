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
const long long llINF = 2e18+5;
const long long mod = 1e9+7;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
typedef unsigned long long ull;
int n,m,nope,c[150005];
vecpi v[150005];
map <pi,int> M;
vector <pair<pi,pi>> ans;

// -1 : pv -> x (in)
// 1 : x -> pv (out)

pi dfs(int x) {
    c[x] = 1;
    vec in,out;
    for(pi i : v[x]) {
        if(c[i.x]) continue;
        pi R = dfs(i.x);
        int op = R.x, node = R.y;
        int Out = 0, In = 0;
        if(i.y & 1) Out = 1, out.pb(i.x);
        if(i.y & 2) In = 1, in.pb(i.x);

        if(op == -1) {
            if(!In) nope = 1;
            else {
                ans.pb({{node,i.x},{i.x,x}});
                in.pop_back();
            }
        }
        if(op == 1) {
            if(!Out) nope = 1;
            else {
                ans.pb({{x,i.x},{i.x,node}});
                out.pop_back();
            }
        }
    }
    int sz = min(in.size(),out.size());
    while(sz--) {
        ans.pb({{in.back(),x},{x,out.back()}});
        in.pop_back(), out.pop_back();
    }
    
    if(in.size() > 1) nope = 1;
    if(out.size() > 1) nope = 1;
    pi ret = {0,0};
    if(in.size()) ret = {-1,in[0]};
    if(out.size()) ret = {1,out[0]};
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        int x,y; cin >> x >> y;
        M[{x,y}] |= 1, M[{y,x}] |= 2;
    }
    for(auto i : M) {
        v[i.x.x].pb({i.x.y,i.y});
    }
    for(int i = 1;i <= n;i++) {
        if(!c[i]) {
            pi ret = dfs(i);
            if(ret.x) nope = 1;
        }
    }
    if(nope) {
        cout << "No";
        return 0;
    }
    cout << "Yes\n";
    for(auto i : ans) {
        cout << i.x.x << ' ' << i.x.y << ' ' << i.y.x << ' ' << i.y.y << '\n'; 
    }
}
