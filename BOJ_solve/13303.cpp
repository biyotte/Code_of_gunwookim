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
const long long mod = 1e18;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pl;
typedef pair <ll,ll> pi;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,sty,enx;
set <pi> s; // {위치,거리}

struct Line {
	ll x,ly,ry;
}a[100005];

bool cmp(Line x,Line y) {
	return x.x < y.x;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> sty >> enx;
	s.insert({sty,0});
	for(int i = 1;i <= n;i++) {
		cin >> a[i].x >> a[i].ly >> a[i].ry;
	}
	sort(a+1,a+n+1,cmp);
	for(int i = 1;i <= n;i++) {;
		int l = a[i].ly, r = a[i].ry;
		auto itl = s.lower_bound({l,0});
		auto itr = s.lower_bound({r+1,0});
		if(itl != itr) {
			vecpi rem;
			for(auto it = itl;it != itr;it++) rem.pb(*it);
			ll mnL = llINF,mnR = llINF;
			for(pi i : rem) {
				s.erase(i);
				mnL = min(mnL,i.y+i.x-l);
				mnR = min(mnR,i.y+r-i.x);
			}
			s.insert({l,mnL});
			s.insert({r,mnR});
		}
	}
	vec ans;
	ll mn = llINF;
	for(pi i : s) mn = min(mn,i.y);
	for(pi i : s) if(i.y == mn) ans.pb(i.x);
	cout << mn+enx << '\n' << ans.size() << ' ';
	for(int i : ans) cout << i << ' ';
}