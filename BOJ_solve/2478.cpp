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
const long long llINF = 2e18;
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
int n,a[505],c[505];

void Shift(int x) {
    if(x < 0) {
        x *= -1;
        x = n-x;
    }
    reverse(a+1,a+x+1);
    reverse(a+x+1,a+n+1);
    reverse(a+1,a+n+1);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for(int i = 1;i < n;i++) {
        Shift(-i);
        int cn = 0;
        memset(c,0,sizeof(c));
        int sh = 0;
        for(int j = 1;j <= n;j++) {
            if(a[j]+1 == a[j%n+1]||a[(j-2+n)%n+1]+1 == a[j]) {
                c[j] = 1;
                cn++;
            }
        }
        if(!cn) {
            reverse(a+1,a+n+1);
            int wi;
            for(int j = 1;j <= n;j++) {
                if(a[j] == 1) {
                    wi = j;
                    break;
                }
            }
            if(wi == 1) {Shift(i); continue;}
            cout << n-wi+1 << '\n' << "1 " << n << '\n' << i;
            return 0;
        }
        int l = n, r = 1;
        for(int j = 1;j <= n;j++) {
            if(!c[j]) {
                l = min(l,j);
                r = max(r,j);
            }
        }
        reverse(a+l,a+r+1);
        int wi;
        for(int j = 1;j <= n;j++) {
            if(a[j] == 1) {
                wi = j;
                break;
            }
        }
        if(wi^1) {
            Shift(wi-1);
            int ch = 0;
            for(int j = 1;j <= n;j++) {
                if(a[j]^j) {
                    ch = 1;
                    break;
                }
            }
            if(ch) {
                Shift(-(wi-1));
                reverse(a+l,a+r+1);
                Shift(i);
                continue;
            }
            cout << n-wi+1 << '\n' << l << ' ' << r << '\n' << i;
            return 0;
        }
        reverse(a+l,a+r+1);
        Shift(i);
    }
}