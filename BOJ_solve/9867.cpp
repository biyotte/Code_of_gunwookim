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
const long long llINF = 1e18;
const int mod = 1e9+7;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,Q;
ll ans,a[40005];

struct Range {
    ll no,l,r,lr;
}t[160005];

Range f(Range left,Range right) {
    Range ret;
    ret.no = max({left.no+right.l,left.r+right.no,left.no+right.no});
    ret.l = max(left.l+max(right.l,right.no),left.lr+right.no);
    ret.r = max(right.r+max(left.r,left.no),right.lr+left.no);
    ret.lr = max(left.l+max(right.r,right.lr),left.lr+right.r);
    return ret;
}

void build(int x,int l,int r) {
    if(l == r) {
        t[x] = {0,-llINF,-llINF,a[l]};
        return;
    }
    int mid = (l + r) >> 1;
    build(x*2,l,mid), build(x*2+1,mid+1,r);
    t[x] = f(t[x*2],t[x*2+1]);
}

void update(int x,int l,int r,int wi,int val) {
    if(wi < l||r < wi) return;
    if(l == r) {
        t[x] = {0,-llINF,-llINF,val};
        return;
    }
    int mid = (l + r) >> 1;
    update(x*2,l,mid,wi,val), update(x*2+1,mid+1,r,wi,val);
    t[x] = f(t[x*2],t[x*2+1]);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> Q;
    for(int i = 1;i <= n;i++) cin >> a[i];
    build(1,1,n);
    while(Q--) {
        int x,y; cin >> x >> y;
        update(1,1,n,x,y);
        ans += max({t[1].no,t[1].l,t[1].r,t[1].lr});
    }
    cout << ans;
}
