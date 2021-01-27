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
const long long llINF = 5e18;
const long long mod = 1e9+7;
const long long hmod1 = 1e9+409;
const long long hmod2 = 1e9+433;
const long long base = 257;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,Q;
ll f[1000005];
vec su[1000005];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> n >> Q;
    f[0] = 0, f[1] = 1;
    for(int i = 2;i <= n;i++) f[i] = (f[i-2]+f[i-1])%mod;
    while(Q--) {
        int l,r; cin >> l >> r;
        su[l].pb(1), su[r+1].pb(-(r-l+2));
    }
    ll a = 0,b = 0;
    for(int i = 1;i <= n;i++) {
        for(int j : su[i]) {
            if(j < 0) a -= f[-j-1], b -= f[-j];
            else b++;
        }
        a = (a%mod+mod)%mod;
        b = (b%mod+mod)%mod;
        cout << b << ' ';
        swap(a,b); b += a;
    }
}
