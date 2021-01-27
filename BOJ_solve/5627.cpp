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
const int MAXN = 20000;
const int MAXM = 4000000;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pl;
typedef pair <ll,ll> pi;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;


// not solved


tuple <ll,ll,ll> add_gcd(ll x,ll y) {
	if(!y) return make_tuple(x,1,0);
	ll g,nx,ny;
	tie(g,nx,ny) = add_gcd(y,x%y);
	return make_tuple(g,ny,nx-(x/y)*ny);
}

ll inverse(ll ax,ll by,ll c) {
	ll g,x,y;
	g = __gcd(ax,by);
	if(c % g) return -1;
	tie(g,x,y) = add_gcd(ax,by);
	return x*c;
}

pi CRT(vecpi con) {
	// x = val (mod M)
	// val = a
	// m1,m2 = M,M2
	// ax = z (mod m)
	// ax + my = z
	ll val = con[0].x, M = con[0].y;
	for(int i = 1;i < con.size();i++) {
		ll val2 = con[i].x, M2 = con[i].y;
		ll g = __gcd(M,M2);
		if(val % g != val2 % g) return {-1,-1};
		ll k = inverse(M,M2,((val2-val)%M2+M2)%M2);
		if(k == -1) return {-1,-1};
		ll tm = M*M2/__gcd(M,M2);
		ll tval = M*k+val;
		M = tm, val = tval;
		val = (val%M+M)%M;
	}
	return {val,M};
}

int n,m,T,op,ex,ey;
int a[55][55],c[55][55][4];
int nx[4] = {0,1,0,-1}, ny[4] = {1,0,-1,0};
vecpi choice[6],ch;
ll ans,mxst;

ll getAns(pi x,ll stmx) {
	ll ret = x.x;
	while(ret < stmx) ret += x.y;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	vecpi con;
	cin >> n >> m >> T;
	cin >> ex >> ey;
	ll real = -1;
	for(int k = 1;k <= T;k++) {
		char o;
		int sx,sy; cin >> sx >> sy >> o;
		if(o == 'R') op = 0;
		if(o == 'D') op = 1;
		if(o == 'L') op = 2;
		if(o == 'U') op = 3;
		for(int i = 1;i <= n;i++) {
			for(int j = 1;j <= m;j++) {
				char x; cin >> x;
				a[i][j] = x-'0';
			}
		}
		memset(c,0,sizeof(c));
		ll st = -1,ju = -1;
		for(int cnt = 1;1;cnt++) {
			if(sx == ex&&sy == ey) {st = cnt; break;}
			if(c[sx][sy][op]) break;
			c[sx][sy][op] = 1;
			op = (op+a[sx][sy])%4;
			int dx = sx+nx[op], dy = sy+ny[op];
			if(dx < 1||dx > n||dy < 1||dy > m) {
				op = (op+2)%4;
				dx = sx+nx[op], dy = sy+ny[op];
			}
			sx = dx, sy = dy;
		}
		memset(c,0,sizeof(c));
		if(st == -1) {
			cout << "-1";
			return 0;
		}
		for(int cnt = 0;1;cnt++) {
			if(c[sx][sy][op]) break;
			if(sx == ex&&sy == ey&&cnt) {
				choice[k].pb({st,cnt});
				con.pb({st,cnt});
				ju = 1;
			}
			c[sx][sy][op] = 1;
			op = (op+a[sx][sy])%4;
			int dx = sx+nx[op], dy = sy+ny[op];
			if(dx < 1||dx > n||dy < 1||dy > m) {
				op = (op+2)%4;
				dx = sx+nx[op], dy = sy+ny[op];
			}
			sx = dx, sy = dy;
		}
		if(ju == -1) {
			if(real == -1) real = st;
			else if(real != st) {
				cout << "-1";
				return 0;
			}
		}
	}
	if(real != -1) {
		for(pi i : con) {
			if(i.y == -1) continue;
			if(real < i.x||(real-i.x) % i.y) {
				cout << "-1";
				return 0;
			}
		}
		cout << real;
		return 0;
	}
	pi ans = CRT(con);
	if(ans.x == -1) cout << "-1";
	else cout << getAns(ans,mxst);
}