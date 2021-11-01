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
const long long llINF = 1e18+10;
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
int n,top,p[300005];
int a[600005],c[300005];
int vis[300005],nope;
pi idx[300005];
pi st[300005]; // {색, 오른쪽 위치}
vec v[300005];

int Find(int x) {return (x^p[x] ? p[x] = Find(p[x]) : x);}

void merge(int x,int y) {
    x = Find(x), y = Find(y);
    if(x^y) p[y] = x;
}

void dfs(int x,int co) {
    vis[x] = co;
    for(int i : v[x]) {
        if(vis[i]&&3-co != vis[i]) nope = 1;
        if(!vis[i]) dfs(i,3-co);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) p[i] = i;
    for(int i = 1;i <= n*2;i++) {
        cin >> a[i];
        if(!idx[a[i]].x) idx[a[i]].x = i;
        else idx[a[i]].y = i, a[i] *= -1;
    }
    for(int i = 1;i <= n*2;i++) {
        //cout << i << ' ';
        if(a[i] > 0) {
            st[++top] = {a[i],idx[a[i]].y};
        }
        else {
            int id = 0,la = 0;
            while(!c[-a[i]]&&st[top].x != -a[i]) {
                if(id) {
                    merge(st[top].x,id);
                }
                if(la < st[top].y) {
                    //cout << top << ' ' << st[top].x << ' ' << st[top].y << '\n';
                    la = st[top].y;
                    id = st[top].x;
                }
                c[st[top].x] = 1;
                top--;
            }
            if(!c[-a[i]]) top--;
            if(id) {
                c[id] = 0;
                st[++top] = {id,la};
                v[-a[i]].pb(id), v[id].pb(-a[i]);
            }
        }
    }
    /*
    for(int i = 1;i <= n;i++) {
        cout << Find(i) << ' ';
    }
    cout << '\n';
    */
    for(int i = 1;i <= n;i++) {
        for(int &j : v[i]) {
            j = Find(j);
        }
    }
    for(int i = 1;i <= n;i++) {
        if(i == Find(i)) continue;
        for(int j : v[i]) {
            v[p[i]].pb(j);
        }
        v[i].clear();
    }
    /*
    for(int i = 1;i <= n;i++) {
        cout << i << " : ";
        for(int j : v[i]) cout << j << ' ';
        cout << '\n';
    }
    */
    for(int i = 1;i <= n;i++) {
        if(vis[p[i]]) continue;
        dfs(p[i],1);
    }
    if(nope) {
        cout << "IMPOSSIBLE";
    }
    else {
        for(int i = 1;i <= 2*n;i++) {
            if(vis[Find(abs(a[i]))] == 1) cout << '^';
            else cout << 'v';
        }
    }
}
