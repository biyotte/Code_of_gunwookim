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
int n,k,Q,a[100005];
int cnt[100005][21];
ll ans[100005];

// not solved

struct Query {
	int l,r,idx;
}qq[200005];

void DnC(int l,int r,vector <Query> &q) {
	if(l == r||q.empty()) return;
	int mid = (l + r) >> 1;
	vector <Query> L,R;
	for(auto i : q) {
		if(i.r < mid) L.pb(i);
		else if(i.l > mid) R.pb(i);
		else {
			for(int j = 1;j <= k;j++) {
				ans[i.idx] += 1LL*(cnt[n][j]-cnt[mid-1][j])*cnt[mid-1][j];
				ans[i.idx] %= mod;
			}
		}
	}
	DnC(l,mid,L), DnC(mid+1,r,R);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= k;j++) cnt[i][j] = cnt[i-1][j];
		cnt[i][a[i]]++;
	}
	cin >> Q;
	vector <Query> in;
	for(int i = 1;i <= Q;i++) {
		cin >> qq[i].l >> qq[i].r;
		qq[i].idx = i;
		in.pb(qq[i]);
	}
	DnC(1,n,in);
	for(int i = 1;i <= Q;i++) cout << ans[i] << '\n';
}