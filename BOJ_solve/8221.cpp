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
const long long llINF = 1e18;
const int mod = 1e9+7;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int t[1000005];
int n,nx[1000005];
char s[1000005],s2[1000005];
int sz[26];
vec wi[26];

void update(int x,int val) {
    for(;x <= n;x += x&-x) {
        t[x] += val;
    }
}

int query(int x) {
    int res = 0;
    for(;x;x -= x&-x) res += t[x];
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> s+1 >> s2+1;
    for(int i = 1;i <= n;i++) {
        wi[s2[i]-'A'].pb(i);
    }
    for(int i = 0;i < 26;i++) sz[i] = 0;
    for(int i = 1;i <= n;i++) {
        nx[i] = wi[s[i]-'A'][sz[s[i]-'A']++];
    }
    ll ans = 0;
    for(int i = 1;i <= n;i++) {
        ans += i-query(nx[i])-1;
        update(nx[i],1);
    }
    cout << ans;
}
