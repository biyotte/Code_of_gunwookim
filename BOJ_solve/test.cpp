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
typedef pair <int,int> pl;
typedef pair <ll,ll> pi;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
typedef unsigned long long ull;
int n,m,Q;
int a[200005];
int t[400005];
int q[200005][3];
vec rev;

void update(int l,int r,int val) {
    for(++l;l <= m;l += l&-l) t[l] += val;
    for(++r;r <= m;r += r&-r) t[r] -= val;
}

int query(int x) {
    int ret = 0;
    for(;x;x -= x&-x) ret += t[x];
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> Q;
    rev.pb(0);
    for(int i = 1;i <= n;i++) cin >> a[i], rev.pb(a[i]);
    for(int i = 1;i <= Q;i++) {
        cin >> q[i][0] >> q[i][1];
        if(q[i][0] & 1) rev.pb(q[i][1]);
        else cin >> q[i][2], rev.pb(q[i][2]);
    }
    sort(all(rev)), rev.erase(unique(all(rev)),rev.end());
    for(int i = 0;i <= n+1;i++) a[i] = lower_bound(all(rev),a[i])-rev.begin()+1;
    for(int i = 1;i <= Q;i++) {
        if(q[i][0] & 1) q[i][1] = lower_bound(all(rev),q[i][1])-rev.begin()+1;
        else q[i][2] = lower_bound(all(rev),q[i][2])-rev.begin()+1;
    }
    m = rev.size();
    for(int i = 0;i <= n;i++) update(min(a[i],a[i+1]),max(a[i],a[i+1]),1);
    for(int i = 1;i <= Q;i++) {
        if(q[i][0] & 1) cout << query(q[i][1])/2 << '\n';
        else {
            int x = q[i][1], y = q[i][2];
            update(min(a[x],a[x-1]),max(a[x],a[x-1]),-1);
            update(min(a[x],a[x+1]),max(a[x],a[x+1]),-1);
            a[x] = y;
            update(min(a[x],a[x-1]),max(a[x],a[x-1]),1);
            update(min(a[x],a[x+1]),max(a[x],a[x+1]),1);
        }
    }
}