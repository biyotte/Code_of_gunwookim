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
const long long llINF = 1e18+10;
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
int n,a[15],ans;
ll d[15][15],L;

int Ch() {
    for(int i = 1)
}

void Go(int x,int idx) {
    if(x == n/2+1) {
        ans |= Ch();
        return;
    }
    for(int i = idx+1;i <= n;i++) {
        a[x] = i;
        Go(x+1,i);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> L;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) cin >> d[i][j];
    }
    Go(1,0);
}
