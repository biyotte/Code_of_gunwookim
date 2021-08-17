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
int c[2000005],ans;
int n,k,End = 2000002;
int p[2000005];

int go(int x) {
    if(c[x]||x >= End) return 0;
    c[x] = 1;
    if(p[x+1]) return go(p[x+1])+1;
    return go(x+1);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        int x,y; cin >> x >> y;
        p[x] = y, p[y] = x;
    }
    ans = go(0);
    vec v;
    for(int i = 1;i < End;i++) if(!c[i]) v.pb(go(i));
    sort(all(v));
    reverse(all(v));
    for(int i = 0;i < v.size()&&i < k;i++) ans += v[i]+2;
    k -= min((int)v.size(),k);
    cout << ans+(k/2)*4+k%2;
}