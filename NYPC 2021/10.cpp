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
int n,k,a[200005];
ll t[1000005];
ll cnt[1000005];

void update(int x,int val) {
    int val2 = x*val;
    for(;x <= 1000000;x += x&-x) t[x] += val2, cnt[x] += val;
}

ll queryCnt(int l,int r) {
    ll ret = 0;
    for(;r;r -= r&-r) ret += cnt[r];
    for(--l;l;l -= l&-l) ret -= cnt[l];
    return ret;
}

ll queryT(int l,int r) {
    ll ret = 0;
    for(;r;r -= r&-r) ret += t[r];
    for(--l;l;l -= l&-l) ret -= t[l];
    return ret;
}

ll Get(int x) {
    ll lt = queryT(1,x-1), lc = queryCnt(1,x-1);
    ll rt = queryT(x+1,1000000), rc = queryCnt(x+1,1000000);
    return lc*x-lt+rt-rc*x;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k;
    for(int i = 1;i <= n;i++) cin >> a[i];
    ll sum = 0;
    for(int i = 1;i < k;i++) {
        sum += Get(a[i]);
        update(a[i],1);
    }
    ll ans = -llINF;
    for(int i = k;i <= n;i++) {
        sum += Get(a[i]);
        ans = max(ans,sum);
        update(a[i],1);
        sum -= Get(a[i-k+1]);
        update(a[i-k+1],-1);
    }
    cout << ans;
}
