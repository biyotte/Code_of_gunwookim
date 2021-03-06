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
int a[5005];
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	//int T = 1;
	while(T--) {
		cin >> n;
		int is = 0,wi = 0;
		for(int i = 1;i <= n;i++) {
			cin >> a[i];
			if(!is) is = a[i];
			else if(is != a[i]) is = -1;
		}
		if(is != -1) {
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		for(int i = 1;i <= n;i++) {
			if(a[i] != a[1]) {
				cout << 1 << ' ' << i << '\n';
				wi = i; 
			}
		}
		for(int i = 2;i <= n;i++) {
			if(a[1] == a[i]) {
				cout << i << ' ' << wi << '\n';
			}
		}
	}
}