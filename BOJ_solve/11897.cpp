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
long long mod;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,m,Q,ql[50005],qr[50005];
short p[50005][705];
vecpi edge;
vecpi el,er;

int Find(int x,int y) {return (y ^ p[x][y] ? p[x][y] = Find(x,p[x][y]) : y);}


void merge(int op,int x,int y) {
	x = Find(op,x), y = Find(op,y);
	if(x == y) return;
	//if(sz[op][x] < sz[op][y]) swap(x,y);
	p[op][y] = x;
	//sz[op][x] += sz[op][y];
}



int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	edge.pb({-1,-1});
	for(int i = 1;i <= m;i++) {
		int x,y; cin >> x >> y;
		edge.pb({x,y});
	}
	cin >> Q;
	for(int i = 0;i <= Q;i++) {
		for(int j = 1;j <= n;j++) p[i][j] = j;//, sz[i][j] = 1;
	}
	for(int i = 1;i <= Q;i++) {
		cin >> ql[i] >> qr[i];
		el.pb({ql[i],i});
		er.pb({qr[i],i});
	}
	sort(all(el));
	sort(all(er)), reverse(all(er));
	int j = 1;
	for(pi i : el) {
		for(;j < i.x;j++) {
			merge(0,edge[j].x,edge[j].y);
		}
		for(int k = 1;k <= n;k++) merge(i.y,k,Find(0,k));
	}
	for(int i = 0;i <= n;i++) {
		p[0][i] = i;//, sz[0][i] = 1;
	}
	j = m;
	for(pi i : er) {
		for(;j > i.x;j--) {
			merge(0,edge[j].x,edge[j].y);
		}
		for(int k = 1;k <= n;k++) merge(i.y,k,Find(0,k));
	}
	for(int i = 1;i <= Q;i++) {
		int cnt = 0;
		for(int j = 1;j <= n;j++) {
			if(p[i][j] == j) cnt++;
		}
		cout << cnt << '\n';
	}
}