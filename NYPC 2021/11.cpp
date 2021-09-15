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
int n,m,k,Q,pv[500005];
int qu[500005];
int mx;
ll t[4000005];
vec v[500005];
vec rev,wi[1000005];

void update(int x,int l,int r,int rl,int rr,ll val) {
    if(rl > r||l > rr) return;
    if(rl <= l&&r <= rr) {
        t[x] = min(t[x],val);
        return;
    }
    int mid = (l + r) >> 1;
    update(x*2,l,mid,rl,rr,val), update(x*2+1,mid+1,r,rl,rr,val);
}

ll query(int x,int l,int r,int w) {
    if(w < l||r < w) return llINF;
    if(l == r) return t[x];
    int mid = (l + r) >> 1;
    return min({query(x*2,l,mid,w),query(x*2+1,mid+1,r,w),t[x]});
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k >> Q;
    for(int i = 1;i <= n;i++) {
        int x,y; cin >> x >> y;
        v[y].pb(x);
        rev.pb(x);
    }
    for(int i = 1;i <= Q;i++) cin >> qu[i], rev.pb(qu[i]);
    sort(all(rev));
    rev.erase(unique(all(rev)),rev.end());
    for(int i = 1;i <= Q;i++) {
        qu[i] = lower_bound(all(rev),qu[i])-rev.begin();
    }
    for(int i = 1;i <= k;i++) {
        sort(all(v[i]));
        for(int j = 0;j < v[i].size();j++) {
            v[i][j] = lower_bound(all(rev),v[i][j])-rev.begin();
        }
        wi[v[i][0]].pb(i);
        mx = max(mx,v[i][0]);
    }
    int ch = 0;
    m = rev.size();
    for(int i = 1;i <= 4*m;i++) t[i] = llINF;
    for(int i = 0;i < m;i++) {
        update(1,0,m-1,i,mx,rev[mx]-rev[i]);
        for(int j = 0;j < wi[i].size();j++) {
            int idx = wi[i][j];
            if(pv[idx] == v[idx].size()-1) {ch = 1; break;}
            wi[v[idx][++pv[idx]]].pb(idx);
            mx = max(mx,v[idx][pv[idx]]);
        }
        if(ch) break;
    }
    for(int i = 0;i < m;i++) wi[i].clear();
    mx = INF, ch = 0;
    for(int i = 1;i <= k;i++) {
        pv[i] = v[i].size()-1;
        wi[v[i][pv[i]]].pb(i);
        mx = min(mx,v[i][pv[i]]);
    }
    for(int i = m-1;i >= 0;i--) {
        update(1,0,m-1,mx,i,rev[i]-rev[mx]);
        for(int j = 0;j < wi[i].size();j++) {
            int idx = wi[i][j];
            if(!pv[idx]) {ch = 1; break;}
            wi[v[idx][--pv[idx]]].pb(idx);
            mx = min(mx,v[idx][pv[idx]]);
        }
        if(ch) break;
    }
    for(int i = 1;i <= Q;i++) {
        cout << query(1,0,m-1,qu[i]) << '\n';
        if(query(1,0,m-1,qu[i]) == llINF) return -1;
    }
}
