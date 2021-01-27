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
const int TMX = 1 << 18;
const long long llINF = 5e18;
const long long mod = 1e9+7;
const long long hmod1 = 1e9+409;
const long long hmod2 = 1e9+433;
const long long base = 257;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,Q;
char a[105];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int T; cin >> T;
	//int T = 1;
	while(T--) {
		cin >> n >> Q;
		cin >> a+1;
		while(Q--) {
			int l,r,g = 1; cin >> l >> r;
			for(int i = l-1;i;i--) {
				if(a[l] == a[i]) g = 0;
			}
			for(int i = r+1;i <= n;i++) {
				if(a[r] == a[i]) g = 0;
			}
			cout << (g ? "NO" : "YES") << '\n';
		}	
	}
}
