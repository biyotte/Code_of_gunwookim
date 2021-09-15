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
int n,c[500005],cnt;
int t[1000005];
ll ans;

void update(int x) {
    for(;x <= 2*n;x += x&-x) t[x]++;
}

int query(int l,int r) {
    int ret = 0;
    for(;r;r -= r&-r) ret += t[r];
    for(--l;l;l -= l&-l) ret -= t[l];
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for(int i = 1;i <= 2*n;i++) {
        int x; cin >> x;
        if(c[x]) ans += i-c[x]-1-query(c[x],i)*2, update(c[x]);
        else c[x] = i;
    }
    cout << n+1+ans/2;
}
