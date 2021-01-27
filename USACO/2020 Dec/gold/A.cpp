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
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,P;
int LU[1005][1005],RU[1005][1005],LD[1005][1005],RD[1005][1005];
int D[1005][1005],c[1005][1005];
int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
char a[1005][1005];

void getDist();
void Do_Bfs();
void Twist_and_insert_square();
int getAns();
struct Query {int x,sy,ey,op;};
vector <Query> v;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> P;
	for(int i = 1;i <= n;i++) cin >> a[i]+1;
	getDist();
	Do_Bfs();
	cout << getAns();
}

void getDist() {
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) {
			if(a[i][j] == '#') LU[i][j] = 0;
			else LU[i][j] = min(LU[i-1][j],LU[i][j-1])+1;
		}
	}
	for(int i = 1;i <= n;i++) {
		for(int j = n;j >= 1;j--) {
			if(a[i][j] == '#') RU[i][j] = 0;
			else RU[i][j] = min(RU[i-1][j],RU[i][j+1])+1;
		}
	}
	for(int i = n;i >= 1;i--) {
		for(int j = 1;j <= n;j++) {
			if(a[i][j] == '#') LD[i][j] = 0;
			else LD[i][j] = min(LD[i+1][j],LD[i][j-1])+1;
		}
	}
	for(int i = n;i >= 1;i--) {
		for(int j = n;j >= 1;j--) {
			if(a[i][j] == '#') RD[i][j] = 0;
			else RD[i][j] = min(RD[i+1][j],RD[i][j+1])+1;
		}
	}
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) {
			D[i][j] = min({LU[i][j],RU[i][j],LD[i][j],RD[i][j]});
		}
	}
}

struct Robot {int time,sz,x,y;};

void Do_Bfs() {
	queue <Robot> q;
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) {
			if(a[i][j] == 'S') q.push({0,1,i,j});
		}
	}
	while(!q.empty()) {
		Robot now = q.front(); q.pop();
		int time = now.time, sz = now.sz, x = now.x, y = now.y;
		if(c[x][y]) continue;
		c[x][y] = sz;
		if(time&&time % P == 0) sz++;
		if(sz > D[x][y]) continue;
		c[x][y] = sz;
		for(int i = 0;i < 4;i++) {
			int nx = x+dx[i], ny = y+dy[i];
			int ntime = time+1, nsz = sz;
			if(c[nx][ny]||nsz > D[nx][ny]) continue;
			q.push({ntime,nsz,nx,ny});
		}
	}
}

int getAns() {
	priority_queue <pair<int,pi>> q;
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) {
			if(c[i][j]) q.push({c[i][j]-1,{i,j}});
		}
	}
	int ret = 0;
	memset(c,0,sizeof(c));
	while(!q.empty()) {
		auto now = q.top(); q.pop();
		int cost = now.x, x = now.y.x, y = now.y.y;
		if(c[x][y]) continue;
		c[x][y] = 1, ret++;
		if(!cost) continue;
		for(int i = 0;i < 4;i++) {
			int nx = x+dx[i], ny = y+dy[i];
			if(c[nx][ny]) continue;
			q.push({cost-1,{nx,ny}});
		}
	}
	return ret;
}