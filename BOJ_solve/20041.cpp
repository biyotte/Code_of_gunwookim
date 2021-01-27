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
int n,bit;
int sx,sy,X[500005],Y[500005];
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); 
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> X[i] >> Y[i];
    cin >> sx >> sy;
    for(int i = 1;i <= n;i++) {
        int x,y; x = X[i], y = Y[i];
        if(x <= sx&&abs(x-sx) >= abs(y-sy)) bit |= 1;
        if(x >= sx&&abs(x-sx) >= abs(y-sy)) bit |= 2;
        if(y <= sy&&abs(y-sy) >= abs(x-sx)) bit |= 4;
        if(y >= sy&&abs(y-sy) >= abs(x-sx)) bit |= 8;
    }
    if(bit == 15) cout << "NO";
    else cout << "YES";
}