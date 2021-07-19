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
int n,m;
pi a[1005],b[1005];
vecpi vv;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i].x >> a[i].y;
    }
    cin >> m;
    for(int i = 1;i <= m;i++) {
        cin >> b[i].x >> b[i].y;
    }
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            vv.pb({a[i].x+b[j].x-1,1});
            vv.pb({a[i].x+b[j].y,-1});
            vv.pb({a[i].y+b[j].x,-1});
            vv.pb({a[i].y+b[j].y+1,1});
        }
    }
    sort(all(vv));
    int la = -INF;
    ll g = 0,val = 0,ans = 0,mo = 0;
    for(pi i : vv) {
        if(la != -INF) val += g*(i.x-la);
        g += i.y;
        la = i.x;
        //cout << i.x-1 << ' ' << i.y << " : " << val << '\n';
        if(ans < val) mo = i.x-1, ans = val;
    }.
    cout << mo;
}
