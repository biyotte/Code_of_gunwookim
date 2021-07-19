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
const long long llINF = 1e18+10;
const long long mod = 1e9+7;
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
int n,a[200005];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--) {
        cin >> n;
        for(int i = 1;i <= n;i++) {
            cin >> a[i];
        }
        int ans = 0;
        for(int i = 1;i <= n;i++) {
            int c[6] = {0,0,0,0,0,0};
            c[min(n-i+1,5)] = 1;
            for(int j = 0;j <= 4;j++) {
                for(int k = j+1;k <= 4;k++) {
                    for(int l = k+1;l <= 4&&i+l <= n;l++) {
                        if((a[i+j] <= a[i+k]&&a[i+k] <= a[i+l])||(a[i+j] >= a[i+k]&&a[i+k] >= a[i+l])) c[max({j,k,l})] = 1;
                    }
                }
            }
            int ch = 0;
            for(int j = 0;j <= 4;j++) {
                if(c[j]) {ch = 1; ans += j; break;}
            }
            if(!ch) ans += 5;
        }
        cout << ans << '\n';
    }
}
