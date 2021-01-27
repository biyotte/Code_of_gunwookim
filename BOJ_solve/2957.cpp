#include <bits/stdc++.h>
#define x first
#define y second
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast")
#pragma gcc optimize("unroll-loops")
using namespace std;
const long long INF = 1e18;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
int n,a[300005];
ll d[300005];
set <int> s;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	s.insert(0); s.insert(n+1);
	ll ans = 0;
	for(int i = 1;i <= n;i++) {
		auto it = s.upper_bound(a[i]);
		auto it2 = it; it--;
		d[a[i]] = max(d[*it],d[*it2])+1;
		ans += d[a[i]]-1;
		s.insert(a[i]);
		cout << ans << '\n';
	}
}