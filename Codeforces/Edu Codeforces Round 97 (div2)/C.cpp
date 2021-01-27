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
int n;
int a[205];
int d[405][205];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	//int T = 1;
	while(T--) {
		cin >> n;
		for(int i = 1;i <= n;i++) cin >> a[i];
		sort(a+1,a+n+1);
		for(int i = 0;i <= 2*n;i++) {
			for(int j = 0;j <= n;j++) {
				d[i][j] = INF;
			}
		}
		for(int i = 0;i <= 2*n;i++) d[i][0] = 0;
		for(int i = 1;i <= 2*n;i++) {
			for(int j = 1;j <= n;j++) {
				d[i][j] = min(d[i-1][j],d[i-1][j-1]+abs(i-a[j]));
			}
		}
		cout << d[2*n][n] << '\n';
	}
}