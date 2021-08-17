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
const long long mod = 1e9+7;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,k,ml,mr,a[1000005],c[1000005];
int vl[1000005],vr[1000005],isthief[1000005];
int dl[1000005],dr[1000005];
vec v[1000005],mn[1000005];
pi g[1000005];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        v[a[i]].pb(i);
        mn[a[i]].pb(INF);
        dl[i] = INF, dr[i] = -INF;
    }
    cin >> ml >> mr;
    for(int i = 1;i <= ml;i++) cin >> vl[i], isthief[vl[i]] = 1;
    for(int i = 1;i <= mr;i++) cin >> vr[i], isthief[vr[i]] = 1;
    for(int i = 0;i < v[vl[ml]].size();i++) {
        mn[vl[ml]][i] = v[vl[ml]][i];
    }
    for(int i = ml-1;i >= 1;i--) {
        int pv = (int)v[vl[i+1]].size()-1;
        for(int j = (int)v[vl[i]].size()-1;j >= 0;j--) {
            while(pv >= 0&&v[vl[i]][j] < v[vl[i+1]][pv]) pv--;
            if(pv != (int)v[vl[i+1]].size()-1) mn[vl[i]][j] = mn[vl[i+1]][pv+1];
        }
    }
    for(int i = 0;i < v[vl[1]].size();i++) dl[v[vl[1]][i]] = mn[vl[1]][i];
    for(int i = n-1;i >= 1;i--) dl[i] = min(dl[i],dl[i+1]);

    for(int i = 1;i <= n;i++) {
        for(int &j : mn[i]) j = -INF;
    }

    for(int i = 0;i < v[vr[mr]].size();i++) {
        mn[vr[mr]][i] = v[vr[mr]][i];
    }
    for(int i = mr-1;i >= 1;i--) {
        int pv = 0;
        for(int j = 0;j < v[vr[i]].size();j++) {
            while(pv < v[vr[i+1]].size()&&v[vr[i]][j] > v[vr[i+1]][pv]) pv++;
            if(pv) mn[vr[i]][j] = mn[vr[i+1]][pv-1];
        }
    }
    dl[n+1] = INF, dr[0] = -INF;
    for(int i = 0;i < v[vr[1]].size();i++) dr[v[vr[1]][i]] = mn[vr[1]][i];
    for(int i = 2;i <= n;i++) dr[i] = max(dr[i],dr[i-1]);
    for(int i = 1;i <= n;i++) g[i] = {INF,-INF};
    for(int i = 1;i <= n;i++) g[a[i]].x = min(g[a[i]].x,dl[i+1]), g[a[i]].y = max(g[a[i]].y,dr[i-1]);
    for(int i = 1;i <= n;i++) {
        if(g[i].x > g[i].y) continue;
        c[g[i].x]++, c[g[i].y+1]--;
    }

    vec ans;
    for(int i = 1;i <= n;i++) {
        c[i] += c[i-1];
        if(c[i]&&vr[mr] == a[i]) ans.pb(i);
    }
    cout << ans.size() << '\n';
    for(int i : ans) cout << i << ' ';

}
 