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
int n,m,c[1505][1505];
char a[1505][1505];
int sb[1505][1505];
int sr[1505][1505];
int mx[1505][1505];
int mb[1505][1505];
int mr[1505][1505];
int nx[8] = {1,1,1,0,0,-1,-1,-1}, ny[8] = {1,0,-1,1,-1,1,0,-1};
queue <pi> q;

void BFS(int sx,int sy,int color) {
	if(a[sx][sy] == '.') return;
	q.push({sx,sy});
	while(!q.empty()) {
		int x = q.front().x, y = q.front().y; q.pop();
		if(c[x][y]) continue;
		c[x][y] = 1;
		if(a[x][y] == '#') (color&1 ? sb[x][y] : sr[x][y]) = 1;
		for(int i = 0;i < 8;i++) {
			int dx = x+nx[i], dy = y+ny[i];
			if(dx < 1||dx > n||dy < 1||dy > m||a[dx][dy] == '.') continue;
			q.push({dx,dy});
		}
	}
}

int sumB(int sx,int sy,int ex,int ey) {
	return sb[ex][ey]-sb[sx-1][ey]-sb[ex][sy-1]+sb[sx-1][sy-1];
}

int sumR(int sx,int sy,int ex,int ey) {
	return sr[ex][ey]-sr[sx-1][ey]-sr[ex][sy-1]+sr[sx-1][sy-1];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> m >> n;
	for(int i = 1;i <= n;i++) cin >> a[i]+1;
	for(int i = 2;i <= n;i++) BFS(i,1,1);
	for(int i = 1;i < m;i++) BFS(n,i,1);
	for(int i = 1;i < n;i++) BFS(i,m,2);
	for(int i = 2;i <= m;i++) BFS(1,i,2);
	a[1][1] = a[n][m] = '#';
	for(int i = 1;i <= n+1;i++) {
		for(int j = 1;j <= m+1;j++) {
			sb[i][j] += sb[i-1][j]+sb[i][j-1]-sb[i-1][j-1];
			sr[i][j] += sr[i-1][j]+sr[i][j-1]-sr[i-1][j-1];
			mb[i][j] = mr[i][j] = INF;
		}
	}
	for(int i = n;i >= 1;i--) {
		for(int j = m;j >= 1;j--) {
			if(a[i][j] == '#') mx[i][j] = 0;
			else mx[i][j] = min({mx[i][j+1],mx[i+1][j],mx[i+1][j+1]})+1;
		}
	}
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= m;j++) {
			if(a[i][j] == '#') continue;
			if(j == 1) mb[i][j] = 1;
			else if(n-i+1 <= mx[i][j]) mb[i][j] = n-i+1;
			if(i == 1) mr[i][j] = 1;
			else if(m-j+1 <= mx[i][j]) mr[i][j] = m-j+1;
		}
	}
	int ans = INF,ax,ay;
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= m;j++) {
			if(a[i][j] == '#') continue;
			int l = 1,r = mx[i][j];
			while(l < r) {
				int mid = (l + r) >> 1;
				if(sumB(i-1,j-1,i-1,j+mid)||sumB(i-1,j-1,i+mid,j-1)) r = mid;
				else l = mid+1;
			}
			int bl = l,rl;
			l = 1,r = mx[i][j];
			while(l < r) {
				int mid = (l + r) >> 1;
				if(sumR(i-1,j-1,i-1,j+mid)||sumR(i-1,j-1,i+mid,j-1)) r = mid;
				else l = mid+1;
			}
			rl = l;
			//cout << i << ' ' << j << " : " << l << '\n';
			if(bl == mx[i][j]) {
				int mid = mx[i][j];
				if((sumB(i-1,j-1,i-1,j+mid)||sumB(i-1,j-1,i+mid,j-1)||sumB(i-1,j+mid,i+mid,j+mid)||sumB(i+mid,j-1,i+mid,j+mid))) bl = mx[i][j];
				else bl = INF;
			}
			if(rl == mx[i][j]) {
				int mid = mx[i][j];
				if((sumR(i-1,j-1,i-1,j+mid)||sumR(i-1,j-1,i+mid,j-1)||sumR(i-1,j+mid,i+mid,j+mid)||sumR(i+mid,j-1,i+mid,j+mid))) rl = mx[i][j];
				else rl = INF;
			}
			int len = max(min(bl,mb[i][j]),min(rl,mr[i][j]));
			if(ans > len) ans = len, ax = i, ay = j;
		}
	}
	if(ans == INF) cout << "Impossible";
	else cout << ans << ' ' << ay << ' ' << ax;
}