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
int a[100005];
int b[100005];
int Lg[100005],Rg[100005];
int jak[100005];
int la[400005], mn[400005], mx[400005];

void push(int x,int l,int r) {
    if(la[x]) {
        mn[x] = mx[x] = la[x];
        la[x*2] = la[x*2+1] = la[x];
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

void go() {
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i], update(1,1,n,i,i,a[i]);
    for(int i = 1;i <= n;i++) cin >> b[i];
    if(n == 1) {
        cout << (a[1]^b[1] ? -1 : 0);
        return 0;
    }
    int la = 1;
    for(int i = 1;i <= n;i++) {
        if(a[i] == b[i]) {
            m++;
            Lg[m] = la, Rg[m] = i;
            la = i;
        }
    }
    m++;
    Lg[m] = la, Rg[m] = n;
    for(int ii = 1;ii <= m;ii++) {
        int L = Lg[ii], R = Rg[ii],Lgo = R,Rgo = L,ch = 0;
        jak[L] = 0;
        for(int ia = L,ib = L;ib <= R;ib++) {
            while(ia <= R&&a[ia] != b[ib]) ia++;
            if(ia > ib) {
                Lgo = ib-1;
                break;
            }
            jak[ib] = ia;
        }
        for(int ia = R,ib = R;ib >= L;ib--) {
            while(ia >= L&&a[ia] != b[ib]) ia--;
            if(jak[ib]||ia < ib) {Rgo = ib+1; break;}
            jak[ib] = ia;
        }
        if(Lgo+1 < Rgo ) {
            cout << -1;
            return 0;
        }
        for(int i = Lgo;i > L;i--) {
            //cout << "L " << i << " : " << jak[i] << '\n';
            change(jak[i],i,jak[i]);
        }
        for(int i = Rgo;i < R;i++) {
            //cout << "R " << i << " : " << jak[i] << '\n';
            change(i,jak[i],jak[i]);
        }
    }
    cout << ans.size() << '\n';
    for(int i = 1;i <= n;i++) update(1,1,n,i,i,a[i]);
    for(Op i : ans) {
        int val = 0;
        if(!i.op) val = queryMin(1,1,n,i.l,i.r);
        else val = queryMax(1,1,n,i.l,i.r);
        update(1,1,n,i.l,i.r,val);
        //cout << (i.op ? "M" : "m") << ' ' << i.l << ' ' << i.r << '\n';
    }
    for(int i = 1;i <= n;i++) if(queryMax(1,1,n,i,i) != b[i]) {
        cout << n << '\n';
        for(int i = 1;i <= n;i++)
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    while(1) {
        go();
    }
}