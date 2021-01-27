#include <bits/stdc++.h>
#define x first
#define w second
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
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pl;
typedef pair <ll,ll> pi;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,m;
int t[300005],a[300005];
vec rev,veg[300005];

void update(int x) {
	for(;x <= n;x += x&-x) t[x]++;
}

int query(int l,int r) {
	int ret = 0;
	for(;r;r -= r&-r) ret += t[r];
	for(l--;l;l -= l&-l) ret -= t[l];
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i], rev.pb(a[i]);
	sort(all(rev)), rev.erase(unique(all(rev)),rev.end());
	m = rev.size();
	for(int i = 1;i <= n;i++) {
		a[i] = lower_bound(all(rev),a[i])-rev.begin()+1;
		veg[a[i]].pb(i);
	}
	ll ans = 0;
	for(int i = m;i >= 1;i--) {
		for(int idx : veg[i]) {
			ans += min(query(1,idx++),query(idx+1,n));
		}
		for(int idx : veg[i]) update(idx);
	}
	cout << ans;
}