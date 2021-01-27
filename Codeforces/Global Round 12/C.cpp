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
char in[305][305];
int n,p[3],a[305][305];
int b[305][305];
char ans[305][305];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); 
	int T; cin >> T;
	while(T--) {
		cin >> n;
		int sum = 0;
		for(int i = 1;i <= n;i++) {
			cin >> in[i]+1;
			for(int j = 1;j <= n;j++) {
				if(in[i][j] == 'O') sum++, a[i][j] = 0;
				else if(in[i][j] == 'X') sum++, a[i][j] = 1;
				else a[i][j] = 2;
			}
		}
		int ch = 0;
		for(int op = 0;op < 2;op++) {
			for(int i = 1;i <= n;i++) {
				for(int j = 1;j <= n;j++) {
					if(!op) b[i][j] = (i+j)%3;
					else b[i][j] = ((i-j)%3+3)%3;
				}
			}
			int calc;
			for(int bit = 1;bit < 7;bit++) {
				calc = 0;
				for(int j = 0;j < 3;j++) {
					if(bit & (1 << j)) p[j] = 1;
					else p[j] = 0;
				}
				for(int no = 0;no < 3;no++) {
					if(!no&&p[1] == p[2]) continue;
					if(no == 1&&p[0] == p[2]) continue;
					if(no == 2&&p[0] == p[1]) continue;
					for(int i = 1;i <= n;i++) {
						for(int j = 1;j <= n;j++) {
							if(b[i][j] != no&&p[b[i][j]] != a[i][j]&&a[i][j] != 2) calc++;
						}
					}
					for(int i = 1;i <= n;i++) {
						for(int j = 1;j <= n;j++) {
							if(a[i][j] == 2) ans[i][j] = '.';
							else {
								if(b[i][j] == no) ans[i][j] = in[i][j];
								else if(p[b[i][j]]) ans[i][j] = 'X';
								else ans[i][j] = 'O';
							}
						}
					}
					if(calc <= sum/3) {
						//cout << calc << ' ' << no << ' ' << p[0] << ' ' << p[1] << ' ' << p[2] << '\n';
						int rans = 0;
						for(int i = 1;i <= n;i++) {
							for(int j = 1;j <= n;j++) {
								cout << ans[i][j];
								if(ans[i][j] != in[i][j]) rans++;
							}
							cout << '\n';
						}
						if(rans != calc) return -1;
						ch = 1;
						break;
					}
				}
				if(ch) break;
			}
			if(ch) break;
		}
		if(!ch) return -1;
	}
}