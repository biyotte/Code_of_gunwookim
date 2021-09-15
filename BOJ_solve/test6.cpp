#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define sz(v) v.size()
#define all(v) v.begin(),v.end()
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
using namespace std;
const int INF = 1e9;
const int TMX = 1 << 18;
const long long llINF = 1e18+10;
const long long mod = 998244353;
const long long hmod1 = 1e9+409;
const long long hmod2 = 1e9+433;
const long long base = 257;
const int MAXN = 100000;
const int MAXM = 1000000;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,g[55][55],c[55];
char a[55];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--) {
        cin >> n >> a+1;
        vec v;
        memset(c,0,sizeof(c));
        for(int i = 1;i <= n;i++) {
            if(a[i] == '2') v.pb(i);
        }
        if(v.size() == 0) {
            cout << "YES\n";
            for(int i = 1;i <= n;i++) {
                for(int j = 1;j <= n;j++) {
                    if(i == j) cout << "X";
                    else cout << "=";
                }
                cout << '\n';
            }
            continue;
        }
        if(v.size() <= 2) {
            cout << "NO\n";
            continue;
        }
        for(int i = 0;i < v.size();i++) c[v[i]] = v[(i+1)%(int)(v.size())];
        cout << "YES\n";
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= n;j++) {
                if(i == j) cout << "X";
                else if(c[i] == j) cout << "W";
                else if(c[j] == i) cout << "-";
                else cout << "=";
            }
            cout << '\n';
        }
    }
}