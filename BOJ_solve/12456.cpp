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
const long long llINF = 5e18;
const long long mod = 1e9+7;
const long long hmod1 = 1e9+409;
const long long hmod2 = 1e9+433;
const long long base = 257;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int T;
ll n,k;
priority_queue <pl> q;

struct Coffee {
    ll cnt,t,val;
}a[105];

bool cmp(Coffee x,Coffee y) {
    return x.t > y.t;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> T;
    for(int tc = 1;tc <= T;tc++) {
        cin >> n >> k;
        for(int i = 1;i <= n;i++) {
            cin >> a[i].cnt >> a[i].t >> a[i].val;
        }
        sort(a+1,a+n+1,cmp); a[n+1].t = 0;
        while(!q.empty()) q.pop();
        ll ans = 0;
        for(int i = 1;i <= n;i++) {
            q.push({a[i].val,a[i].cnt});
            ll op = a[i].t-a[i+1].t;
            while(op&&!q.empty()) {
                ll val = q.top().x, cnt = q.top().y;
                q.pop();
                if(cnt > op) {
                    ans += val*op;
                    q.push({val,cnt-op});
                    op = 0;
                }
                else ans += val*cnt, op -= cnt;
            }
        }
        cout << "Case #" << tc << ": " << ans << '\n';
    }
}
