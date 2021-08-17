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
int n,g,c[100005];
int a[100005],ra[100005];
priority_queue <pi> q;
ll T;

bool isok(int mid) {
    ll ret = 0;
    g = 1;
    while(!q.empty()) q.pop();
    for(int i = 1;i <= n;i++) c[i] = 0, a[i] = ra[i], q.push({-a[i],i});
    for(int i = 1;i <= n;i++) {
        while(c[q.top().y]) q.pop();
        int x = q.top().y; q.pop();
        c[x] = 1;
        if(x > 1&&a[x-1]-a[x] > mid) {
            ret += a[x-1]-a[x]-mid, a[x-1] = a[x]+mid;
            q.push({-a[x-1],x-1});
        }
        if(x < n&&a[x+1]-a[x] > mid) {
            ret += a[x+1]-a[x]-mid, a[x+1] = a[x]+mid;
            q.push({-a[x+1],x+1});
        }
    }
    return (ret <= T);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> T;
    for(int i = 1;i <= n;i++) cin >> a[i], ra[i] = a[i];
    int l = 0, r = 1e9;
    while(l < r) {
        int mid = (l + r) >> 1;
        if(isok(mid)) r = mid;
        else l = mid+1;
    }
    isok(l);
    for(int i = 1;i <= n;i++) cout << a[i] << ' ';
}