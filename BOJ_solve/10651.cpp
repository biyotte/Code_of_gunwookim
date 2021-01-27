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
int n,T;
int t[100005];
pl a[100005];
multiset <ll> s;

bool isok(int mid) {
    s.clear();
    for(int i = 1;i <= mid;i++) s.insert(llINF);
    for(int i = n;i >= 1;i--) {
        auto it = s.upper_bound(a[i].y);
        if(it == s.end()) return false;
        int val = *it;
        s.erase(it), s.insert(a[i].y);
    }
    return true;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> n >> T;
    for(int i = 1;i <= n;i++) {
        cin >> a[i].x >> a[i].y;
        a[i].y = a[i].x+a[i].y*T;
    }
    sort(a+1,a+n+1);
    int l = 1, r = n;
    while(l < r) {
        int mid = (l + r) >> 1;
        if(isok(mid)) r = mid;
        else l = mid+1;
    }
    cout << l;
}
