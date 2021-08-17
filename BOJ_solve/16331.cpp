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
int n,m;
int a[100005],b[100005];
int tu[100005],jak[100005];
int la[400005],mn[400005],mx[400005];

void push(int x,int l,int r) {
    if(la[x]) {
        mn[x] = mx[x] = la[x];
        if(l^r) la[x*2] = la[x*2+1] = la[x];
        la[x] = 0;
    }
}

void update(int x,int l,int r,int rl,int rr,int val) {
    push(x,l,r);
    if(rl > r||l > rr) return;
    if(rl <= l&&r <= rr) {
        la[x] = val;
        push(x,l,r);
        return;
    }
    int mid = (l + r) >> 1;
    update(x*2,l,mid,rl,rr,val), update(x*2+1,mid+1,r,rl,rr,val);
    mn[x] = min(mn[x*2],mn[x*2+1]);
    mx[x] = max(mx[x*2],mx[x*2+1]);
}

int queryMax(int x,int l,int r,int rl,int rr) {
    push(x,l,r);
    if(rl > r||l > rr) return 0;
    if(rl <= l&&r <= rr) return mx[x];
    int mid = (l + r) >> 1;
    return max(queryMax(x*2,l,mid,rl,rr),queryMax(x*2+1,mid+1,r,rl,rr));
}

int queryMin(int x,int l,int r,int rl,int rr) {
    push(x,l,r);
    if(rl > r||l > rr) return INF;
    if(rl <= l&&r <= rr) return mn[x];
    int mid = (l + r) >> 1;
    return min(queryMin(x*2,l,mid,rl,rr),queryMin(x*2+1,mid+1,r,rl,rr));
}

struct Op {
    int op,l,r; // op=0 : min, op=1 : max
};
vector <Op> ans;

void change(int l,int r,int wi) {
    if(l == r) return;
    int vl = l, vr = r;
    if(vl == wi) vl++;
    if(vr == wi) vr--;
    ans.pb({1,vl,vr});
    int val = queryMax(1,1,n,vl,vr);
    update(1,1,n,vl,vr,val);
    update(1,1,n,l,r,a[wi]);
    ans.pb({(val < a[wi]),l,r});
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i], update(1,1,n,i,i,a[i]);
    for(int i = 1;i <= n;i++) cin >> b[i];
    for(int ia = 1,ib = 1;ib <= n;ib++) {
        while(ia <= n&&a[ia] != b[ib]) ia++;
        if(ia > ib) tu[ib] = 1;
        if(ia > n) {
            cout << -1;
            return 0;
        }
        jak[ib] = ia;
    }

    for(int i = 1;i <= n;i++) {
        if(tu[i]) change(min(jak[i],i),max(i,jak[i]),jak[i]);
    }
    for(int i = n;i >= 1;i--) {
        if(!tu[i]) change(min(jak[i],i),max(i,jak[i]),jak[i]);
    }
    cout << ans.size() << '\n';
    for(Op i : ans) {
        cout << (i.op ? "M" : "m") << ' ' << i.l << ' ' << i.r << '\n';
    }
}