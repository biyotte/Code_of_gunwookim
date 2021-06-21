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
const long long llINF = 1e18+10;
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
int n,m;
int p[4000005];
bool c[2005][2005];

int f(int x,int y) {return (x-1)*m+y;}
int Find(int x) {return (x^p[x] ? p[x] = Find(p[x]) : x);}
void merge(int x,int y) {
	x = Find(x), y = Find(y);
	p[y] = x;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++) p[i] = i;
	int Q; cin >> Q;
	while(Q--) {
		int op,x,y,x2,y2;
		cin >> op >> x >> y;
		if(op & 1) {
			c[x][y] = 1;
			if(c[x+1][y]) merge(f(x,y),f(x+1,y));
			if(c[x-1][y]) merge(f(x,y),f(x-1,y));
			if(c[x][y+1]) merge(f(x,y),f(x,y+1));
			if(c[x][y-1]) merge(f(x,y),f(x,y-1));
		}
		else {
			cin >> x2 >> y2;
			cout << (Find(f(x,y)) == Find(f(x2,y2))&&c[x][y]&&c[x2][y2] ? "Yes" : "No") << '\n';
		}
	}
}
