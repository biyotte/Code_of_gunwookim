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
int n,top,c[50005];
pi s[50005];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    vec ans;
    for(int i = 1;i <= 2*n;i++) {
        int x; cin >> x;
        if(!c[x]) {
            top++;
            s[top] = {x,top};
            c[x] = 1;
        }
        else {
            vecpi pu;
            while(s[top].x^x) {
                pu.pb({s[top].x,s[top].y-1});
                ans.pb(s[top].y);
                top--;
            }
            top--;
            reverse(all(pu));
            for(pi i : pu) s[++top] = i;
        }
    }
    cout << ans.size() << '\n';
    for(int i : ans) cout << i << '\n';
}