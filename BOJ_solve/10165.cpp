#include <bits/stdc++.h>
#define MAXN 200005
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
int L,n,mn,c[500005];
int cnt;

struct Bus {
    int l,r,idx;
}a[500005];

bool cmp(Bus x,Bus y) {
    if(x.l == y.l) return x.r > y.r;
    return x.l < y.l;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> L >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i].l >> a[i].r;
        if(a[i].l > a[i].r) a[i].l = a[i].l-L;
        mn = min(mn,a[i].l);
    }
    for(int i = 1;i <= n;i++) {
        if(a[i].l >= mn+L&&a[i].l < a[i].r) a[i].r -= L;
        if(a[i].l >= mn+L) a[i].l -= L;
        a[i].l -= mn, a[i].r -= mn;
        a[i].idx = i;
    }
    sort(a+1,a+n+1,cmp);
    int r = a[1].r;
    for(int i = 2;i <= n;i++) {
        if(a[i].r <= r) c[a[i].idx] = 1;
        r = max(r,a[i].r);
    }
    for(int i = 1;i <= n;i++) if(!c[i]) cout << i << ' ';
}