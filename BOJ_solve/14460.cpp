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
const int MAXN = 100000;
const int MAXM = 1000000;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,k,a[100005],b[100005];
int t[100005];
pi wi[100005];
ll ans;

void update(int x,int val) {
	for(;x <= n;x += x&-x) t[x] += val;
}

int query(int l,int r) {
	if(r < 1||l > n) return 0;
	int ret = 0;
	for(;r;r -= r&-r) ret += t[r];
	for(l--;l;l -= l&-l) ret -= t[l];
	return ret;
}

void go(int l,int r) {
	if(l == r) return;
	int mid = (l + r) >> 1;
	vecpi L,R;
	for(int i = l;i <= mid;i++) L.pb(wi[i]);
	for(int i = mid+1;i <= r;i++) R.pb(wi[i]);
	sort(all(L)), sort(all(R));
	int g = 0;
	for(pi i : L) {
		while(g < R.size()&&R[g].x < i.x) update(R[g++].y,1);
		ans += query(1,i.y-k-1)+query(i.y+k+1,n);
	}
	for(int i = 0;i < g;i++) update(R[i].y,-1);
	go(l,mid), go(mid+1,r);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	for(int i = 1;i <= n;i++) {int x; cin >> x, a[x] = i;}
	for(int i = 1;i <= n;i++) {int x; cin >> x, b[x] = i;}
	for(int i = 1;i <= n;i++) wi[a[i]] = {b[i],i};
	go(1,n);
	cout << ans;
}