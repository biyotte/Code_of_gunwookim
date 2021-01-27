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
int n,Q,g,p[100005],c[100005];
int par[100005],ans[1000005];
pi q[1100005];
set <int> s[100005];

int Find(int x) {return (x^p[x] ? p[x] = Find(p[x]) : x);}

void merge(int x,int y) {
	x = Find(x), y = Find(y);
	if(s[x].size() < s[y].size()) swap(x,y);
	p[y] = x;
	for(int i : s[y]) s[x].insert(i);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); 
	cin >> n >> Q;
	for(int i = 2;i <= n;i++) cin >> par[i];
	for(int i = 1;i <= n;i++) cin >> c[i], s[i].insert(c[i]), p[i] = i;
	for(int i = 1;i <= Q+n-1;i++) cin >> q[i].x >> q[i].y;
	for(int i = Q+n-1;i >= 1;i--) {
		if(q[i].x & 1) merge(q[i].y,par[q[i].y]);
		else ans[++g] = s[Find(q[i].y)].size();
	}
	for(int i = 1;i <= Q;i++) cout << ans[Q-i+1] << '\n';
}