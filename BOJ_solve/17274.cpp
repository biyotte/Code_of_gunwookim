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
int n,m,Q,q[200005];
pi a[200005];
vec rv,t[2400005];

void update(int x,int l,int r,int wi,int val) {
    if(wi < l||r < wi) return;
    t[x].pb(val);
    if(l == r) return;
    int mid = (l + r) >> 1;
    update(x*2,l,mid,wi,val), update(x*2+1,mid+1,r,wi,val);
}

int query1(int x,int l,int r,int rl,int rr) {
    if(rl > r||l > rr) return 0;
    if(rl <= l&&r <= rr) return (t[x].empty() ? 0 : t[x].back());
    int mid = (l + r) >> 1;
    return max(query1(x*2,l,mid,rl,rr),query1(x*2+1,mid+1,r,rl,rr));
}

int query2(int x,int l,int r,int wi,int gidx) {
    if(wi > r) return 0;
    if(l >= wi) {
        int it = upper_bound(all(t[x]),gidx)-t[x].begin();
        return ((int)t[x].size()-it)%2;
    }
    int mid = (l + r) >> 1;
    return (query2(x*2,l,mid,wi,gidx)+query2(x*2+1,mid+1,r,wi,gidx))&1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> Q;
    for(int i = 1;i <= n;i++) {
        cin >> a[i].x >> a[i].y;
        rv.pb(a[i].x), rv.pb(a[i].y);
    }
    for(int i = 1;i <= Q;i++) {
        cin >> q[i];
        rv.pb(q[i]);
    }
    sort(all(rv)), rv.erase(unique(all(rv)),rv.end());
    m = rv.size();
    for(int i = 1;i <= n;i++) {
        a[i].x = lower_bound(all(rv),a[i].x)-rv.begin()+1;
        a[i].y = lower_bound(all(rv),a[i].y)-rv.begin()+1;
    }
    for(int i = 1;i <= Q;i++) {
        q[i] = lower_bound(all(rv),q[i])-rv.begin()+1;
        update(1,1,m,q[i],i);
    }
    ll Ans = 0;
    for(int i = 1;i <= n;i++) {
        if(a[i].x == a[i].y) {
            Ans += rv[a[i].x-1];
            continue;
        }
        int ch = 0;
        if(a[i].x > a[i].y) swap(a[i].x,a[i].y), ch = 1;
        int mxidx = query1(1,1,m,a[i].x,a[i].y-1);
        int ans = query2(1,1,m,a[i].y,mxidx);
        if(!mxidx) ans = (ans+ch)%2, Ans += (ans ? rv[a[i].y-1] : rv[a[i].x-1]);
        else Ans += (ans ? rv[a[i].x-1] : rv[a[i].y-1]);
    }
    cout << Ans;
}
