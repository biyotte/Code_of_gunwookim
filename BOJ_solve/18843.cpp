#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define all(v) v.begin(),v.end()
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
using namespace std;
const long long INF = 1e9;
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
int n,Q;
int p[100005];
set <int> s[100005],s2[100005];
vec ch[100005];
ll ans,sz[100005];

/*

연쇄작용이 나타나는 경우를 처리 못해서 그냥 보류

not solved

*/

int Find(int x) {return (x^p[x] ? p[x] = Find(p[x]) : x);}

void merge(int x,int y) {
	int rx = x;
	x = Find(x), y = Find(y);
	ans -= sz[x]*(ll)s[x].size();
	ans -= sz[y]*(ll)s[y].size();
	s[y].erase(rx);
	if(sz[x]+s[x].size()+s2[x].size() < sz[y]+s[y].size()+s2[y].size()) swap(x,y);
	for(int i : s[y]) {
		if(Find(i) == x) continue;
		s[x].insert(i);
	}
	s2[x].erase(y), s2[y].erase(x);
	for(int i : s2[y]) s2[x].insert(i);
	for(int i : ch[y]) {
		if(s[x].find(i) != s[x].end()) s[x].erase(i);
		ch[x].pb(i);
	}
	p[y] = x;
	ans -= sz[x]*(sz[x]-1), ans -= sz[y]*(sz[y]-1);
	sz[x] += sz[y];
	ans += sz[x]*(sz[x]-1);
	ans += sz[x]*(ll)s[x].size();
}

void update(int x,int y) {
	if(Find(x) == Find(y)) return;
	ans -= sz[Find(y)]*(ll)s[Find(y)].size();
	s[Find(y)].insert(x);
	s2[Find(y)].insert(Find(x));
	ans += sz[Find(y)]*(ll)s[Find(y)].size();
	if(s2[Find(x)].find(Find(y)) != s2[Find(x)].end()) merge(x,y);

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> Q;
	for(int i = 1;i <= n;i++) p[i] = i, sz[i] = 1, ch[i].pb(i);
	while(Q--) {
		int x,y; cin >> x >> y;
		update(x,y);
		cout << ans << '\n';
	}
}
