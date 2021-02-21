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
const int MAXN = 20000;
const int MAXM = 4000000;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pl;
typedef pair <ll,ll> pi;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int a[105];
int n,ans[105];

void dfs(int l,int r,int dep) {
	if(l > r) return;
	int idx = l;
	for(int i = l;i <= r;i++) {
		if(a[idx] < a[i]) idx = i;
	}
	ans[idx] = dep;
	dfs(l,idx-1,dep+1), dfs(idx+1,r,dep+1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while(T--) {
		cin >> n;
		for(int i = 1;i <= n;i++) cin >> a[i];
		dfs(1,n,0);
		for(int i = 1;i <= n;i++) cout << ans[i] << ' ';
		cout << '\n';
	}
}

for(int i = 0;i < 21;i++) {
	for(int j = 0;j < 20;j++) arr[i][j] = 0;
}