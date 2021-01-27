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
int n,m;
int a[100005],b[100005];
ll cnt[100005],sa,sb;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i], sa += a[i];
    for(int i = 1;i <= m;i++) cin >> b[i], sb += b[i];
    sort(a+1,a+n+1), sort(b+1,b+m+1);
    if(a[n]^b[m]) {
        cout << -1;
        return 0;
    }
    ll ansMax = 0,sum = 0;
    for(int i = 1,p = 1;i <= n;i++) {
        while(p <= m&&a[i] >= b[p]) sum += b[p], p++;
        ansMax += sum+a[i]*(m-p+1);
    }
    cout << max(sa,sb) << ' ' << ansMax;
}
