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
int n,sx,sy,d[1505][1505];
int a[1505][1505];
vecpi ip[1000005];

struct IP {
	int x[4];
	int mx[4];
}tx[1505],ty[1505];

void build() {
	for(int i = 0;i <= n+1;i++) {
		for(int k = 0;k < 4;k++) {
			tx[i].mx[k] = ty[i].mx[k] = -INF;
			tx[i].x[k] = ty[i].x[k] = -1;
		}
	}
}

void update(int op,int x,int wi,int val) {
	for(int i = 0;i < 4;i++) {
		if((op ? tx[x] : ty[x]).mx[i] >= val) continue;
		for(int j = 3;j > i;j--) {
		(op ? tx[x] : ty[x]).x[j] = (op ? tx[x] : ty[x]).x[j-1];
		(op ? tx[x] : ty[x]).mx[j] = (op ? tx[x] : ty[x]).mx[j-1];
		}
		(op ? tx[x] : ty[x]).x[i] = wi;
		(op ? tx[x] : ty[x]).mx[i] = val;
		return;
	}
}

int query(int op,int x,int wi) {
	if(x < 1||x > n||wi < 1||wi > n) return -INF;
	for(int i = 0;i < 4;i++) {
		if(wi-1 <= (op ? tx[x] : ty[x]).x[i]&&(op ? tx[x] : ty[x]).x[i] <= wi+1) continue;
		return (op ? tx[x] : ty[x]).mx[i];
	}
	return -INF;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> sx >> sy;
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) {
			cin >> a[i][j];
			d[i][j] = -INF;
			ip[a[i][j]].pb({i,j});
		}
	}
	build();
	d[sx][sy] = 0;
	int ans = 0;
	for(int co = 0;co <= 1000000;co++) {
		for(pi i : ip[co]) {
			for(int k : {-1,1}) {
				d[i.x][i.y] = max(d[i.x][i.y],query(1,i.x+k,i.y));
				d[i.x][i.y] = max(d[i.x][i.y],query(0,i.y+k,i.x));
			}
			d[i.x][i.y]++;
			ans = max(ans,d[i.x][i.y]);
		}
		for(pi i : ip[co]) {
			update(1,i.x,i.y,d[i.x][i.y]);
			update(0,i.y,i.x,d[i.x][i.y]);
		}
	}
	cout << ans;
}