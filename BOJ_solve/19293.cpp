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
int n,m[1005];
vec a[1005];
ld d[1000005],tmp[1000005],d2[1005],gop;
ld an[1000005];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> m[i];
        for(int j = 1;j <= m[i];j++) {
            int x; cin >> x;
            a[i].pb(x);
        }
        sort(all(a[i]));
        reverse(all(a[i]));
    }
    sort(a+1,a+n+1), reverse(a+1,a+n+1);
    int cnt = 0;
    for(int i = 1;i <= n;i++) {
        for(int j = 0;j <= m[i];j++) d2[j] = 0;
        gop = 1;
        for(int j = 0;j < m[i];j++) {
            d2[j+1] = gop*((ld)(1000-a[i][j])/1000.0);
            gop *= ((ld)a[i][j]/1000.0);
        }
        for(int j = 0;j <= cnt;j++) an[m[i]+j] += d[j]*gop;
        for(int j = 0;j <= m[i]+cnt;j++) tmp[j] = 0;
        if(i == 1) {
            cnt = m[i];
            for(int j = 1;j <= cnt;j++) {
                d[j] = d2[j];
            }
            continue;
        }
        for(int j = i;j <= cnt;j++) {
            for(int k = 1;k <= m[i];k++) {
                tmp[j+k] += d[j]*d2[k];
            }
        }
        cnt += m[i];
        for(int j = 0;j <= cnt;j++) d[j] = tmp[j];
    }
    ld ans = 0;
    for(int i = 0;i <= cnt;i++) ans += (an[i]+d[i])*(ld)i;
    cout << ans;
}
