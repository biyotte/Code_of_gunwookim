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
const long long llINF = 1e18;
const int mod = 1e9+7;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,m,k,p[1000005];
vecpi ef,el,ans;

int Find(int x) {return (x ^ p[x] ? p[x] = Find(p[x]) : x);}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> k;
	for(int i = 1;i <= n;i++) p[i] = i;
	for(int i = 1;i <= m;i++) {
		int x,y; cin >> x >> y;
		if(x <= k||y <= k) el.pb({x,y});
		else ef.pb({x,y});
	}
	for(pi i : ef) {
		int x = i.x, y = i.y;
		if(Find(x) == Find(y)) continue;
		p[p[y]] = p[x];
	}
	for(pi i : el) {
		int x = i.x, y = i.y;
		if(Find(x) == Find(y)) {
			ans.pb(i);
			continue;
		}
		p[p[y]] = p[x];
	}
	cout << ans.size() << '\n';
	for(pi i : ans) cout << i.x << ' ' << i.y << '\n';
}
