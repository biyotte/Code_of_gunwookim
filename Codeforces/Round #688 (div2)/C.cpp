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
const long long llINF = 1e18;
const long long mod = 998244353;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
char a[2005][2005];
int n,l,r,an[10];



int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--) {
		cin >> n;
		for(int i = 1;i <= n;i++) cin >> a[i]+1;
		for(int d = 0;d < 10;d++) {
			int Lx = -1,Ly = -1,Rx = -1,Ry = -1;
			for(int i = 1;i <= n;i++) {
				for(int j = 1;j <= n;j++) {
					if(a[i][j] == d+'0') {
						Lx = i; break;
					}
				}
				if(Lx != -1) break;
			}
			for(int i = 1;i <= n;i++) {
				for(int j = 1;j <= n;j++) {
					if(a[j][i] == d+'0') {
						Ly = i; break;
					}
				}
				if(Ly != -1) break;
			}
			for(int i = n;i >= 1;i--) {
				for(int j = 1;j <= n;j++) {
					if(a[i][j] == d+'0') {
						Rx = i; break;
					}
				}
				if(Rx != -1) break;
			}
			for(int i = n;i >= 1;i--) {
				for(int j = 1;j <= n;j++) {
					if(a[j][i] == d+'0') {
						Ry = i; break;
					}
				}
				if(Ry != -1) break;
			}
			if(Lx == -1) {
				cout << "0 ";
				continue;
			}
			int ans = 0;
			for(int i = Lx;i <= n;i++) {
				for(int j = 1;j <= n;j++) {
					if(a[i][j] == d+'0') {
						ans = max(ans,(i-Lx)*max(j-1,n-j));
					}
				}
			}
			for(int i = Ly;i <= n;i++) {
				for(int j = 1;j <= n;j++) {
					if(a[j][i] == d+'0') {
						ans = max(ans,(i-Ly)*max(j-1,n-j));
					}
				}
			}
			for(int i = Rx;i >= 1;i--) {
				for(int j = 1;j <= n;j++) {
					if(a[i][j] == d+'0') {
						ans = max(ans,(Rx-i)*max(j-1,n-j));
					}
				}
			}
			for(int i = Ry;i >= 1;i--) {
				for(int j = 1;j <= n;j++) {
					if(a[j][i] == d+'0') {
						ans = max(ans,(Ry-i)*max(j-1,n-j));
					}
				}
			}
			cout << ans << ' ';
		}
		cout << '\n';
    }
}