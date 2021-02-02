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
const long long llINF = 1e18;
const long long mod = 1999;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,m,k,ind[50005],nx[200005],pv[200005],app[200005];
map <pi,int> edge;
set <int> have[50005];
vec inp,ans;
vec non[50005];
pi e[200005];

void dfs(int x,int prev) {
    if(nx[prev]) {
        int next = e[nx[prev]].y;
        if(have[x].find(next) == have[x].end()) return;
        have[x].erase(next);
        dfs(next,nx[prev]);
    }
    else {
        while(!non[x].empty()) {
            int next = non[x].back();
            non[x].pop_back();
            dfs(next,edge[{x,next}]);
        }
    }
    ans.pb(x);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        int x,y; cin >> x >> y;
        ind[x]++, ind[y]--;
        edge[{x,y}] = i;
        e[i] = {x,y};
    }
    cin >> k;
    for(int j = 1;j <= k;j++) {
        int len,x; inp.clear();
        cin >> len;
        for(int i = 1;i <= len;i++) {
            cin >> x;
            inp.pb(x);
        }
        for(int i = 1;i < len-1;i++) {
            int prev = edge[{inp[i-1],inp[i]}];
            int next = edge[{inp[i],inp[i+1]}];

            if(!prev||!next||(nx[prev]&&nx[prev] != next)||(pv[next]&&pv[next] != prev)) {
                cout << "NIE";
                return 0;
            }
            nx[prev] = next;
            pv[next] = prev;
            app[next] = 1;
        }
    }
    for(int i = 1;i <= n;i++) {
        if(ind[i]) {
            cout << "NIE";
            return 0;
        }
    }
    for(int i = 1;i <= m;i++) {
        if(app[i]) have[e[i].x].insert(e[i].y);
        else non[e[i].x].pb(e[i].y);
    }
    dfs(1,0);
    reverse(all(ans));
    if(ans.size() != m+1) {
        cout << "NIE";
        return 0;
    }
    cout << "TAK\n";
    for(int i : ans) cout << i << '\n';
}