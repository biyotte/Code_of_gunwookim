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
int a[100005];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	//int T; cin >> T;
	int T = 1;
	while(T--) {
		cin >> n;
		for(int i = 1;i <= n;i++) cin >> a[i];
		sort(a+1,a+n+1);
		int ch = 0;
		a[n+1] = INF;
		for(int i = 1;i <= n+1;i++) {
			if(a[i] == a[i-1]||a[i] == a[i-1]+1) continue;
			if(a[i]-a[i-1] >= 3||(a[i]-a[i-1] == 2&&ch)) {
				cout << a[i-1]+1;
				return 0;
			}
			else if(a[i]-a[i-1] == 2) ch = 1;
		}
	}
}