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
int n,m,Q;
vec v[405][27], rv[405][27];
int c[405][405][27];
int p[405][405][27],stt[405][405];
pi p2[405][405];

struct Queue {int x,y,ch,di;};
queue <Queue> q;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	memset(c,-1,sizeof(c));
	for(int i = 1;i <= n;i++) c[i][i][0] = 0, q.push({i,i,0,0});
	for(int i = 1;i <= m;i++) {
		int x,y; char z; cin >> x >> y >> z;
		v[x][z-'a'+1].pb(y), rv[y][z-'a'+1].pb(x);
		q.push({x,y,0,1});
		c[x][y][0] = 1;
		stt[x][y] = z; 
	}
	while(!q.empty()) {
		Queue now = q.front(); q.pop();
		int x = now.x, y = now.y, ch = now.ch, di = now.di;
		if(ch) {
			for(int i : v[y][ch]) {
				if(c[x][i][0] == -1) {
					c[x][i][0] = di+1;
					p2[x][i] = {y,ch};
					q.push({x,i,0,di+1});
				}
			} 
		}
		else {
			for(int i = 1;i <= 26;i++) {
				for(int j : rv[x][i]) {
					if(c[j][y][i] == -1) {
						c[j][y][i] = di+1;
						p[j][y][i] = x;
						q.push({j,y,i,di+1});
					}
				} 
			}
		}
	}
	cin >> Q; Q--;
	int st,en; cin >> st;
	vector <char> ans;
	while(Q--) {
		cin >> en;
		if(c[st][en][0] == -1) cout << "-1\n";
		else {
			ans.clear();
			cout << c[st][en][0] << ' ';
			int x = st, y = en,di = c[st][en][0];
			while(di > 1) {
				di -= 2;
				int nx,ny,ch;
				ny = p2[x][y].x;
				ch = p2[x][y].y;
				nx = p[x][ny][ch];
				ans.pb(ch+'a'-1);
				x = nx, y = ny;
			}
			for(char i : ans) cout << i;
			if(x^y) cout << (char)stt[x][y];
			reverse(all(ans));
			for(char i : ans) cout << i;
			cout << '\n';
		}
		swap(st,en);
	}
}