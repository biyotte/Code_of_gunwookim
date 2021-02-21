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
int n,m;
ll a[200005],sum[200005],mx[200005];

int getIdx(ll x) {
	int it = lower_bound(mx+1,mx+n+1,x)-mx;
	return it;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while(T--) {
		cin >> n >> m;
		mx[0] = -llINF;
		for(int i = 1;i <= n;i++) {
			cin >> a[i];
			sum[i] = sum[i-1]+a[i];
			mx[i] = max(mx[i-1],sum[i]);
		}
		while(m--) {
			ll x; cin >> x;
			if(x <= mx[n]) {
				int idx = getIdx(x);
				cout << idx-1 << ' ';
				continue;
			}
			if(sum[n] <= 0) {
				cout << "-1 ";
				continue;
			}
			ll ti = (x-mx[n]+sum[n]-1)/sum[n];
			x -= ti*sum[n];
			int idx = getIdx(x);
			cout << ti*n+idx-1 << ' ';
		}
		cout << '\n';
	}
}