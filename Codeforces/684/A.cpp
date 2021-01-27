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
const long long mod = 1e9+7;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,m;
char a[105][105],b[105][105];

struct Ans {
	int x1,y1,x2,y2,x3,y3;
};
vector<Ans> ans;

void make(int j,int i,int pl) {
	if(j^n) {
		if(pl == 0) {
			swap(i,j);
			if(j^m) {
				ans.pb({i,j,i+1,j,i+1,j+1});
				a[i][j] = '0';
				if(a[i+1][j] == '0') a[i+1][j] = '1';
				else a[i+1][j] = '0';
				if(a[i+1][j+1] == '0') a[i+1][j+1] = '1';
				else a[i+1][j+1] = '0';
			}
			else {
				ans.pb({i,m,i+1,m,i+1,m-1}), a[i][m] = '0';
				if(a[i+1][m] == '0') a[i+1][m] = '1';
				else a[i+1][m] = '0';
				if(a[i+1][m-1] == '0') a[i+1][m-1] = '1';
				else a[i+1][m-1] = '0';
			}
		}
		if(pl == 1) {
			ans.pb({j,i,j+1,i,j+1,i+1});
			ans.pb({j,i+1,j+1,i,j+1,i+1});
			a[j][i] = a[j][i+1] = '0';
		}
		if(pl == 2) {
			ans.pb({j,i,j+1,i+1,j,i+1});
			ans.pb({j,i+2,j+1,i+1,j,i+1});
			a[j][i] = a[j][i+2] = '0';
		}
		if(pl == 3) {
			ans.pb({j,i,j+1,i+1,j,i+1});
			ans.pb({j+1,i+1,j,i+1,j,i+2});
			ans.pb({j,i+2,j+1,i+2,j+1,i+3});
			ans.pb({j+1,i+2,j+1,i+3,j,i+3});
			a[j][i] = a[j][i+3] = '0';
		}
		if(pl == 4) {
			ans.pb({j,i,j+1,i+1,j,i+1});
			ans.pb({j+1,i+1,j,i+1,j,i+2});
			ans.pb({j,i+2,j+1,i+3,j,i+3});
			ans.pb({j+1,i+3,j,i+3,j,i+4});
			a[j][i] = a[j][i+4] = '0';
		}
	}
	else {
		if(pl == 0) {
			if(i^m) {
				ans.pb({n,i,n-1,i,n-1,i+1});
				ans.pb({n-1,i+1,n,i+1,n,i});
				ans.pb({n,i,n-1,i,n,i+1});
				a[n][i] = '0';
			}
			else {
				ans.pb({n,i,n-1,i,n-1,i-1});
				ans.pb({n-1,i-1,n,i-1,n,i});
				ans.pb({n,i,n-1,i,n,i-1});
				a[n][i] = '0';
			}
		}
		if(pl == 1) {
			ans.pb({n,i,n-1,i,n-1,i+1});
			ans.pb({n,i+1,n-1,i,n-1,i+1});
			a[n][i] = a[n][i+1] = '0';
		}
		if(pl == 2) {
			ans.pb({n,i,n-1,i+1,n,i+1});
			ans.pb({n,i+2,n-1,i+1,n,i+1});
			a[n][i] = a[n][i+2] = '0';
		}
		if(pl == 3) {
			ans.pb({n,i,n-1,i+1,n,i+1});
			ans.pb({n-1,i+1,n,i+1,n,i+2});
			ans.pb({n,i+2,n-1,i+2,n-1,i+3});
			ans.pb({n-1,i+2,n-1,i+3,n,i+3});
			a[n][i] = a[n][i+3] = '0';
		}
		if(pl == 4) {
			ans.pb({n,i,n-1,i+1,n,i+1});
			ans.pb({n-1,i+1,n,i+1,n,i+2});
			ans.pb({n,i+2,n-1,i+3,n,i+3});
			ans.pb({n-1,i+3,n,i+3,n,i+4});
			a[n][i] = a[n][i+4] = '0';
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	srand(time(NULL));
	while(T--) {
		cin >> n >> m;
		//n = rand()%5+2, m = rand()%5+2;
		ans.clear();
		for(int i = 1;i <= n;i++) {
			cin >> a[i]+1;
			#if 0
			for(int j = 1;j <= m;j++) {
				int tm = rand()%2;
				a[i][j] = b[i][j] = tm+'0';
			}
			#endif
		}
		for(int j = 1;j < n;j++) {
			for(int i = 1;i <= m;i++) {
				if(a[j][i] == '1') {
					if(i <= m-1&&a[j][i+1] == '1') {
						if(a[j+1][i] == '1') {
							ans.pb({j,i,j,i+1,j+1,i});
							a[j][i] = a[j][i+1] = a[j+1][i] = '0';
						}
						else if(a[j+1][i+1] == '1') {
							ans.pb({j,i,j,i+1,j+1,i+1});
							a[j][i] = a[j][i+1] = a[j+1][i+1] = '0';
						}
						else make(j,i,1);
					}
					else if(i <= m-2&&a[j][i+2] == '1') {
						make(j,i,2);
					}
					else {
						make(j,i,0);
					}
				}
			}
		}
		for(int i = 1;i <= m;i++) {
			if(a[n][i] == '1') {
				if(i <= m-1&&a[n][i+1] == '1') {
					make(n,i,1);
				}
				else if(i <= m-2&&a[n][i+2] == '1') {
					make(n,i,2);
				}
				else if(i <= m-3&&a[n][i+3] == '1') {
					if(i+3 <= m-1&&a[n][i+4] == '1') {
						make(n,i+3,1);
						make(n,i,0);
					}
					else if(i+3 <= m-2&&a[n][i+5] == '1') {
						make(n,i+3,2);
						make(n,i,0);
					}
					else {
						make(n,i,3);
					}
				}
				else if(i <= m-4&&a[n][i+4] == '1') {
					if(i+4 <= m-1&&a[n][i+5] == '1') {
						make(n,i+4,1);
						make(n,i,0);
					}
					else if(i+4 <= m-2&&a[n][i+6] == '1') {
						make(n,i+4,2);
						make(n,i,0);
					}
					else {
						make(n,i,4);
					}
				}
				else {
					make(n,i,0);
				}
			}
		}
		#if 0
		if(ans.size() > n*m) {
			cout << n << ' ' << m << '\n';
			for(int i = 1;i <= n;i++) {
				for(int j = 1;j <= m;j++) cout << b[i][j];
				cout << '\n';
			}
			break;
		}
		continue;
		#endif
		cout << ans.size() << '\n';
		for(auto i : ans) {
			cout << i.x1 << ' ' << i.y1 << ' ' << i.x2 << ' ' << i.y2 << ' ' << i.x3 << ' ' << i.y3 << '\n';
		}
	}
}
