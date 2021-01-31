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
const long long llINF = 1e18;
const long long mod = 1999;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,num[3005];
char a[3005][3005];
int p[15];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for(int i = 2;i <= n;i++) cin >> a[i]+1;
    for(int i = 1;i <= 7;i++) p[i] = 1;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= 14;j++) {
            if(p[j]) num[i] |= (1 << j);
        }
        next_permutation(p+1,p+15);
    }
    for(int i = 2;i <= n;i++) {
        for(int j = 1;j < i;j++) {
            for(int l = 1;l <= 14;l++) {
                if(a[i][j]-'0') {
                    if((num[i] & (1 << l))&&!(num[j] & (1 << l))) {
                        cout << (char)('a'+l-1);
                        break;
                    }
                }
                else {
                    if((num[j] & (1 << l))&&!(num[i] & (1 << l))) {
                        cout << (char)('a'+l-1);
                        break;
                    }
                }
            }
        }
        cout << '\n';
    }
}
