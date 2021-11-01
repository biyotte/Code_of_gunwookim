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
int bit;
int a[1000005],b[1000005],an,bn;
vector <char> print;

void Print(int x) {
    print.clear();
    while(x) {
        print.pb(x%2+'0');
        x /= 2;
    }
    reverse(all(print));
    for(char j : print) cout << j;
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(0);
    for(bit = 1;1;bit++) {
        int la = -1;
        int tmp = bit,no = 0;
        while(tmp) {
            int bi = tmp%2;
            if(la == bi) {
                if(bi) no |= 2;
                else no |= 1;
            }
            la = bi;
            tmp /= 2;
        }
        int mn = min(an,bn);
        if(!(no&1)) a[++an] = bit;
        if(!(no&2)) b[++bn] = bit;
        if(mn^min(an,bn)) {
            int idx = min(an,bn);
            cout << idx << " : ";
            Print(a[idx]);
            cout << ' ';
            Print(b[idx]);
            
            cout << '\n';
        }
    }
}