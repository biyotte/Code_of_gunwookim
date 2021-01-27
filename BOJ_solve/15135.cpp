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
const long long llINF = 1e18;
const long long mod = 998244353;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,op,op2,stans,stans2,c[300005],c2[1000005];
int a[300005],c3[1000005];
int cnt[1000005],cnt2[1000005];
int ans[300005];
vec sz,g;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); 
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    sort(a+1,a+n+1), stans = 1;
    for(int i = n;i >= 1;i--) {
        if(i != 1&&a[i] != a[i-1]) stans++;
        if(c2[a[i]]) {
            if(c2[a[i]] == 1) c[i] = 1;
            else c[i] = 0;
        }
        else {
            c3[a[i]] = 1;
            for(int j = a[i]*2;j <= 1000000;j += a[i]) {
                if(c3[j]) {
                    c2[a[i]] = 1;
                    break;
                }
            }
            if(!c2[a[i]]) c2[a[i]] = -1; 
            if(c2[a[i]] == 1) c[i] = 1;
            else c[i] = 0;
        }
        if(c[i]) cnt[a[i]]++;
        cnt2[a[i]]++;
    }
    stans2 = stans;
    ans[0] = stans;
    for(int i = 1;i <= 1000000;i++) {
        if(cnt[i]) g.pb(cnt[i]);
        if(cnt2[i]) sz.pb(cnt2[i]);
    }
    for(int i = 1;i <= n;i++) ans[i] = INF;
    sort(all(g)), sort(all(sz));
    for(int i : g) {
        for(int j = 1;j <= i;j++) {
            if(j == i) stans--;
            ans[++op] = stans;
        }
    }
    for(op++;op <= n;op++) ans[op] = ans[op-1];
    stans2++;
    for(int i : sz) {
        for(int j = 1;j <= i;j++) {
            if(j == i) stans2--;
            op2++;
            ans[op2] = min(ans[op2],stans2);
        }
    }
    for(int i = 0;i <= n;i++) {
        cout << ans[i] << ' ';
    }
}