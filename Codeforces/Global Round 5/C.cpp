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
const long long mod = 11092019;
const long long hashmod = 100003;
const int MAXN = 20000;
const int MAXM = 4000000;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,c[50005];
map <int,set<pi>> v;
map <pi,set<pi>> v2;

struct Point {
	int x,y,z,idx;
}a[50005],ra[50005];

set <pi> s;

bool cmp(Point x,Point y) {
	if(x.x != y.x) return x.x < y.x;
	if(x.y != y.y) return x.y < y.y;
	return x.z < y.z;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) {
		cin >> a[i].x >> a[i].y >> a[i].z;
		a[i].idx = i;
		ra[i] = a[i];
		v[a[i].y].insert({a[i].z,i});
		v2[{a[i].y,a[i].z}].insert({a[i].x,i});
		s.insert({a[i].y,a[i].idx});
	}
	sort(a+1,a+n+1,cmp);
	for(int i = 1;i <= n;i++) {
		if(c[a[i].idx]) continue;
		s.erase({a[i].y,a[i].idx});
		v[a[i].y].erase({a[i].z,a[i].idx});
		v2[{a[i].y,a[i].z}].erase({a[i].x,a[i].idx});
		auto it = s.lower_bound({a[i].y,0});

		if(s.empty()) while(1);

		if(it == s.end()) it--;

		int y = it->x;
		auto itz = v[y].lower_bound({a[i].z,0});

		if(v[y].empty()) while(1);

		if(itz == v[y].end()) itz--;

		int z = itz->x;

		if(v2[{y,z}].empty()) while(1);

		pi itx = *v2[{y,z}].begin();
		int idx = itx.y;
		c[idx] = 1;
		cout << a[i].idx << ' ' << idx << '\n';
		s.erase({ra[idx].y,ra[idx].idx});
		v[ra[idx].y].erase({ra[idx].z,ra[idx].idx});
		v2[{ra[idx].y,ra[idx].z}].erase({ra[idx].x,ra[idx].idx});
	}
}
