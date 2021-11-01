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
const long long llINF = 2e18+5;
const long long mod = 1e9+7;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
typedef unsigned long long ull;
int n,ans = 1,la;
pi a[1000005];
deque <pi> dq;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i].x >> a[i].y;
    for(int i = 1;i <= n;i++) {
        while(!dq.empty()&&a[dq.front().x].x > a[i].y) dq.pop_front();
        if(!dq.empty()) ans = max(ans,i-dq.front().y+1);
        la = i;
        while(!dq.empty()&&a[dq.back().x].x < a[i].x) la = dq.back().y, dq.pop_back();
        dq.pb({i,la});
    }
    cout << ans;
}