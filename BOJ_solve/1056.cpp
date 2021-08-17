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
ll n;
unordered_map <ll,ll> d;

ll mpow(ll x,int m) {
    if(!m) return 1;
    ll tmp = mpow(x,m/2);
    if(tmp > INF) return llINF;
    if(m % 2) return tmp*tmp*x;
    return tmp*tmp;
}

ll go(ll x) {
    if(d.find(x) != d.end()) return d[x];
    ll l,r;
    d[x] = x-1;
    int mx = log2(x);
    ll la = min(INF+5,x);
    for(int i = 2;i <= mx+1;i++) {
        l = 2, r = la;
        while(l < r) {
            ll mid = (l + r + 1) >> 1;
            if(mpow(mid,i) > x) r = mid-1;
            else l = mid;
        }
        la = l;
        ll tmp = mpow(l,i);
        d[x] = min(d[x],go(l)+1+abs(tmp-x));
        if(tmp > x) break;
        tmp = mpow(l+1,i);
        if(tmp == llINF) continue;
        d[x] = min(d[x],go(l+1)+1+abs(mpow(l+1,i)-x));
    }
    return d[x];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    cout << go(n);
}

