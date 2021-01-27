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
ll n;
ll c[205][205];
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); 
	cin >> n;
	for(int i = 1;i <= 200;i++) c[i][0] = c[i][i] = 1;
	for(int i = 1;i <= 200;i++) {
		for(int j = 1;j < i;j++) {
			c[i][j] = c[i-1][j]+c[i-1][j-1];
		}
	} 
	cout << c[n-1][11];
}