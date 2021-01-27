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
int n,m,k;
int L[55][55],R[55][55],D[55][55],U[55][55];
bool c[10005][55][55];
char a[55][55],pro[10005];

struct Keyboard {
	int cost,d,x,y;
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i]+1, a[i][m+1] = '!';
	cin >> pro+1;
	k = strlen(pro+1);
	pro[++k] = '*';
	for(int i = 1;i <= n;i++) {
		int la = -1;
		for(int j = 1;j <= m;j++) {
			if(a[i][j]^a[i][j-1]) la = j-1;
			L[i][j] = la;
		}
	}
	for(int i = 1;i <= n;i++) {
		int la = -1;
		for(int j = m;j >= 1;j--) {
			if(a[i][j]^a[i][j+1]) la = j+1;
			R[i][j] = la;
		}
	}
	for(int i = 1;i <= m;i++) {
		int la = -1;
		for(int j = 1;j <= n;j++) {
			if(a[j][i]^a[j-1][i]) la = j-1;
			U[j][i] = la;
		}
	}
	for(int i = 1;i <= m;i++) {
		int la = -1;
		for(int j = n;j >= 1;j--) {
			if(a[j][i]^a[j+1][i]) la = j+1;
			D[j][i] = la;
		}
	}
	queue <Keyboard> q;
	int st = 1;
	while(a[1][1] == pro[st]) st++;
	q.push({0,st,1,1});
	while(!q.empty()) {
		auto now = q.front(); q.pop();
		if(c[now.d][now.x][now.y]) continue;
		c[now.d][now.x][now.y] = 1;
		if(now.d == k+1) {
			cout << now.cost+k;
			return 0;
		}
		int cost = now.cost, d = now.d, x = now.x, y = now.y;
		int nx,ny,nd;
		if(L[x][y]) {
			nx = x, ny = L[x][y];
			nd = d;
			while(a[nx][ny] == pro[nd]) nd++;
			q.push({cost+1,nd,nx,ny});
		}
		if(R[x][y] != m+1) {
			nx = x, ny = R[x][y];
			nd = d;
			while(a[nx][ny] == pro[nd]) nd++;
			q.push({cost+1,nd,nx,ny});
		}
		if(U[x][y]) {
			nx = U[x][y], ny = y;
			nd = d;
			while(a[nx][ny] == pro[nd]) nd++;
			q.push({cost+1,nd,nx,ny});
		}
		if(D[x][y] != n+1) {
			nx = D[x][y], ny = y;
			nd = d;
			while(a[nx][ny] == pro[nd]) nd++;
			q.push({cost+1,nd,nx,ny});
		}
	}
}