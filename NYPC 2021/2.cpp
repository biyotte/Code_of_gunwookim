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
const long long llINF = 1e16;
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
int n,m;
int c[105];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    memset(c,-1,sizeof(c));
    while(m--) {
        int t,i,s;
        cin >> t >> i >> s;
        if(!s) {
            if(c[i] != -1) {
                cout << "NO";
                return 0;
            }
            c[i] = t;
        }
        else {
            if(c[i] == -1||t-c[i] < 60) {
                cout << "NO";
                return 0;
            }
            c[i] = -1;
        }
    }
    for(int i = 1;i <= n;i++) if(c[i] != -1) {
        cout << "NO";
        return 0;
    }
    cout << "YES";
}
