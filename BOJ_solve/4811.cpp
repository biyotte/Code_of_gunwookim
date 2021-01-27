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
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,m;
ll c[35];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); 
	c[0] = 1;
	for(int i = 1;i <= 30;i++) {
		for(int j = i-1;j >= 0;j--) {
			c[i] += c[j]*c[i-j-1];
		}
	}
    while(1) {
    	cin >> n;
    	if(!n) break;
    	cout << c[n] << '\n';
    }
}