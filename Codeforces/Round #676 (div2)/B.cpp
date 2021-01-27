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
char a[205][205];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	//int T = 1;
	while(T--) {
		cin >> n;
		for(int i = 1;i <= n;i++) cin >> a[i]+1;
		int u,l,r,d;
		u = (a[1][2] == '1');
		l = (a[2][1] == '1');
		r = (a[n-1][n] == '1');
		d = (a[n][n-1] == '1');
		vecpi ans;
		if(u == l&&r == d&&u^d) {
			cout << "0\n";
			continue;
		}
		if(u == 0&&l == 0) {
			if(r == 0) ans.pb({n-1,n});
			if(d == 0) ans.pb({n,n-1});
		}
		else if(r == 0&&d == 0) {
			if(l == 0) ans.pb({2,1});
			if(u == 0) ans.pb({1,2});
		}
		else {
			if(l == 1) ans.pb({2,1});
			if(u == 1) ans.pb({1,2});
			if(r == 0) ans.pb({n-1,n});
			if(d == 0) ans.pb({n,n-1});
			if(ans.size() >= 3) {
				ans.clear();
				if(l == 0) ans.pb({2,1});
				if(u == 0) ans.pb({1,2});
				if(r == 1) ans.pb({n-1,n});
				if(d == 1) ans.pb({n,n-1});
			}
		}
		cout << ans.size() << '\n';
		for(pi i : ans) cout << i.x << ' ' << i.y << '\n';
	}
}