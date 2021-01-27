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
int n,r[100005],c[100005];
int a[100005],go;
stack <int> nam2,nam1;
stack <pi> g2,g3;
vecpi ans;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	//int T; cin >> T;
	int T; T = 1;
	while(T--) {
		cin >> n;
		for(int i = 1;i <= n;i++) cin >> a[i];
		for(int i = 1;i <= n;i++) {
			nam2.push(n-i+1);
		}
		for(int i = 1;i <= n;i++) {
			if(!a[i]) c[i] = 0;
			else {
				c[i] = 1;
				if(a[i] == 1) {
					if(!g2.empty()) {
						pi x = g2.top(); g2.pop();
						ans.pb({x.x,i});
						if(x.y) {
							if(nam2.empty()) {
								cout << -1;
								return 0;
							}
							int y = nam2.top(); nam2.pop();
							ans.pb({y,i});
							nam1.push(y);
						}
					}
					else if(!g3.empty()) {
						pi x = g3.top(); g3.pop();
						ans.pb({x.x,i});
						if(x.y) {
							if(nam2.empty()) {
								cout << -1;
								return 0;
							}
							int y = nam2.top(); nam2.pop();
							ans.pb({y,i});
							nam1.push(y);
						}
					}
					else {
						if(!nam1.empty()) {
							int y = nam1.top(); nam1.pop();
							ans.pb({y,i});
						}
						else {
							if(nam2.empty()) {
								cout << -1;
								return 0;
							}
							int y = nam2.top(); nam2.pop();
							ans.pb({y,i});
						}
					}
				}
				else {
					if(!g3.empty()) {
						pi x = g3.top(); g3.pop();
						ans.pb({x.x,i});
						if(x.y) {
							if(nam2.empty()) {
								cout << -1;
								return 0;
							}
							int y = nam2.top(); nam2.pop();
							ans.pb({y,i});
							if(a[i]-2) g3.push({y,a[i]-2});
							else g2.push({y,a[i]-2});
						}
					}
					else {
						if(nam2.empty()) {
							cout << -1;
							return 0;
						}
						int y = nam2.top(); nam2.pop();
						ans.pb({y,i});
						if(a[i]-2) g3.push({y,a[i]-2});
						else g2.push({y,a[i]-2});
					}
				}
			}
		}
		if(!g2.empty()||!g3.empty()) {
			cout << -1;
			return 0;
		}
		cout << ans.size() << '\n';
		for(pi i : ans) {
			cout << i.x << ' ' << i.y << '\n';
		}
	}
}