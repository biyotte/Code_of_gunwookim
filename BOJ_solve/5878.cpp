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
int n;
ll L,sum[100005];
ll d[100005],a[100005];
multiset <ll> s;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> L;
    for(int i = 1;i <= n;i++) {
        int x,y; cin >> x >> y;
        a[i] = x;
        sum[i] = sum[i-1]+y;
    }
    deque <pi> dq; // {idx,sz}
    for(int i = 1;i <= n;i++) {
        while(!dq.empty()&&sum[i]-sum[dq.front().x-dq.front().y] > L) {
            s.erase(s.find(a[dq.front().x]+d[dq.front().x-dq.front().y]));
            if(dq.front().y > 1) {
                dq.front().y--;
                s.insert(a[dq.front().x]+d[dq.front().x-dq.front().y]);
            }
            else dq.pop_front();
        }
        int sz = 1;
        while(!dq.empty()&&a[dq.back().x] < a[i]) {
            s.erase(s.find(a[dq.back().x]+d[dq.back().x-dq.back().y]));
            sz += dq.back().y;
            dq.pop_back();
        }
        dq.push_back({i,sz});
        s.insert(a[i]+d[i-sz]);
        d[i] = *s.begin();
    }
    cout << d[n];
}
