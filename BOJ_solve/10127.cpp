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
int n,k,m,l;
int a[1000005];
vec v[1000005];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
		v[a[i]].pb(i);
	}
	cin >> m >> l;
	int st = 1,en = n;
	for(int i = 1;i <= m;i++) {
		int x; cin >> x;
		int it = upper_bound(all(v[x]),st)-v[x].begin();
		if(it == v[x].size()) {
			cout << "0\n";
			return 0;
		}
		st = v[x][it];
	}
	for(int i = 1;i <= l;i++) {
		int x; cin >> x;
		int it = lower_bound(all(v[x]),en)-v[x].begin()-1;
		if(it == -1) {
			cout << "0\n";
			return 0;
		}
		en = v[x][it];
	}
	vec ans;
	for(int i = st;i <= en;i++) if(a[i] == a[st]) ans.pb(i);
	cout << ans.size() << '\n';
	for(int i : ans) cout << i << ' ';
}
