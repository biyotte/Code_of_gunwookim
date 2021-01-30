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
int n,wt[300005],cnt;
int c1[300005],c2[300005],ans1[300005],ans2[300005];
char a[300005];
vec t;

void dfs(int x,int ev) {
	if((ev&1?c1[x]:c2[x])) return;
	(ev&1?c1[x]:c2[x]) = 1; cnt++;
	t.pb(x);
	if(x > 1&&wt[x-1] == ev) dfs(x-1,ev);
	if(x < n+1&&wt[x] == ev) dfs(x+1,ev);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); 
	int T; cin >> T;
	while(T--) {
		cin >> n >> a+1;
		for(int i = 1;i <= n+1;i++) c1[i] = c2[i] = 0;
		for(int i = 1;i <= n;i++) {
			if(i & 1) {
				if(a[i] == 'L') wt[i] = 2;
				else wt[i] = 1;
			}
			else {
				if(a[i] == 'R') wt[i] = 2;
				else wt[i] = 1;
			}
		}
		for(int i = 1;i <= n+1;i++) {
			cnt = 0;
			if(!c1[i]) {
				t.clear();
				dfs(i,1);
				for(int j : t) ans1[j] = cnt;
			}
			cnt = 0;
			if(!c2[i]) {
				t.clear();
				dfs(i,2);
				for(int j : t) ans2[j] = cnt;
			}
		}
		for(int i = 1;i <= n+1;i++) {
			if(i % 2) cout << ans1[i] << ' '; 
			else cout << ans2[i] << ' ';
		}
		cout << '\n';
	}
}