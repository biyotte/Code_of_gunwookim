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
const int MAXN = 100000;
const int MAXM = 1000000;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n;
char a[100005][5];

int d(int x,int y) {
	return (a[x][1] != a[y][1])+(a[x][2] != a[y][2])+(a[x][3] != a[y][3])+(a[x][4] != a[y][4]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while(T--) {
		cin >> n;
		for(int i = 1;i <= n;i++) {
			cin >> a[i]+1;
		}
		if(n > 256) {
			cout << "0\n";
			continue;
		}
		int ans = INF;
		for(int i = 1;i <= n;i++) {
			for(int j = i+1;j <= n;j++) {
				for(int k = j+1;k <= n;k++) {
					ans = min(ans,d(i,j)+d(j,k)+d(k,i));
				}
			}
		}
		cout << ans << '\n';
	}
}