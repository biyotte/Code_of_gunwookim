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
int n,m,c[505][505],p[250005];
char a[505][505];
int nx[4] = {1,0,-1,0}, ny[4] = {0,1,0,-1};
int cnt[250005];

int Find(int x) {return (x^p[x] ? p[x] = Find(p[x]) : x);}

int f(int x,int y) {return (x-1)*m+y;}

// not solved

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while(T--) {
		cin >> n >> m;
		for(int i = 1;i <= n;i++) {
			cin >> a[i]+1;
			for(int j = 1;j <= m;j++) p[f(i,j)] = f(i,j);
		}
		for(int i = 1;i <= n;i++) {
			for(int j = 1;j <= m;j++) {
				if(a[i][j] == 'X') {
					int fl = 0;
					for(int k = 0;k < 4;k++) {
						int dx = i+nx[k], dy = j+ny[k];
						if(a[dx][dy] == 'X') {
							fl = 1;
							break;
						}
					}
					if(fl) continue; 
					for(int k = 0;k < 4;k++) {
						for(int len = 1;1;len++) {
							int dx = i+nx[k]*len, dy = j+ny[k]*len, ffl = 0;
							if(dx < 1||dx > n||dy < 1||dy > m) break;
							cnt[Find(f(dx,dy))] = 1;
							for(int l = 0;l < 4;l++) {
								int ddx = dx+nx[l], ddy = dy+ny[l];
								if(ddx < 1||ddx > n||ddy < 1||ddy > m||a[ddx][ddy] == '.') continue;
								if(cnt[Find(f(ddx,ddy))]) {
									ffl = 1;
									break;
								}
								cnt[Find(f(ddx,ddy))]++;
							}
							cnt[Find(f(dx,dy))] = 0;
							for(int l = 0;l < 4;l++) {
								int ddx = dx+nx[l], ddy = dy+ny[l];
								if(ddx < 1||ddx > n||ddy < 1||ddy > m||a[ddx][ddy] == '.') continue;
								cnt[Find(f(ddx,ddy))] = 0;
								if(!ffl) {
									p[Find(f(ddx,ddy))] = p[Find(f(dx,dy))];
								}
							}
							if(ffl) break;
							a[dx][dy] = 'X';
						}
					}
				}
			}
		}
		for(int i = 1;i <= n;i++) {
			for(int j = 1;j <= m;j++) {
				cout << a[i][j];
			}
			cout << '\n';
		}
	}
}