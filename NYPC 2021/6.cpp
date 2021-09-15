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
int n,k,ans,c[300005];
int a[300005];
int idx[300005];

bool cmp(int x,int y) {
    return a[x] < a[y];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k;
    for(int i = 1;i <= n;i++) cin >> a[i], idx[i] = i;
    sort(idx+1,idx+n+1,cmp);
    for(int i = 1;i <= n;i++) {
        if(c[idx[i]]) continue;
        int L = idx[i], R = idx[i]+1;
        while(L >= 1&&!c[L]&&a[L] >= a[idx[i]]&&a[L] <= a[idx[i]]+k) c[L--] = 1;
        while(R <= n&&!c[R]&&a[R] >= a[idx[i]]&&a[R] <= a[idx[i]]+k) c[R++] = 1;
        ans++;
    }
    cout << ans;
}