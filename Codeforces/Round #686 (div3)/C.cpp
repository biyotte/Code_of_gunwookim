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
int n;
int a[200005];
vec v[200005];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int T; cin >> T;
	//int T = 1;
	while(T--) {
		cin >> n;
		for(int i = 1;i <= n;i++) v[i].clear();
		for(int i = 1;i <= n;i++) v[i].pb(0);
		for(int i = 1;i <= n;i++) {
			cin >> a[i];
			v[a[i]].pb(i);
		}
		for(int i = 1;i <= n;i++) v[i].pb(n+1);
		int ans = INF;
		for(int i = 1;i <= n;i++) {
			if(v[i].size() == 2) continue;
			int cnt = 0;
			for(int j = 1;j < v[i].size();j++) {
				if(v[i][j] != v[i][j-1]+1) cnt++;
			}
			ans = min(ans,cnt);
		}
		cout << ans << '\n';
	}
}
