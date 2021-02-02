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
int n,m,idx,w[10005];
ll c[605][605],ans;
pi a[605];

struct Point {
    pi x; int w;
}b[10005];

int ccw(pi x,pi y,pi z) {
    int op = x.x*y.y+y.x*z.y+z.x*x.y;
    op -= x.y*y.x+y.y*z.x+z.y*x.x;
    if(op < 0) return -1;
    if(op > 0) return 1;
    return 0;
}

bool cmp(Point x,Point y) {
    return ccw(a[idx],x.x,y.x) > 0;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i].x >> a[i].y;
    reverse(a+1,a+n+1);
    cin >> m;
    for(int i = 1;i <= m;i++) cin >> b[i].x.x >> b[i].x.y >> b[i].w, ans += b[i].w;
    for(int i = 1;i <= n;i++) {
        idx = i;
        vector <Point> v;
        for(int j = 1;j <= m;j++) if(b[j].x != a[i]) v.pb(b[j]);
        sort(all(v),cmp);
        int la = 0;
        ll sum = 0;
        for(int j = i+1;j < i+n;j++) {
            int now = (j-1)%n+1;
            while(la < v.size()&&ccw(a[i],v[la].x,a[now]) > 0) {
                sum += v[la++].w;
            }
            c[i][now] = sum;
        }
    }
    ll rans = llINF;
    for(int i = 1;i <= n;i++) {
        for(int j = i+1;j <= n;j++) {
            for(int k = j+1;k <= n;k++) {
                rans = min(rans,c[i][j]+c[j][k]+c[k][i]);
            }
        }
    }
    cout << ans-rans;
}
