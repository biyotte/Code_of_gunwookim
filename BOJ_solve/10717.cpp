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
int n,m,lll,P,a[4005][4005];
int L[4005][4005],R[4005][4005],U[4005][4005],D[4005][4005];
int t[4005],mx;
ll ans;

void init() {memset(t,0,sizeof(t));}
void update(int x) {for(;x <= n+m;x += x&-x) t[x]++;}
int query(int l,int r) {
	if(l > r) return 0;
	int ret = 0;
	for(;r;r -= r&-r) ret += t[r];
	for(l--;l;l -= l&-l) ret -= t[l];
	return ret;
}

void getAns(int sx,int sy) {
	mx = 0;
	memset(t,0,sizeof(t));
	vecpi v;
	for(int i = sx,j = sy;i <= n&&j <= m;i++,j++,mx++) v.pb({i-min(L[i][j],U[i][j])+1,i});
	sort(all(v));
	for(int pl = 0,pv = 0;pl < mx;pl++) {
		int x = sx+pl, y = sy+pl;
		while(pv < v.size()&&v[pv].x <= x) update(v[pv++].y);
		int len = min(R[x][y],D[x][y])-1;
		ans += query(x+lll-1,x+len);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> lll >> P;
	for(int i = 1;i <= P;i++) {
		int x,y; cin >> x >> y;
		a[x][y] = 1;
	}
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= m;j++) {
			if(a[i][j]) U[i][j] = L[i][j] = 0;
			else U[i][j] = U[i-1][j]+1, L[i][j] = L[i][j-1]+1;
		}
	}
	for(int i = n;i >= 1;i--) {
		for(int j = m;j >= 1;j--) {
			if(a[i][j]) D[i][j] = R[i][j] = 0;
			else D[i][j] = D[i+1][j]+1, R[i][j] = R[i][j+1]+1;
		}
	}
	for(int i = 1;i <= n;i++) getAns(i,1);
	for(int i = 2;i <= m;i++) getAns(1,i);
	cout << ans;
}