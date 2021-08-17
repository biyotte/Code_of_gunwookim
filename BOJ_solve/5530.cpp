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
int n;
char a[1000005];

bool isok(int mid) {
    int cnt = 0, c1 = 0, c2 = 0, c3 = 0;
    for(int i = n;i >= 1;i--) {
        if(a[i] == 'I') {
            if(++cnt <= mid) c1++;
            else if(c2) c2--, c3++;
        }
        if(a[i] == 'O'&&c1) c1--, c2++;
        if(a[i] == 'J'&&c2) c2--, c3++;
    }
    return (c3 >= mid);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> a+1;
    int l = 0, r = n;
    while(l < r) {
        int mid = (l + r + 1) >> 1;
        if(isok(mid)) l = mid;
        else r = mid-1;
    }
    cout << l;
}