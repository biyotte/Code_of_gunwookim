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
int g = 1,n;
int a[2105],sum[2105];
vector <int> idx[2105];

void choice(int sz,vec v) {
    g *= 2;
    if(sz == 1) {
        for(int i : idx[v[0]]) {
            cout << a[i] << ' ';
        }
        exit(0);
    }
    vec nv;
    int A,B,C;
    A = v[0];
    for(int i = 1;i < sz;i += 2) {
        B = v[i], C = v[i+1];
        if((sum[A]+sum[B])%g == 0) {
            for(int j : idx[B]) idx[A].pb(j);
            nv.pb(A);
            sum[A] += sum[B];
            A = C;
        }
        else if((sum[A]+sum[C])%g == 0) {
            for(int j : idx[C]) idx[A].pb(j);
            nv.pb(A);
            sum[A] += sum[C];
            A = B;
        }
        else if((sum[B]+sum[C])%g == 0) {
            for(int j : idx[C]) idx[B].pb(j);
            nv.pb(B);
            sum[B] += sum[C];
        }
    }
    choice(sz/2,nv);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for(int i = 1;i < 2*n;i++) cin >> a[i], sum[i] = a[i], idx[i].pb(i);
    vec ans;
    for(int i = 1;i < 2*n;i++) ans.pb(i);
    choice(n*2-1,ans);
}