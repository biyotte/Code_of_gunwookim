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
int n,m,S,T;
vecpi v[100005];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int Tc; cin >> Tc;
    while(Tc--) {
        cin >> n >> m >> S >> T;
        for(int i = 1;i <= n;i++) v[i].clear();
        for(int i = 1;i <= m;i++) {
            int x,y,z; cin >> x >> y >> z;
            v[x].pb({y,z}), v[y].pb({x,z});
        }
        for(int i = 1;)
    }
}