#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
using namespace std;
const int INF = 1e9;
const int TMX = 1 << 18;
const long long llINF = 1e18;
const long long mod = 1e9+7;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,m,in2[300005];
int b[300005];
char in[300005];
char a[300005];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> in+1;
    for(int i = 1;i <= n;i++) cin >> in2[i];
    a[++m] = in[1], b[m] = in2[1];
    for(int i = 2;i <= n;i++) {
        if(in[i] != in[i-1]) a[++m] = in[i];
        b[m] = max(b[m],in2[i]);
    }
    n = m;
    if(n <= 2) {
        cout << 0;
        return 0;
    }
    int sel = (n-1)/2;
    sort(b+2,b+n);
    ll ans = 0;
    for(int i = n-1;i >= n-sel;i--) ans += b[i];
    cout << ans;
}