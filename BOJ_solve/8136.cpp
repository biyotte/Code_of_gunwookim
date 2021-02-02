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
const long long mod = 1999;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
string s;
int n,len;
map <string,int> ma;

vec getPi(string ss) {
    int m = ss.size(), j = 0;
    vec p(m,0);
    for(int i = 1;i < m;i++) {
        while(j&&ss[i]^ss[j]) j = p[j-1];
        if(ss[i] == ss[j]) p[i] = ++j;
    }
    return p;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for(int j = 1;j <= n;j++) {
        cin >> len >> s;
        auto p = getPi(s);
        string pu;
        if(p[len-1]&&len % (len-p[len-1]) == 0) {
            for(int i = 0;i < len-p[len-1];i++) pu += s[i];
        }
        else for(int i = 0;i < len;i++) pu += s[i];
        ma[pu]++;
    }
    ll ans = 0;
    for(auto i : ma) ans += 1LL*i.y*i.y;
    cout << ans;
}