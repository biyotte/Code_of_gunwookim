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
typedef pair <int,int> pl;
typedef pair <ll,ll> pi;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,a[200005],t[200005];
ll ans[200005];
vec rev;

struct Query {int k,l,r;};
vector <Query> q[200005][2];

void update(int x) {
	for(;x <= n;x += x&-x) t[x]++;
}

int query(int l,int r) {
	int ret = 0;
	for(;r;r -= r&-r) ret += t[r];
	for(l--;l;l -= l&-l) ret -= t[l];
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
		rev.pb(a[i]);
	}
	sort(all(rev)), rev.erase(unique(all(rev)),rev.end());
	for(int i = 1;i <= n;i++) {
		a[i] = lower_bound(all(rev),a[i])-rev.begin()+1;
		q[a[i]][0].pb({i,0,0});
	}
	for(int K = 1;K < n;K++) {
		for(int i = 1;i <= n;i++) {
			int l = K*(i-1)+2, r = K*i+1;
			if(l > n) break;
			r = min(r,n);
			q[a[i]][1].pb({K,l,r});
		}
	}
	for(int i = 1;i <= n;i++) {
		for(Query j : q[i][1]) ans[j.k] += query(j.l,j.r);
		for(Query j : q[i][0]) update(j.k);
	}
	for(int i = 1;i < n;i++) cout << ans[i] << ' ';

}