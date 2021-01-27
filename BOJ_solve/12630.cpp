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
const int mod = 1e9+7;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n;
int a[45];
char s[50];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    for(int tc = 1;tc <= T;tc++) {
        cin >> n;
        for(int i = 1;i <= n;i++) {
            a[i] = 0;
            cin >> s+1;
            for(int j = 1;j <= n;j++) if(s[j] == '1') a[i] = j;
        }
        int ans = 0;
        for(int i = 1,j;i <= n;i++) {
            for(j = i;j <= n;j++) {
                if(a[j] <= i) break;
            }
            if(j == n+1) while(1);
            for(int k = j;k > i;k--) {
                swap(a[k],a[k-1]);
                ans++;
            }
        }
        cout << "Case #" << tc << ": " << ans << '\n';
    }
}
