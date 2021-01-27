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
char a[1005];
char b[10] = " atcoder";
int n;


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while(T--) {
		cin >> a+1;
		n = strlen(a+1);
		int ans = INF,i;
		for(i = 1;i <= 7;i++) {
			if(a[i] < b[i]) break;
			if(a[i] > b[i]) {
				ans = 0;
				break;
			}
		}
		if(i == 8&&n >= 8) ans = 0;
		for(int i = 1;i <= n;i++) {
			if(a[i] != 'a') {
				if(i == 1) {
					ans = 0;
					break;
				}
				else if(a[i] <= 't') {
					ans = min(ans,i-1);
				}
				else ans = min(ans,i-2);
			}
		}
		if(ans == INF) ans = -1;
		cout << ans << '\n';
	}
}