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
//const int mod = 1e9+7;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,m,mod;
int area[10005];
int d[2][10005];
vec p;

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> mod;
    p.pb(0);
    for(int i = 2;i <= 10000;i++) {
        if(area[i]) continue;
        p.pb(i);
        for(int j = i*i;j <= 10000;j += i) area[j] = 1;
    }
    m = p.size();
    for(int i = 0;i <= n;i++) d[0][i] = 1;
    for(int i = 1;i < m;i++) {
        for(int j = 0;j <= n;j++) {
            ll mpow = p[i];
            d[i%2][j] = d[(i-1)%2][j];
            while(mpow <= j) {
                d[i%2][j] = (d[i%2][j]+(mpow*d[(i-1)%2][j-mpow])%mod)%mod;
                mpow *= p[i];
            }
        }
    }
    cout << d[(m-1)%2][n];
}
