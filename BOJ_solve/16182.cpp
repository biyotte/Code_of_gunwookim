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
int n,m,c[300005],c2[300005],ans[300005];
int l[300005],r[300005],ind[300005];
priority_queue <pair<int,pi>> q; // {오른쪽 끝, 위치}
set <int> s;
vec v[300005],rv[300005];

int dfs(int x) {
    if(c2[x]) return 1;
    if(c[x]) return 0;
    c[x] = c2[x] = 1;
    for(int i : v[x]) if(dfs(i)) return 1;
    c2[x] = 0;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> l[i] >> r[i];
    for(int i = 1;i <= m;i++) {
        int x,y; cin >> x >> y;
        v[x].pb(y), ind[y]++;
        rv[y].pb(x);
    }
    for(int i = 1;i <= n;i++) {
        if(!c[i]&&dfs(i)) {
            cout << "-1";
            return 0;
        }
    }
    memset(c,0,sizeof(c));
    for(int i = 1;i <= n;i++) {
        s.insert(i);
        if(!ind[i]) q.push({-r[i],{-l[i],-i}});
    }

    while(!q.empty()) {
        int now = -q.top().y.y; q.pop();
        for(int i : v[now]) {
            l[i] = max(l[i],l[now]+1);
            if(!--ind[i]) q.push({-r[i],{-l[i],-i}});
        }
    }
    for(int i = 1;i <= n;i++) {
        for(int j : rv[i]) ind[j]++;
    }
    for(int i = 1;i <= n;i++) {
        if(!ind[i]) q.push({-r[i],{-l[i],-i}});
    }

    while(!q.empty()) {
        int now = -q.top().y.y; q.pop();
        for(int i : rv[now]) {
            r[i] = min(r[i],r[now]-1);
            if(!--ind[i]) q.push({-r[i],{-l[i],-i}});
        }
    }
    for(int i = 1;i <= n;i++) {
        for(int j : v[i]) ind[j]++;
    }
    for(int i = 1;i <= n;i++) {
        if(!ind[i]) q.push({-r[i],{-l[i],-i}});
    }
    while(!q.empty()) {
        int now = -q.top().y.y; q.pop();
        auto it = s.lower_bound(l[now]);
        if(it == s.end()||*it > r[now]) {
            cout << "-1";
            return 0;
        }
        int idx = *it;
        ans[idx] = now; s.erase(it);
        for(int i : v[now]) {
            l[i] = max(l[i],idx+1);
            if(!--ind[i]) q.push({-r[i],{-l[i],-i}});
        }
    }
    for(int i = 1;i <= n;i++) {
        if(!ans[i]) return -1;
        cout << ans[i] << '\n';
    }
}