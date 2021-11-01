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
int n;
int a[600005];
char ans[600005];

struct TreeLtR {

    int tree[2400005];

    void update(int x,int l,int r,int rl,int rr,int val) {
        if(rl > r||l > rr) return;
        if(rl <= l&&r <= rr) {
            tree[x] = min(tree[x],val);
            return;
        }
        int mid = (l + r) >> 1;
        update(x*2,l,mid,rl,rr,val), update(x*2+1,mid+1,r,rl,rr,val);
    }

    int query(int x,int l,int r,int wi) {
        if(l > wi||wi > r) return INF;
        if(l == r) return tree[x];
        int mid = (l + r) >> 1;
        return min({query(x*2,l,mid,wi),query(x*2+1,mid+1,r,wi),tree[x]});
    }

    int query(int x) {
        return query(1,1,n*2,x);
    }

    void update(int l,int r) {
        update(1,1,n*2,l,r,r);
    }

    int LazyPro(int x,int l,int )

}upl,downl;

struct TreeRtL {

    int tree[2400005];

    void update(int x,int l,int r,int rl,int rr,int val) {
        if(rl > r||l > rr) return;
        if(rl <= l&&r <= rr) {
            tree[x] = max(tree[x],val);
            return;
        }
        int mid = (l + r) >> 1;
        update(x*2,l,mid,rl,rr,val), update(x*2+1,mid+1,r,rl,rr,val);
    }

    int query(int x,int l,int r,int wi) {
        if(l > wi||wi > r) return 0;
        if(l == r) return tree[x];
        int mid = (l + r) >> 1;
        return max({query(x*2,l,mid,wi),query(x*2+1,mid+1,r,wi),tree[x]});
    }

    int query(int x) {
        return query(1,1,n*2,x);
    }

    void update(int l,int r) {
        update(1,1,n*2,l,r,l);
    }

}upr,downr;

struct Ball {
    int l,r,idx;
}idx[300005];

bool cmp(Ball x,Ball y) {
    if(x.r-x.l == y.r-y.l) return x.l < y.l;
    return x.r-x.l < y.r-y.l;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n*8;i++) upl.tree[i] = downl.tree[i] = INF;
    for(int i = 1;i <= n*2;i++) {
        cin >> a[i];
        if(!idx[a[i]].l) idx[a[i]].l = i;
        else idx[a[i]].r = i, idx[a[i]].idx = a[i];
    }
    random_shuffle(idx+1,idx+n+1);
    for(int i = 1;i <= n;i++) {
        int l = idx[i].l, r = idx[i].r;
        //cout << up.query(r) << ' ' << up.query(l-1) << '\n';
        //cout << l << ' ' << r << ' ' << upl.query(l) << ' ' << upr.query(r) << ' ' << downl.query(l) << ' ' << downr.query(r) << '\n';
        if(upl.query(l) < r||upr.query(r) > l) {
            if(downl.query(l) < r||downr.query(r) > l) {
                //cout << l << ' ' << r << ' ' << upl.query(l) << ' ' << upr.query(r) << ' ' << downl.query(l) << ' ' << downr.query(r) << '\n';
                cout << "IMPOSSIBLE";
                return 0;
            }
            //cout << l << ' ' << r << " down\n";
            downl.update(l,r), downr.update(l,r);
            ans[l] = ans[r] = 'v';
        }
        else {
            //cout << l << ' ' << r << " up\n";
            upl.update(l,r), upr.update(l,r);
            ans[l] = ans[r] = '^';
        }
    }
    cout << ans+1;
}
