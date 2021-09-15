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
int n,ch,is[300005],c[300005];
vec v[300005];

void dfs(int x,int pr) {
    if(c[x]) return;
    c[x] = 1;
    for(int i : v[x]) {
        if(i^pr) {
            if(c[i]) ch = 1;
            dfs(i,x);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for(int i = 1;i < n;i++) {
        int x,y,z; cin >> x >> y >> z;
        if(!z) v[x].pb(y), v[y].pb(x);
        else is[y]++;
    }
    for(int i = 1;i <= n;i++) {
        if(is[i] >= 2||(is[i]&&c[i])) ch = 1;
        if(is[i]) dfs(i,0);
    }
    int ans = 0;
    for(int i = 1;i <= n;i++) {
        if(!c[i]) ans++;
    }
    if(ch) ans = 0;
    cout << ans;
}