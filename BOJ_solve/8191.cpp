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
const long long llINF = 4e18+10;
const long long mod = 20070713;
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
int n,m,idx[1000005];
ll a[1000005], s[1000005];
ll ml[1000005], mr[1000005];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    while(m--) {
        int k; cin >> k;
        for(int i = 1;i <= n;i++) {
            s[i] = s[i-1]+(a[i]-k);
            ml[i] = min((i > 1 ? ml[i-1] : llINF),s[i]);
        }
        for(int i = n;i >= 1;i--) {
            mr[i] = max((i < n ? mr[i+1] : -llINF),s[i]);
        }
        int ans = 0;
        for(int r = 1,l = 0;r <= n;r++) {
            while(l < r&&mr[r]-ml[l] < 0) l++;
            if(mr[r]-ml[l] >= 0) ans = max(ans,r-l);
        }
        cout << ans << ' ';
    }
}
