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
int n,m,b;
int p[1005],q[1005];
vector <pair <int,pi>> v;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> T;
    for(int tc = 1;tc <= T;tc++) {
        cin >> n >> m >> b;
        v.clear();
        for(int i = 1;i <= m;i++) cin >> p[i] >> q[i];
        for(int i = 1;i <= m;i++) {
            if(p[i] >= b) v.pb({p[i],{0,i}});
            for(int j = i;j <= m;j++) {
                if(p[i]+p[j] >= b) v.pb({p[i]+p[j],{i,j}});
            }
        }
        sort(all(v));
        ll ans = 0;
        for(auto i : v) {
            int val = i.x, x = i.y.x, y = i.y.y;
            if(!x) {while(n&&q[y]) q[y]--, ans += val, n--;}
            else {
                if(x^y) {while(n&&q[x]&&q[y]) q[x]--, q[y]--, ans += val, n--;}
                else {while(n&&q[x] >= 2) q[x] -= 2, ans += val, n--;}
            }
        }
        cout << "Case #" << tc << ": ";
        if(n) cout << "-1\n";
        else cout << ans << '\n';
    }
}
