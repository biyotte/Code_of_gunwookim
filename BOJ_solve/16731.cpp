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
int n;
ll a[100005];

ll d(int x,int y) {
    return abs(a[x]-a[y]);
}

int FindL(int wi,int r) {
    if(wi == 1) return -1;
    ll len = a[r]-a[wi];
    int it = upper_bound(a+1,a+wi+1,a[wi]-len)-a;
    if(it == wi) return -1;
    return it;
}

int FindR(int wi,int l) {
    if(wi == n) return -1;
    ll len = a[wi]-a[l];
    int it = upper_bound(a+wi+1,a+n+1,a[wi]+len)-a-1;
    if(it == wi) return -1;
    return it;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    a[0] = -llINF;
    a[n+1] = llINF;
    ll ans = 0;
    for(int st = 1;st <= n;st++) {
        int l = st, r = st,wi = 0;
        while(1 < l||r < n) {
            if(!wi) {
                int idx = FindL(l,r+1);
                if(idx == -1) {
                    ans += d(l,r+1);
                    r++;
                    wi ^= 1;
                }
                else {
                    ans += d(l,idx);
                    l = idx;
                }
            }
            else {
                int idx = FindR(r,l-1);
                if(idx == -1) {
                    ans += d(r,l-1);
                    l--;
                    wi ^= 1;
                }
                else {
                    ans += d(r,idx);
                    r = idx;
                }
            }
        }
    }
    cout << ans;
}