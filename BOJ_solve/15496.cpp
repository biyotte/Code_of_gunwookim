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
ll d[2005][30][30],com[2005][2005];
char a[2005];
int n,Q,cnt[2005][30];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> a+1; n = strlen(a+1);
	for(int i = n;i >= 1;i--) {
		for(int j = 0;j < 26;j++) {
			cnt[i][j] = cnt[i+1][j]+((a[i]-'a') == j);
		}
	}
	for(int i = 0;i <= n;i++) {
		com[i][0] = 1;
		if(!i) continue;
		for(int j = 1;j <= n;j++) {
			com[i][j] = (com[i-1][j]+com[i-1][j-1])%mod;
		}
	}
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) {
			for(int k = 0;k < 26;k++) {
				if(j-1 < i-2) break;
				d[i][a[j]-'a'][k] = (d[i][a[j]-'a'][k]+com[j-1][i-2]*cnt[j+1][k]%mod)%mod;
			}
		}
	}
	cin >> Q;
	while(Q--) {
		int x; char y,z;
		cin >> x >> y >> z;
		cout << d[x][y-'a'][z-'a'] << '\n';
	}
}
