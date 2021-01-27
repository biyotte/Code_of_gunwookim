#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define all(v) v.begin(),v.end()
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
using namespace std;
const long long INF = 1e9;
const int TMX = 1 << 18;
const long long llINF = 1e18;
const long long mod = 1e9+7;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int num[10] = {1,0,0,0,1,0,1,0,2,1};
int dig[10] = {1,1,1,1,2,2,1,2,1,1};


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
    for(int i = 1;i <= 1000;i++) {
        for(int j = 18;j <= 1000;j++) {
            if(89*i % j == 17&&8*i % j == 3) cout << i << ' ' << j << " : " << 89*i << ' ' << 8*i << ' ' << 56*i % j << '\n';
        }
    }
}
