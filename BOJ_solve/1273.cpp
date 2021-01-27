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
const long long llINF = 1e18;
long long mod;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi; 
typedef long long ll;
ll cnt[12000005],sum[3000005];
int n,m = 3e6,Q,g[4];
int a[300005][3];
int v[3000005][3];

void build(int x,int l,int r) {
	if(l == r) {cnt[x] = 1; return;}
	int mid = (l + r) >> 1;
	build(x<<1,l,mid), build(x<<1|1,mid+1,r);
	cnt[x] = cnt[x<<1]+cnt[x<<1|1];
}

void update(int x,int l,int r,int wi) {
	if(l > wi||wi > r) return;
	if(l == r) {cnt[x] = 0; return;}
	int mid = (l + r) >> 1;
	update(x<<1,l,mid,wi),update(x<<1|1,mid+1,r,wi);
	cnt[x] = cnt[x<<1]+cnt[x<<1|1];
}


ll kth(int x,int l,int r,int k) {
	if(l == r) return l;
	int mid = (l + r) >> 1;
	if(cnt[x<<1] < k) return kth(x<<1|1,mid+1,r,k-cnt[x<<1]);
	return kth(x<<1,l,mid,k);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int j = 0;j < 3;j++) {
		for(int i = 1;i <= n;i++) {
			cin >> a[i][j];
			if(j) a[i][j] += a[i][j-1];
			v[a[i][j]+1][j]++;
		}
	}
	cin >> Q;
	g[0] = n;
	for(int i = 1;i <= m;i++) {
		for(int j = 0;j < 3;j++) {
			g[j] -= v[i][j];
			g[j+1] += v[i][j];
		}
		for(int j = 0;j < 3;j++) {
			sum[i] += g[j]*(j*j+1);
		}
	}
	build(1,1,m);
	while(Q--) {
		int x; cin >> x;
		if(cnt[1] < x) cout << "0\n";
		else {
			int y = kth(1,1,m,x);
			cout << sum[y] << '\n';
			update(1,1,m,y);
		}
	}
}