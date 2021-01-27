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
const long long mod = 998244353;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,k,mx,res,dep[100005];
vec v[100005];

int dfs(int x,int pr) {
	if((int)v[x].size() == 1&&x != 1) {
		return dep[x] = 1;
	}
	vec v2;
	for(int i : v[x]) {
		if(i == pr) continue;
		int tmp = dfs(i,x);
		if(tmp > mx) res++, tmp = 0;
		v2.pb(tmp);
	}
	sort(all(v2));
	for(int i = (int)v2.size()-1;i > 0;i--) {
		if(v2[i]+v2[i-1] > mx) res++, v2[i] = 0;
	}
	int Max = 0;
	for(int i : v2) {
		Max = max(Max,i);
	}
	return dep[x] = Max+1;
}

bool isok(int mid) {
	mx = mid, res = 0;
	dfs(1,-1);
	return (res <= k);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); 
	cin >> n >> k;
	for(int i = 1;i < n;i++) {
		int x,y; cin >> x >> y;
		v[x].pb(y), v[y].pb(x);
	}
	int l = 0, r = n;
	while(l < r) {
		int mid = (l + r) >> 1;
		if(isok(mid)) r = mid;
		else l = mid+1;
	}
	cout << l;
}