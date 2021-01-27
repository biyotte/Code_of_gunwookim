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
int a[200005],b[200005],p[200005];
int inv[200005];
vecpi v,ans;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i], v.pb({a[i],i});
	for(int i = 1;i <= n;i++) cin >> b[i];
	for(int i = 1;i <= n;i++) cin >> p[i], inv[p[i]] = i;
	sort(all(v));
	for(pi i : v) {
		int x = i.x, idx = i.y;
		if(p[idx] == idx) continue;
		if(x <= b[p[idx]]) {
			cout << -1;
			return 0;
		}
		ans.pb({idx,inv[idx]});
		p[inv[idx]] = p[idx], inv[p[idx]] = inv[idx];
	}
	cout << ans.size() << '\n';
	for(pi i : ans) cout << i.x << ' ' << i.y << '\n';
}