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
const int MAXN = 100000;
const int MAXM = 1000000;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,R,P,S,co,p[25005],rev[25005];
int ind[25005],c[25005];
vecpi v[25005],v2[25005];
vec t[25005];
ll dist[25005];


struct Edge {
	int x,y,val;
}er[50005],ep[50005];

int Find(int x) {return (x^p[x] ? p[x] = Find(p[x]) : x);}

void merge(int x,int y) {
	x = Find(x), y = Find(y);
	if(x == y) return;
	p[y] = x;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> R >> P >> S;
	for(int i = 1;i <= n;i++) p[i] = i;
	for(int i = 1;i <= R;i++) {
		int x,y,z; cin >> x >> y >> z;
		v[x].pb({y,z}), v[y].pb({x,z});
		merge(x,y);
	}
	for(int i = 1;i <= n;i++) {
		if(Find(i) == i) rev[i] = ++co;
	}
	for(int i = 1;i <= n;i++) {
		t[rev[p[i]]].pb(i);
		dist[i] = llINF;
	}
	for(int i = 1;i <= P;i++) {
		int x,y,z; cin >> x >> y >> z;
		ep[i] = {x,y,z};
		v2[x].pb({y,z});
		ind[rev[p[y]]]++;
	}
	dist[S] = 0;
	queue <int> inq;
	priority_queue <pair<ll,int>> q;
	for(int i = 1;i <= co;i++) {
		if(!ind[i]) inq.push(i);
	}
	while(!inq.empty()) {
		int now = inq.front(); inq.pop();
		for(int i : t[now]) {
			q.push({-dist[i],i});
		}
		while(!q.empty()) {
			ll cost = -q.top().x; int x = q.top().y; q.pop();
			if(c[x]) continue; c[x] = 1;
			dist[x] = min(dist[x],cost);
			for(pi i : v[x]) q.push({-cost-i.y,i.x});
		}
		for(int x : t[now]) {
			for(pi i : v2[x]) {
				int nx = rev[p[i.x]];
				dist[i.x] = min(dist[i.x],dist[x]+i.y);
				if(!--ind[nx]) inq.push(nx);
			}
		}
	}
	for(int i = 1;i <= n;i++) {
		if(dist[i] >= INF) cout << "NO PATH\n";
		else cout << dist[i] << '\n';
	}
}
