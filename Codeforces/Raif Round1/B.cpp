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
char a[300005];
int n,c[300005];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	//int T; T = 1;
	while(T--) {
		cin >> n;
		cin >> a+1;
		int ch = 0;
		for(int i = 1;i <= n;i++) {
			c[i] = 0;
			if(a[i] == '>') ch |= 1;
			if(a[i] == '<') ch |= 2;
		}
		if(ch != 3) {
			cout << n << '\n';
		}
		else {
			int cnt = 0;
			for(int i = 1;i <= n;i++) {
				if(a[i] == '-') c[i] = c[i%n+1] = 1;
			}
			for(int i = 1;i <= n;i++) cnt += c[i];
			cout << cnt << '\n';
		}
	}
}