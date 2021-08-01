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
const long long llINF = 3e18+10;
const long long mod = 1e9+7;
const long long hashmod = 100003;
const int MAXN = 100000;
const int MAXM = 20000000;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,a[300005];
ll d[300005];
char s[300005];
vec w,h;
vecpi v[300005];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> s+1;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        if(s[i] == 'W') w.pb(i);
        else h.pb(i);
    }
    for(int i = 1;i <= n;i++) {
        if(s[i] == 'W') {
            int it = lower_bound(all(h),i)-h.begin();
            if(!it||it == h.size()) continue;
            v[h[it]].pb({h[it-1],a[i]});
        }
        else {
            int it = lower_bound(all(w),i)-w.begin();
            if(!it||it == w.size()) continue;
            v[w[it]].pb({w[it-1],a[i]});
        }
    }
    for(int i = 1;i <= n;i++) {
        d[i] = d[i-1];
        for(pi j : v[i]) {
            d[i] = max(d[i],d[j.x]+j.y);
        }
    }
    cout << d[n];
}