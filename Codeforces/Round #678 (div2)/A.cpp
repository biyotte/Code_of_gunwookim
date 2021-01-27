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
long long mod = 998244353;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef vector <int> vec;
typedef vector <pi> vecpi; 
typedef long long ll;
int n;
int sum,m,a[105];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	//int T = 1;
	while(T--) {
		cin >> n >> m;
		sum = 0;
		for(int i = 1;i <= n;i++) {
			cin >> a[i];
			sum += a[i];
		}
		if(sum == m) cout << "YES\n";
		else cout << "NO\n";
	}
}