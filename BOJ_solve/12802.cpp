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
int n,A,B,mid,a[300005],turn;
int c[300005],ispath[300005];
vec v[300005];
vec path;

int findPath(int x,int pr) {
    if(x == B) {
        path.pb(x);
        ispath[x] = 1;
        return 1;
    }
    for(int i : v[x]) {
        if(i == pr) continue;
        if(findPath(i,x)) {
            path.pb(x);
            ispath[x] = 1;
            return 1;
        }
    }
    return 0;
}

void dfs(int x) {
    c[x] = 1;
    vec b;
    a[x] = 0;
    for(int i : v[x]) {
        if(c[i]) continue;
        dfs(i);
        b.pb(a[i]);
    }
    sort(all(b)), reverse(all(b));
    for(int i = 0;i < b.size();i++) {
        a[x] = max(a[x],b[i]+i+1);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> A >> B;
    for(int i = 1;i < n;i++) {
        int x,y; cin >> x >> y;
        v[x].pb(y), v[y].pb(x);
    }
    findPath(A,-1); reverse(all(path));
    int l = 1, r = path.size()-1;
    while(l <= r) {
        memset(c,0,sizeof(c));
        int mid = (l + r) >> 1;
        c[path[mid]] = 1;
        dfs(A);
        c[path[mid]] = 0;
        dfs(B);
        if(l == r) break;
        if(a[A] >= a[B]) r = mid;
        else l = mid+1;
    }
    memset(c,0,sizeof(c));
    int ans = max(a[A],a[B]);
    c[path[l-1]] = 1;
    if(!c[A]) dfs(A);
    c[path[l-1]] = 0;
    dfs(B);
    cout << min(ans,max(a[A],a[B]));
}