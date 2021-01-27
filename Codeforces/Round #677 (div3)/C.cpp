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
int n;
int a[300005];
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	//int T = 1;
	while(T--) {
		cin >> n;
		int mx = 0,st = 0,en = 0;
		for(int i = 1;i <= n;i++) {
			cin >> a[i];
			mx = max(mx,a[i]);
		}
		a[0] = a[n+1] = INF;
		int ch = -1;
		for(int i = 1;i <= n;i++) {
			if(a[i] == mx) {
				if(a[i-1] < a[i]||a[i] > a[i+1]) ch = i;
			}
		}
		cout << ch << '\n';
	}
}