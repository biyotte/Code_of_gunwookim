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
const long long llINF = 4e18+10;
const long long mod = 20070713;
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
int n,Q;
int a[100005];

struct Seg {
    int sz;
    vector <ld> t;
    Seg(int Sz) : sz(Sz) {
        t.resize(sz);
    }
    void update(int x,ld y) {
        for(;x < sz;x = x|(x+1)) t[x] += y;
    }
    ld query(int x) {
        ld ret = 0;
        for(;x >= 0;x = (x&(x+1))-1) {
            ret += t[x];
        }
        return ret;
    }
};

Seg z(1005),o(1005),t(1005);

void Operate(int idx,ld gop) {
    int mn = min(a[idx],a[idx+1]), mx = max(a[idx],a[idx+1]);
    ld diff = mx-mn;
    if(mn^mx) {
        t.update(mn,gop*1/diff/2), t.update(mx+1,gop*-1/diff/2);
        o.update(mn,gop*-mn/diff), o.update(mx+1,gop*mn/diff);
        z.update(mn,gop*mn*mn/diff/2), z.update(mx+1,gop*-mn*mn/diff/2);
    }
    o.update(mx+1,gop), z.update(mx+1,gop*(diff/2-mx));
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> Q;
    for(int i = 1;i <= n;i++) cin >> a[i];
    cout << fixed << setprecision(3);
    for(int i = 1;i < n;i++) Operate(i,1);
    while(Q--) {
        char op; int x,y;
        cin >> op;
        if(op == 'Q') {
            cin >> x;
            cout << t.query(x)*x*x+o.query(x)*x+z.query(x) << '\n';
        }
        else {
            cin >> x >> y;
            x++;
            if(x > 1) Operate(x-1,-1);
            if(x < n) Operate(x,-1);
            a[x] = y;
            if(x > 1) Operate(x-1,1);
            if(x < n) Operate(x,1); 
        }
    }
}