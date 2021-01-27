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
int cnt[35];
int n,k,d;
vec v[100005];

struct Student {
    int d,idx;
}a[100005];

bool cmp(Student x,Student y) {
    return x.d < y.d;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> n >> k >> d;
    for(int i = 1;i <= n;i++) {
        int x,y; cin >> x >> a[i].d;
        a[i].idx = i;
        for(int j = 1;j <= x;j++) {
            cin >> y; v[i].pb(y);
        }
    }
    sort(a+1,a+n+1,cmp);
    ll ans = 0;
    for(int l = 1,r = 1;l <= n;l++) {
        while(r <= n&&a[r].d-a[l].d <= d) {
            for(int i : v[a[r].idx]) cnt[i]++;
            r++;
        }
        int sum = 0,sum2 = 0;
        for(int i = 1;i <= k;i++) {
            if(cnt[i]) sum++;
            if(cnt[i] == r-l) sum2++;
        }
        ans = max(ans,1LL*(r-l)*(sum-sum2));
        for(int i : v[a[l].idx]) cnt[i]--;
    }
    cout << ans;
}
