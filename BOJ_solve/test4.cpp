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
int n;
pl a[37];
vector <pl> v[20], v2[20];

void go(int x,int y,ll sum,int bit,int cnt) {
    if(x == y+1) {v[cnt].pb({sum,bit}); return;}
    go(x+1,y,sum+a[x].x,bit,cnt+1), go(x+1,y,sum-a[x].y,bit + (1 << (n/2-x)),cnt);
}

void go2(int x,int y,ll sum,int bit,int cnt) {
    if(x == y+1) {v2[cnt].pb({sum,bit}); return;}
    go2(x+1,y,sum+a[x].x,bit,cnt+1), go2(x+1,y,sum-a[x].y,bit + (1 << (n-x)),cnt);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i].x;
    for(int i = 1;i <= n;i++) cin >> a[i].y;
    go(1,n/2,0,0,0), go2(n/2+1,n,0,0,0);
    for(int j = 0;j < n/2;j++) {
        vector <pl> tmp;
        sort(all(v2[j]));
        tmp.pb(v2[j][0]);
        for(int i = 1;i < v2[j].size();i++) {
            if(tmp.back().x^v2[j][i].x) tmp.pb(v2[j][i]);
        }
        v2[j] = tmp;
    }
    ll ans = llINF;
    int idx1 = INF, idx2 = INF;
    for(int cn = 0;cn <= n/2;cn++) {
        for(pl i : v[cn]) {
            int it = lower_bound(all(v2[n/2-cn]),make_pair((ll)-i.x,0LL))-v2[n/2-cn].begin();
            if(it != v2[n/2-cn].size()) {
                if(ans > abs(i.x+v2[n/2-cn][it].x)) ans = abs(i.x+v2[n/2-cn][it].x), idx1 = i.y, idx2 = v2[n/2-cn][it].y;
                else if(ans >= abs(i.x+v2[n/2-cn][it].x)&&(idx1 > i.y||(idx1 == i.y&&idx2 > v2[n/2-cn][it].y))) {
                    ans = abs(i.x+v2[n/2-cn][it].x), idx1 = i.y, idx2 = v2[n/2-cn][it].y;
                }
            }
            if(it) {
                it--;
                if(ans > abs(i.x+v2[n/2-cn][it].x)) ans = abs(i.x+v2[n/2-cn][it].x), idx1 = i.y, idx2 = v2[n/2-cn][it].y;
                else if(ans >= abs(i.x+v2[n/2-cn][it].x)&&(idx1 > i.y||(idx1 == i.y&&idx2 > v2[n/2-cn][it].y))) {
                    ans = abs(i.x+v2[n/2-cn][it].x), idx1 = i.y, idx2 = v2[n/2-cn][it].y;
                }
            }
        }
    }
    for(int i = n/2-1;i >= 0;i--) {
        if(idx1 & (1 << i)) cout << "2 ";
        else cout << "1 ";
    }
    for(int i = n/2-1;i >= 0;i--) {
        if(idx2 & (1 << i)) cout << "2 ";
        else cout << "1 ";
    }
}