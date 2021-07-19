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
int n,m,k;
ll d[1000005],s[1000005];

// not solved

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m >> k;
    d[0] = 1;
    for(int i = 1;i <= k;i++) {
        d[i] = d[i-1]*m%mod;
        s[i] = (s[i-1]+d[i])%mod;
    }
    for(int i = k+1;i <= n;i++) {
        d[i] = (s[i-1]-s[i-k-1]+mod)%mod*m%mod;
        s[i] = (s[i-1]+d[i])%mod;
    }
    cout << d[n];
}
