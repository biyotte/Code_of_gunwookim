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
const long long llINF = 2e18;
const long long mod = 1e9+7;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n;
char a[205];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while(T--) {
		cin >> n >> a+1;
		int ch = 0;
		for(int i = 1;i <= n;i++) {
			for(int j = i-1;j <= n;j++) {
				if(i-1+n-j != 4) continue;
				vector <char> c;
				for(int l = 1;l < i;l++) c.pb(a[l]);
				for(int l = j+1;l <= n;l++) c.pb(a[l]);
				if(c[0] == '2'&&c[1] == '0'&&c[2] == '2'&&c[3] == '0') ch = 1;
			}
		}
		if(ch) cout << "YES\n";
		else cout << "NO\n";
	}
}