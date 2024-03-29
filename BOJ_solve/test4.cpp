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
const long long llINF = 4e18+10;
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
int c[1000005];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    for(int i = 2;i <= 1000000;i++) {
        if(c[i]) continue;
        if(i > 1000) continue;
        for(int j = i*i;j <= 1000000;j += i) c[j] = 1;
    }
    int cnt = 0;
    for(int i = 2;i <= 30000;i++) {
        cnt += !c[i];
    }
    cout << cnt;
}
