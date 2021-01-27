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
int n,a[100005];
int cnt[100005];
ll ans;
vec v[100005];
vec pr[100005];

void dfs(int x,int fl) {
	if(!fl) {
		ans += cnt[a[x]];
		for(int i : pr[x]) cnt[i]++;
		for(int i : v[x]) dfs(i,fl);
		for(int i : pr[x]) cnt[i]--;
	}
	else if(fl & 1) {
		for(int i : pr[x]) ans += cnt[i];
		cnt[a[x]]++;
		for(int i : v[x]) dfs(i,fl);
		cnt[a[x]]--;
	}
	else {
		ans -= cnt[a[x]];
		cnt[a[x]]++;
		for(int i : v[x]) dfs(i,fl);
		cnt[a[x]]--;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
		int x = a[i];
		for(int j = 1;j*j <= x;j++) {
			if(x % j == 0) {
				pr[i].pb(j);
				if(j*j != x) pr[i].pb(x/j);
			}
		}
	}
	for(int i = 2;i <= n;i++) {
		int x; cin >> x;
		v[x].pb(i);
	}
	dfs(1,0), dfs(1,1), dfs(1,2);
	cout << ans;
}