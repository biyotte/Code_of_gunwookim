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
int n,k,a[105];
int mx[105],idx[105];
vec v[105];
priority_queue <pi> per, wor;

bool cmp(int x,int y) {
    return mx[x] > mx[y];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k;
    for(int i = 1;i <= n;i++) cin >> a[i], per.push({a[i],i});
    for(int i = 1;i <= k;i++) {
        cin >> mx[i];
        idx[i] = i;
    }
    while(!per.empty()) {
        pi now = per.top(); per.pop();
        sort(idx+1,idx+k+1,cmp);
        for(int i = 1;i <= now.x;i++) {
            v[idx[i]].pb(now.y);
            mx[idx[i]]--;
        }
    }
    for(int i = 1;i <= k;i++) {
        cout << v[i].size() << ' ';
        for(int j : v[i]) cout << j << ' ';
        cout << '\n';
    }
}
