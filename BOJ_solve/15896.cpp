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
const long long mod = 1999;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,cnt[30],ans2;
int a[1000005],b[1000005];
ll ans1;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++) {
        cin >> b[i];
        for(int j = 0;j <= 28;j++) {
            if(b[i] & (1 << j)) cnt[j]++;
        }
    }
    for(int i = 1;i <= n;i++) {
        for(int j = 0;j <= 28;j++) {
            if(a[i] & (1 << j)) ans1 = (ans1+1LL*(1 << j)%mod*cnt[j]%mod)%mod;
        }
    }
    for(int bit = 0;bit <= 29;bit++) {
        int tl,tr,l = -INF, r = INF, l2 = -INF, r2 = INF;
        for(int i = 1;i <= n;i++) {
            tl = (1 << bit)-a[i]%(1 << (bit+1)), tr = (1 << (bit+1))-a[i]%(1 << (bit+1))-1;
            if(tl <= 0) {
                l2 = max(l2,tl+(1 << (bit+1)));
                r2 = min(r2,tr);
            }
            if(tl >= 0) l = max(l,tl), r = min(r,tr);
        }
        int can = 1;
        for(int i = 1;i <= n;i++) {
            int x = b[i]%(1 << (bit+1));
            if((x < l||r < x)||(r2 < x&&x < l2)) {can = 0; break;}
        }
        if(can) ans2 |= (1 << bit);
    }
    cout << ans1 << ' ' << ans2;
}
