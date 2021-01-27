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
int n,ans,a[300005];
int d[300005][65];
// d[i][j] : i번째 자리에서 부터 j 하나만 만들때 어디까지 뻗어야 하는가

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= 64;i++) {
		for(int j = 1;j <= n;j++) {
			if(a[j] == i) d[j][i] = j;
			else d[j][i] = d[(d[j][i-1]?d[j][i-1]:-1)+1][i-1];
			if(d[j][i]) ans = i;
		}
	}
	cout << ans;
}