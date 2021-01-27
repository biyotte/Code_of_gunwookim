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
//long long mod;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi; 
typedef long long ll;
int n,m,a[1005][1005];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= m;i++) {
		int x,y; cin >> x >> y;
		a[x][y] = a[y][x] = 1;
	}
	for(int i = 2;i <= n;i++) {
		if(!a[1][i]) {
			for(int j = 1;j <= n;j++) {
				if(i == j) continue;
				if(a[i][j]) a[i][j] = a[j][i] = 0;
				else a[i][j] = a[j][i] = 1;
			}
		}
	} 
	for(int i = 1;i <= n;i++) {
		int cnt = 0;
		for(int j = 1;j <= n;j++) cnt += a[i][j];
		if(cnt != n-1) {
			cout << "NE";
			return 0;
		}
	}
	cout << "DA";
}