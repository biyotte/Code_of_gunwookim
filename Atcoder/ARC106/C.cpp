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
long long mod = 1e9+7;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef vector <int> vec;
typedef vector <pi> vecpi; 
typedef long long ll;
int n,m,c[400005];
vecpi ans;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	if(m < 0||(n > 1&&m > n-2)) {
		cout << -1;
		return 0;
	}
	ans.pb({1,4+2*m});
	c[1] = c[4+2*m] = 1;
	for(int i = 1,j = 2;j <= n;j++) {
		while(c[i]) i++;
		int t1 = i;
		c[i] = 1;
		while(c[i]) i++;
		ans.pb({t1,i});
		c[i] = 1;
	}
	for(pi i : ans) {
		cout << i.x << ' ' << i.y << '\n';
	}
}