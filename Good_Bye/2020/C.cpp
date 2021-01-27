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
int n,c[200005],c2[200005];
int Q,ind[200005];
vec v[200005];
queue <int> q;
int p[200005];

int Find(int x) {return (x^p[x] ? p[x] = Find(p[x]) : x);}

void merge(int x,int y) {
	x = Find(x), y = Find(y);
	if(x == y) return;
	p[y] = x;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> Q;
	for(int i = 1;i <= n;i++) {
		p[i] = i;
		int x,y; cin >> x >> y;
		v[x].pb(y), v[y].pb(x);
		ind[x]++, ind[y]++;
	}
	for(int i = 1;i <= n;i++) {
		if(ind[i] == 1) q.push(i);
	}
	while(!q.empty()) {
		int x = q.front(); q.pop();
		c[x] = c2[x] = 1;
		for(int i : v[x]) {
			if(c[i]) continue;
			merge(i,x);
			if(--ind[i] == 1) {
				q.push(i);
			}
		}
	}
	while(Q--) {
		int x,y; cin >> x >> y;
		if(Find(x) == Find(y)) cout << "1\n";
		else cout << "2\n";
	}
}