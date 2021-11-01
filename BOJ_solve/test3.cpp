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
int n;
char a[35][35];
ld k,E1,E2,d = 0.99992,T = 10;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i]+1;
    }
    k = 1.0;
    int ans = 2000;
    while(k > 0.0005) {
        E1 = E2 = 0;
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= n;j++) {
                if(a[i][j] == 'T') E1 += 1;
            }
        }
        int ran = rand()%(n*2);
        if(ran < n) {
            for(int i = 1;i <= n;i++) {
                if(a[ran+1][i] == 'H') a[ran+1][i] = 'T';
                else a[ran+1][i] = 'H';
            }
        }
        else {
            for(int i = 1;i <= n;i++) {
                if(a[i][ran-n+1] == 'H') a[i][ran-n+1] = 'T';
                else a[i][ran-n+1] = 'H';
            }
        }
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= n;j++) {
                if(a[i][j] == 'T') E2 += 1;
            }
        }
        ld val = rand()%1000000001;
        val /= (ld)1000000000.0;
        ld p = exp((E1-E2)/(k*T));
        if(p < val) {
            if(ran < n) {
                for(int i = 1;i <= n;i++) {
                    if(a[ran+1][i] == 'H') a[ran+1][i] = 'T';
                    else a[ran+1][i] = 'H';
                }
            }
            else {
                for(int i = 1;i <= n;i++) {
                    if(a[i][ran-n+1] == 'H') a[i][ran-n+1] = 'T';
                    else a[i][ran-n+1] = 'H';
                }
            }
        }
        k *= d;
        ans = min({ans,(int)E1,(int)E2});
    }
    cout << ans;
}