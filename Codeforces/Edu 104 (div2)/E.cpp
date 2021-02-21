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
const long long llINF = 1e18;
const long long mod = 11092019;
const long long hashmod = 100003;
const int MAXN = 20000;
const int MAXM = 4000000;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n[4],m[3];
ll a[4][150005];
ll t[600005],d[4][150005];
vec v[4][150005];

void build(int x,int y,int l,int r) {
	if(l == r) {
		t[x] = d[y][l];
		return;
	}
	int mid = (l + r) >> 1;
	build(x*2,y,l,mid), build(x*2+1,y,mid+1,r);
	t[x] = min(t[x*2],t[x*2+1]);
}

void update(int x,int l,int r,int wi,ll val) {
	if(wi < l||r < wi) return;
	if(l == r) {
		t[x] += val;
		return;
	}
	int mid = (l + r) >> 1;
	update(x*2,l,mid,wi,val), update(x*2+1,mid+1,r,wi,val);
	t[x] = min(t[x*2],t[x*2+1]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	for(int i = 0;i < 4;i++) cin >> n[i];
	for(int i = 0;i < 4;i++) {
		for(int j = 1;j <= n[i];j++) {
			cin >> a[i][j];
			d[i][j] = a[i][j];
		} 
	}
	for(int i = 0;i < 3;i++) {
		cin >> m[i];
		for(int j = 1;j <= m[i];j++) {
			int x,y; cin >> x >> y;
			v[i][y].pb(x);
		}
	}
	for(int i = 0;i < 3;i++) {
		for(int j = 1;j <= 600000;j++) t[j] = llINF;
		build(1,i,1,n[i]);
		for(int j = 1;j <= n[i+1];j++) {
			for(int k : v[i][j]) {
				update(1,1,n[i],k,llINF);
			}
			d[i+1][j] = min(llINF,t[1]+a[i+1][j]);
			for(int k : v[i][j]) update(1,1,n[i],k,-llINF);
		}
	} 
	ll ans = llINF;
	for(int i = 1;i <= n[3];i++) ans = min(ans,d[3][i]);
	cout << (ans >= llINF ? -1 : ans);
}
