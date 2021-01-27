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
int p[10005];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	//int T = 1;
	for(int i = 2;i <= 3000;i++) {
		p[i] = 1;
		for(int j = 2;j < i;j++) {
			if(i % j == 0) p[i] = 0;
		}
	}
	while(T--) {
		cin >> n;
		int ch = 0;
		for(int i = 1;i <= 3000;i++) {
			for(int j = 1;j <= 3000;j++) {
				if(!p[i]&&!p[j]&&p[i*(n-1)+j]) {
					for(int x = 1;x <= n;x++) {
						for(int y = 1;y <= n;y++) {
							if(x == y) cout << j << ' ';
							else cout << i << ' ';
						}
						cout << '\n';
					}
					ch = 1;
				}
				if(ch) break;
			}
			if(ch) break;
		}
	}
}