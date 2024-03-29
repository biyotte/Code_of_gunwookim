#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define all(v) v.begin(),v.end()
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
using namespace std;
const long long INF = 1e9;
const int TMX = 1 << 18;
const long long llINF = 3e18+10;
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
int n,now,pv,ans[1000005];
int op[1000005];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    if(n % 4 > 1) {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    for(int i = n-1;i >= 0;i--) {
        op[i] = (n-i)%2;
        if(i <= (n-1)/2) op[i] = ((n-1)/2-i)%2;
    }
    now = pv = 1;
    for(int i = n-1;i >= 1;i--) {
        if(i == (n-1)/2) continue;
        now += i*(op[i] ? 1 : -1);
        ans[pv] = now;
        pv = now;
    }
    ans[(n-1)/2+1] = 1;
    for(int i = 1;i <= n;i++) {
        if(!ans[i]) cout << i-1 << ' ';
        else cout << ans[i]-1 << ' ';
    }
}