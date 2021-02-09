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
int n,m,root,sz[100005],c[100005];
vec v[100005];
vec vc[100005];

// not solved

int get_sz(int now,int pv) {
	sz[now] = 1;
	for(int i : v[now]) {
		if(i == pv) continue;
		get_sz(i,x);
		sz[x] += sz[i];
	}
}

int get_cent(int now,int pv) {
	for(int i : v[x]) {
		if(i == pv) continue;
		
	}
}

int make_centroid(int now,int pv) {
	int now_sz = get_sz(now,pv), cent = get_cent(now,pv);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i < n;i++) {
		int x,y; cin >> x >> y;
		v[x].pb(y), v[y].pb(x);
	}
	root = make_centroid(1,-1);
}
