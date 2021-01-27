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
int n,a[105];
int d[200005],g[200005];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); 
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= a[n-1]+a[n];i++) d[i] = g[i] = INF;
    for(int i = 1;i <= a[n-1]+a[n];i++) {
        for(int j = 1;j <= n;j++) {
            if(i-a[j] >= 0) d[i] = min(d[i],d[i-a[j]]+1);
        }
        for(int j = n;j >= 1;j--) {
            if(a[j] <= i) {
                g[i] = g[i-a[j]]+1;
                break;
            }
        }
    }
    for(int i = 1;i <= a[n-1]+a[n];i++) {
        if(d[i]^g[i]) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
}

