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
const long long mod = 20070713;
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
int n,k;
ll m;
pl a[50005];

bool cmpy(pl x,pl y) {
    return x.y < y.y;
}

bool cmpx(pl x,pl y) {
    return x.x < y.x;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k >> m;
    for(int i = 1;i <= n;i++) {
        cin >> a[i].x >> a[i].y;
    }
    sort(a+1,a+n+1,cmpy);
    ll sum = 0;
    priority_queue <ll> q;
    for(int i = 1;i <= k;i++) {
        sum += a[i].y;
        q.push(-a[i].x+a[i].y);
        if(sum > m) {
            cout << i-1;
            return 0;
        }
    }
    sort(a+k+1,a+n+1,cmpx);
    for(int i = k+1;i <= n;i++) {
        
    }
    for(int i = k+1;i <= n;i++) {
        ll x = -q.top(); q.pop();
        sum += x; sum += a[i].y;
        q.push(-a[i].x+a[i].y);
        if(sum > m) {
            cout << i-1;
            return 0;
        }
    }
    cout << n;
}