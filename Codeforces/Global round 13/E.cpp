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
const long long llINF = 1e16;
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
int n,fi[55],sz[200005],c[200005];
vecpi v[200005];
pi edge[200005];

void get_sz(int x,int pr) {
	sz[x] = 1;
	for(pi i : v[x]) {
		if(i.x == pr||c[i.y]) continue;
		get_sz(i.x,x);
		sz[x] += sz[i.x];
	}
}

int get_cut(int x,int pr,int num) {
	for(pi i : v[x]) {
		if(i.x == pr||c[i.y]) continue;
		int tmp = get_cut(i.x,x,num);
		if(sz[i.x] == fi[num-1]||sz[i.x] == fi[num-2]) {
			if(edge[i.y].x != i.x&&sz[i.x] == fi[num-2]) swap(edge[i.y].x,edge[i.y].y);
			if(edge[i.y].x == i.x&&sz[i.x] == fi[num-1]) swap(edge[i.y].x,edge[i.y].y);
			tmp = i.y;
		}
		if(tmp) return tmp;
	}
	return 0;
}

int dfs(int x,int pr,int num) {
	get_sz(x,pr);
	if(sz[x] == 1) return 1;
	int wh = get_cut(x,pr,num);
	if(!wh) return 0;
	c[wh] = 1;
	return (dfs(edge[wh].x,edge[wh].y,num-2)&&dfs(edge[wh].y,edge[wh].x,num-1));
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	if(n == 1) {
		cout << "YES";
		return 0;
	}
	fi[0] = fi[1] = 1;
	int num = 0;
	for(int i = 2;i <= 50;i++) {
		fi[i] = fi[i-1]+fi[i-2];

		if(fi[i] > n) {
			cout << "NO\n";
			return 0;
		
		}
		if(fi[i] == n) {num = i; break;}
	}
	for(int i = 1;i < n;i++) {
		int x,y; cin >> x >> y;
		v[x].pb({y,i}), v[y].pb({x,i});
		edge[i] = {x,y};
	}
	if(dfs(1,-1,num)) cout << "YES";
	else cout << "NO";
	return 0;
}