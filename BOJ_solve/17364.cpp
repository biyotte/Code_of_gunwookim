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
int n,k,sel;
pi a[100005];
multiset <int> s;

bool cmp(pi x,pi y) {
    return x.y < y.y;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i].x >> a[i].y;
    }
    sort(a+1,a+n+1,cmp);
    int cnt = 0;
    for(int i = 1;i <= n;i++) {
        if(sel >= a[i].x) continue;
        if(k == 1) {
            sel = a[i].y, cnt++;
            continue;
        }
        if(s.empty()) {
            s.insert(a[i].y);
            continue;
        }
        auto it = s.lower_bound(a[i].x);
        if(it != s.begin()) {
            it--;
            s.erase(it);
            s.insert(a[i].y);
        }
        else if(s.size() != k-1) s.insert(a[i].y);
        else sel = a[i].y, cnt++;
    }
    cout << cnt;
}