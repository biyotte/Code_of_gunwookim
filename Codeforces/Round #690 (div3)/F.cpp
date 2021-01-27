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
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,m;
pi a[200005];
int sum[200005];
int t[400005];
vec rev;

bool cmp(pi x,pi y) {
	if(x.y == y.y) return x.x > y.x;
	return x.y < y.y;
}

void build() {
	for(int i = 1;i <= m;i++) t[i] = 0;
}

void update(int x) {
	for(;x <= m;x += x&-x) t[x]++;
}

int query(int x) {
	int ret = 0;
	for(;x;x -= x&-x) ret += t[x];
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while(T--) {
		cin >> n;
		rev.clear();
		for(int i = 1;i <= n;i++) {
			sum[i] = 0;
			cin >> a[i].x >> a[i].y;
			rev.pb(a[i].x);
			rev.pb(a[i].y);
		}
		sort(all(rev)); rev.erase(unique(all(rev)),rev.end());
		for(int i = 1;i <= n;i++) {
			a[i].x = lower_bound(all(rev),a[i].x)-rev.begin()+1;
			a[i].y = lower_bound(all(rev),a[i].y)-rev.begin()+1;
		}
		sort(a+1,a+n+1,cmp);
		int ans = n;
		m = rev.size();
		build();
		for(int i = 1;i <= n;i++) {
			sum[i] += query(a[i].y)-query(a[i].x-1);
			update(a[i].y);
		}
		build();
		for(int i = n;i >= 1;i--) {
			sum[i] += query(a[i].y);
			update(a[i].x);
		}
		for(int i = 1;i <= n;i++) ans = min(ans,n-sum[i]-1);
		cout << ans << '\n';
	}
}