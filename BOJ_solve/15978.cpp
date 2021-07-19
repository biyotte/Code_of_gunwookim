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
const long long llINF = 2e18;
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
int n1,n2,k,idx1[300005],idx2[300005],r1,r2;
int p[300005],sz[300005],tsz1[300005],tsz2[300005];
vec v1[300005],v2[300005];
priority_queue <pair<int,pi>> q;

int dfs1(int x) {
    int ret = 1,la = x;
    tsz1[x] = (x <= k);
    for(int i : v1[x]) ret += dfs1(i), tsz1[x] += tsz1[i], la = idx1[i];
    if(v1[x].size() > 1) q.push({-tsz1[x],{-x,1}});
    idx1[x] = la;
    return ret;
}

int dfs2(int x) {
    int ret = 1,la = x;
    tsz2[x] = (x <= k);
    for(int i : v2[x]) ret += dfs2(i), tsz2[x] += tsz2[i], la = idx2[i];
    if(v2[x].size() > 1) q.push({-tsz2[x],{-x,2}});
    idx2[x] = la;
    return ret;
}

int Find(int x) {return (x^p[x] ? p[x] = Find(p[x]) : x);}

void merge(int x,int y) {
    x = Find(x), y = Find(y);
    if(x == y) return;
    p[y] = x;
    sz[x] += sz[y];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n1 >> n2 >> k;
    for(int i = 1;i <= k;i++) {
        p[i] = i, sz[i] = 1;
    }
    for(int i = 1;i <= n1;i++) {
        int x; cin >> x;
        if(x) v1[x].pb(i);
        else r1 = i;
    }
    for(int i = 1;i <= n2;i++) {
        int x; cin >> x;
        if(x) v2[x].pb(i);
        else r2 = i;
    }
    dfs1(r1), dfs2(r2);
    for(int i = 1;i <= n1;i++) {
        if(idx1[i] > k) return -1;
    }
    for(int i = 1;i <= n2;i++) {
        if(idx2[i] > k) return -1;
    }
    while(!q.empty()) {
        int op = q.top().y.y, x = -q.top().y.x; q.pop();
        if(op & 1) {
            for(int i = 1;i < v1[x].size();i++) {
                merge(idx1[v1[x][i]],idx1[v1[x][i-1]]);
            }
            if(sz[Find(idx1[x])] != tsz1[x]) {
                cout << "NO";
                return 0;
            }
        }
        else {
            for(int i = 1;i < v2[x].size();i++) {
                merge(idx2[v2[x][i]],idx2[v2[x][i-1]]);
            }
            if(sz[Find(idx2[x])] != tsz2[x])  {
                cout << "NO";
                return 0;
            }
        }
    }
    //return -1;
    cout << "YES";
}