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
int n,Q,p[1000005];
int sum[1005][1005],mx[1005][1005];
char in[1005][1005];
vec mid[1005];
int L[300005],R[300005];
int st[300005],en[300005];
vector <pi> v[1005];

int have(int x1,int y1,int x2,int y2) {
	return sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1];
}

int get_mx(int x,int y) {
	int l = 1, r = min({x,y,n-x+1,n-y+1});
	while(l < r) {
		int mid = (l + r + 1) >> 1;
		if(have(x-mid+1,y-mid+1,x+mid-1,y+mid-1)) r = mid-1;
		else l = mid;
	}
	return l*2-1;
}

int f(int x,int y) {
	return (x-1)*n+y;
}

int Find(int x) {
	return (x^p[x] ? p[x] = Find(p[x]) : x);
}

void merge(int x,int y) {
	x = Find(x), y = Find(y);
	if(x^y) p[y] = x;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) {
		cin >> in[i]+1;
		for(int j = 1;j <= n;j++) {
			sum[i][j] = sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+(in[i][j] == '#');
		}
	}
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) {
			if(in[i][j] == '.') mx[i][j] = get_mx(i,j);
		}
	}
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) {
			if(i < n&&mx[i][j]&&mx[i+1][j]) {
				v[min(mx[i][j],mx[i+1][j])].pb({f(i,j),f(i+1,j)});
			}
			if(j < n&&mx[i][j]&&mx[i][j+1]) {
				v[min(mx[i][j],mx[i][j+1])].pb({f(i,j),f(i,j+1)});
			}
		}
	}
	cin >> Q;
	for(int i = 1;i <= Q;i++) {
		int x,y; cin >> x >> y;
		st[i] = f(x,y);
		cin >> x >> y;
		en[i] = f(x,y);
		L[i] = 0, R[i] = n;
	}
	while(1) {
		int op = 0;
		for(int i = 1;i <= n;i++) mid[i].clear();
		for(int i = 1;i <= Q;i++) {
			if(L[i]^R[i]) op = 1, mid[(L[i] + R[i] + 1) >> 1].pb(i);
		}
		if(!op) break;
		for(int i = 1;i <= n*n;i++) p[i] = i;
		for(int i = n;i >= 0;i--) {
			for(pi j : v[i]) merge(j.x,j.y);
			for(int j : mid[i]) {
				if(Find(st[j]) != Find(en[j])) R[j] = i-1;
				else L[j] = i;
			}
		}
	}
	for(int i = 1;i <= Q;i++) {
		cout << L[i] << '\n';
	}
}