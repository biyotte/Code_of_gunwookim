#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define sz(v) v.size()
#define all(v) v.begin(),v.end()
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
using namespace std;
const int INF = 1e9;
const int TMX = 1 << 18;
const long long llINF = 1e18+10;
const long long mod = 998244353;
const long long hmod1 = 1e9+409;
const long long hmod2 = 1e9+433;
const long long base = 257;
const int MAXN = 100000;
const int MAXM = 1000000;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int a[10];
int ans = 0;

void go(int x) {
    if(x == 8) {
        for(int i = 1;i <= 5;i++) {
            if(max({a[i],a[i+1],a[i+2]}) != 3+(1 < i&&i < 5)) return;
        }
        ans++;
        return;
    }
    for(int i = 1;i <= 4;i++) {
        a[x] = i;
        go(x+1);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    go(1);
    cout << ans;
}