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
const int mod = 1e9+7;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int a[3005][3005];
int n;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 0;i < n;i++) a[n+i][1] = a[n+i][n] = 1;
	for(int i = 1;i <= n;i++) a[n][i] = a[2*n-1][i] = 1;
	for(int i = 1;i <= n;i++) a[i][n-i+1] = a[n+i-1][2*n-i] = 1;
	for(int i = 1;i < n;i++) a[1][n+i] = a[i][n*2-1] = 1;
	for(int i = 1;i < n*2;i++) {
		for(int j = 1;j < n*2;j++) {
			if(a[i][j]) cout << "*";
			else cout << " ";
		}
		cout << '\n';
	}
} 
