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
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,p[100005],mx[100005];
int a[100005];
vector <pair<int,pi>> edge;

int Find(int x) {return (x^p[x] ? p[x] = Find(p[x]) : x);}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); 
	cin >> n;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
		p[i] = i, mx[i] = a[i];
	}
	for(int i = 1;i < n;i++) {
		int x,y; cin >> x >> y;
		edge.pb({max(a[x],a[y]),{x,y}});
	}
	sort(all(edge));
	ll ans = 0;
	for(auto i : edge) {
		int x = i.y.x, y = i.y.y;
		ans += mx[Find(x)]+mx[Find(y)];
		mx[p[x]] = max(mx[p[x]],mx[p[y]]);
		p[p[y]] = p[x];
	}
	cout << ans;
}