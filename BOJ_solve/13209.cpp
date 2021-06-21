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
int T;
int n,k,cnt;
ll a[100005],mid;
vec v[100005];

ll go(int x,int pr) {
	vector <ll> val;
	for(int i : v[x]) {
		if(i == pr) continue;
		val.pb(go(i,x));
	}
	sort(all(val));
	int pv = val.size();
	ll sum = a[x];
	for(int i = 0;i < val.size();i++) {
		if(sum+val[i] > mid) {
			pv = i;
			break;
		}
		sum += val[i];
	}
	cnt += (int)val.size()-pv;
	return sum;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	while(T--) {
		cin >> n >> k;
		ll mx = -INF;
		for(int i = 1;i <= n;i++) cin >> a[i], mx = max(mx,a[i]);
		for(int i = 1;i <= n;i++) v[i].clear();
		for(int i = 1;i < n;i++) {
			int x,y; cin >> x >> y;
			v[x].pb(y), v[y].pb(x);
		}
		ll l = mx, r = llINF;
		while(l < r) {
			mid = (l + r) >> 1;
			cnt = 0; go(1,-1);
			if(cnt <= k) r = mid;
			else l = mid+1;
		}
		cout << l << '\n';
	}
}