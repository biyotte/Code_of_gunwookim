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
const long long mod = 998244353;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,m,st,en,so,nx[4] = {1,0,-1,0}, ny[4] = {0,1,0,-1};
int num[15][15];
char a[15][15];

// not solved

int f(int x,int y) {return (x-1)*m+y;}
int f2(int x,int y) {return (x-1)*200+y;}

struct Edge {
	int x,cap,rev;
}

void addEdge(int x,int y,int cap) {
	v[x].pb({y,cap,v[y].size()});
	v[y].pb({x,0,v[x].size()-1});
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); 
	cin >> n >> m;
	so = n*m+2;
	for(int i = 1;i <= n;i++) {
		cin >> a[i]+1;
		for(int j = 1;j <= m;j++) {
			if(a[i][j] == 'D') {
				num[i][j] = ++so;
			}
		}
	}
	st = n*m+1, en = n*m+2;
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= m;j++) {
			if(a[i][j] != 'X') continue;
			if(a[i][j] == 'D') {
				for(int ti = 0;ti <= 180;ti++) {
					addEdge(f2(f(i,j),ti),f2(f(i,j),ti+1),INF);
					addEdge(f2(num[dx][dy],ti),f2(f(i,j),ti+1),1);
				}
				addEdge(f2(f(i,j),181),f2(st,181),INF);
			}
			for(int ti = 0;ti <= 180;ti++) {
				addEdge(f2(st,ti),f2(f(i,j),ti+1),1);
				addEdge(f2(f(i,j),ti),f2(f(i,j),ti+1),INF);
			}
			for(int l = 0;l < 4;l++) {
				int dx = i+nx[l], dy = j+ny[l];
				if(a[dx][dy] == 'X') continue;
				
				for(int ti = 0;ti <= 180;ti++) {
					if(a[dx][dy] == 'D') {
						addEdge(f2(f(i,j),ti),f2(num[dx][dy],ti+1),1);
					}
					addEdge(f2(f(i,j),ti),f2(f(dx,dy),ti+1),INF);
				}
			}
		}
	}
}