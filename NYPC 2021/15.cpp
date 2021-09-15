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
const long long llINF = 2e18+5;
const long long mod = 1e9+7;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
typedef unsigned long long ull;
int n,m;
vec rev;
vector<pl> td[1600005],t[1600005];
ll d[200005];
int p[1600005],pd[1600005];

struct A {
    int l,r,idx;
    ll y,c;
}a[200005];

bool cmp(A x,A y) {
    return x.y < y.y;
}

ld getX(pl x,pl y) {
    if(x.x == y.x) while(1);
    return (ld)(x.y-y.y)/(y.x-x.x);
}

void update(int x,int l,int r,int rl,int rr,pl gi) {
    if(rl > r||l > rr) return;
    int sz;
    if(rl <= l&&r <= rr) {
        sz = t[x].size();
        while(sz > 1) {
            if(t[x][sz-1].x == gi.x) {
                if(t[x][sz-1].y < gi.y) break;
                t[x].pop_back();
                sz--;
            }
            else if(getX(t[x][sz-2],t[x][sz-1]) > getX(t[x][sz-1],gi)) {
                t[x].pop_back(), sz--;
            }
            else break;
        }
        if(sz&&t[x][sz-1].x == gi.x) {
            if(t[x][sz-1].y >= gi.y) {
                t[x].pop_back();
                sz--;
                t[x].pb(gi);
            }
        }
        else t[x].pb(gi);
        return;
    }
    sz = td[x].size();
    while(sz > 1) {
        if(td[x][sz-1].x == gi.x) {
            if(td[x][sz-1].y < gi.y) break;
            td[x].pop_back();
            sz--;
        }
        else if(getX(td[x][sz-2],td[x][sz-1]) > getX(td[x][sz-1],gi)) {
            td[x].pop_back(), sz--;
        }
        else break;
    }
    if(sz&&td[x][sz-1].x == gi.x) {
        if(td[x][sz-1].y >= gi.y) {
            td[x].pop_back();
            sz--;
            td[x].pb(gi);
        }
    }
    else td[x].pb(gi);
    int mid = (l + r) >> 1;
    update(x*2,l,mid,rl,rr,gi), update(x*2+1,mid+1,r,rl,rr,gi);
}

ll query(int x,int l,int r,int rl,int rr,ll gi) {
    if(rl > r||l > rr) return llINF;
    ll val = llINF;
    if(!t[x].empty()) {
        p[x] = min(p[x],(int)t[x].size()-5);
        p[x] = max(p[x],0);
        while(p[x]+1 < t[x].size()&&getX(t[x][p[x]],t[x][p[x]+1]) <= gi) p[x]++;
        val = t[x][p[x]].x*gi+t[x][p[x]].y;
    }
    if(rl <= l&&r <= rr) {
        if(!td[x].empty()) {
            pd[x] = min(pd[x],(int)td[x].size()-5);
            pd[x] = max(pd[x],0);
            while(pd[x]+1 < td[x].size()&&getX(td[x][pd[x]],td[x][pd[x]+1]) <= gi) pd[x]++;
            val = min(val,td[x][pd[x]].x*gi+td[x][pd[x]].y);
        }
        return val;
    }
    int mid = (l + r) >> 1;
    return min({query(x*2,l,mid,rl,rr,gi),query(x*2+1,mid+1,r,rl,rr,gi),val});
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i].y >> a[i].l >> a[i].r >> a[i].c;
        a[i].idx = i;
        rev.pb(a[i].l), rev.pb(a[i].r);
    }
    sort(all(rev)), rev.erase(unique(all(rev)),rev.end());
    for(int i = 1;i <= n;i++) {
        a[i].l = lower_bound(all(rev),a[i].l)-rev.begin()+1;
        a[i].r = lower_bound(all(rev),a[i].r)-rev.begin()+1;
    }
    sort(a+1,a+n+1,cmp);
    m = rev.size();
    update(1,1,m,1,m,{0,0});
    for(int i = 1;i <= n;i++) {
        d[a[i].idx] = query(1,1,m,a[i].l,a[i].r,a[i].y)+a[i].y*a[i].y;
        update(1,1,m,a[i].l,a[i].r,{-2*a[i].y,a[i].c+d[a[i].idx]+a[i].y*a[i].y});
    }
    for(int i = 1;i <= n;i++) cout << d[i] << '\n';
}
