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
int n,W,D;
pi l[1005];

struct Person {
	int lx,ly,rx,ry,x,y;
	char op;
	int l,r;
}a[1005];

bool cmp(pi x,pi y) {
	if(x.y == y.y) return x.x < y.x;
	return x.y < y.y;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); 
	cin >> n >> W >> D;
	for(int i = 1;i <= n;i++) {
		cin >> a[i].x >> a[i].y >> a[i].op;
		if(a[i].op == 'N') { // right
			int mnl = min(a[i].x,D-a[i].y);
			int mnr = min(W-a[i].x,D-a[i].y);
			a[i].lx = a[i].x-mnl, a[i].rx = a[i].x+mnr; 
			a[i].ly = a[i].y+mnl, a[i].ry = a[i].y+mnr;
		}
		if(a[i].op == 'E') { // down
			int mnl = min(W-a[i].x,D-a[i].y);
			int mnr = min(W-a[i].x,a[i].y);
			a[i].lx = a[i].x+mnl, a[i].rx = a[i].x+mnr; 
			a[i].ly = a[i].y+mnl, a[i].ry = a[i].y-mnr;
		}
		if(a[i].op == 'W') { // up
			int mnl = min(a[i].x,a[i].y);
			int mnr = min(a[i].x,D-a[i].y);
			a[i].lx = a[i].x-mnl, a[i].rx = a[i].x-mnr; 
			a[i].ly = a[i].y-mnl, a[i].ry = a[i].y+mnr;
		}
		if(a[i].op == 'S') { // left
			int mnl = min(W-a[i].x,a[i].y);
			int mnr = min(a[i].x,a[i].y);
			a[i].lx = a[i].x+mnl, a[i].rx = a[i].x-mnr; 
			a[i].ly = a[i].y-mnl, a[i].ry = a[i].y-mnr;
		}
	}
	for(int i = 1;i <= n;i++) {
		if(!a[i].lx) a[i].l = a[i].ly+1;
		else if(a[i].ly == D) a[i].l = D+1+a[i].lx;
		else if(a[i].lx == W) a[i].l = D+W+1+(D-a[i].ly);
		else a[i].l = 2*D+W+1+(W-a[i].lx);

		if(!a[i].rx) a[i].r = a[i].ry+1;
		else if(a[i].ry == D) a[i].r = D+1+a[i].rx;
		else if(a[i].rx == W) a[i].r = D+W+1+(D-a[i].ry);
		else a[i].r = 2*D+W+1+(W-a[i].rx);
	}
	int ans = INF;
	for(int i = 1;i <= n;i++) {
		int dx = a[i].l;
		for(int j = 1;j <= n;j++) {
			a[j].l -= dx;
			a[j].r -= dx;
			if(a[j].l < 0) a[j].l += 2*(W+D);
			if(a[j].r < 0) a[j].r += 2*(W+D);
			if(a[j].l > a[j].r) l[j] = {a[j].l,a[j].r+2*(W+D)};
			else l[j] = {a[j].l,a[j].r};
		}
		sort(l+1,l+n+1,cmp);
		int la = -INF,cnt = 0;
		for(int j = 1;j <= n;j++) {
			if(la < l[j].x) cnt++, la = l[j].y;
		}
		ans = min(ans,cnt);
		for(int j = 1;j <= n;j++) {
			a[j].l += dx;
			a[j].r += dx;
			if(a[j].l > 2*(W+D)) a[j].l -= 2*(W+D);
			if(a[j].r > 2*(W+D)) a[j].r -= 2*(W+D);
		}
	}
	cout << ans;
}