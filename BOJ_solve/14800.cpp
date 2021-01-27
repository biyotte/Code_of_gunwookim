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
int T;
int n,p,idx[55];
int a[55],b[55][55];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> T;
    for(int tc = 1;tc <= T;tc++) {
        cin >> n >> p;
        for(int i = 1;i <= n;i++) cin >> a[i];
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= p;j++) cin >> b[i][j];
            sort(b[i]+1,b[i]+p+1), idx[i] = 1;
        }
        int ch = 0,can,g = 1,ans = 0;
        while(1) {
            can = 1;
            for(int i = 1;i <= n;i++) {
                while(idx[i] <= p&&b[i][idx[i]] < a[i]*g*9/10) idx[i]++;
                if(idx[i] > p) {ch = 1; break;}
                if(b[i][idx[i]] > a[i]*g*11/10) {can = 0; break;}
            }
            if(ch) break;
            if(!can) g++;
            else {
                ans++;
                for(int i = 1;i <= n;i++) idx[i]++;
            }
        }
        cout << "Case #" << tc << ": " << ans << '\n';
    }
}  
