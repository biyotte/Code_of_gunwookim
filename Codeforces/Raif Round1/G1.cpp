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
const long long llINF = 1e18;
long long mod;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi; 
typedef long long ll;
int k,n;
int d[6][1000005],s[6][1000005];
int f[10];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> k;
	for(int i = 1;i <= 6;i++) cin >> f[i];
	cin >> n;
	int g = 1000000;
	for(int i = 6;i >= 1;i--) {
		g /= 10;
		for(int j = 0;j <= n;j++) {
			d[i][j] = max({d[i+1][j],d[i][j-3]});
		}
	}
	// 미완
}