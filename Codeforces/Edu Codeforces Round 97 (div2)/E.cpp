#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define all(v) v.begin(),v.end()
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
using namespace std;
const int INF = 2e9;
const long long llINF = 1e18;
long long mod = 1e9+7;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef vector <int> vec;
typedef vector <pi> vecpi; 
typedef long long ll;
int n,k;
ll a[500005],c[500005];
ll b[500005];


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	//int T; cin >> T;
	int T = 1;
	int ans;
	while(T--) {
		cin >> n >> k;
		ans = 0;
		for(int i = 1;i <= n;i++) cin >> a[i];
		for(int i = 1;i <= k;i++) cin >> b[i+1];
		b[1] = 0, b[k+2] = n+1;
		a[0] = -llINF, a[n+1] = llINF;
		vector<ll> lis;
		for(int i = 2;i <= k+2;i++) {
			int l = b[i-1], r = b[i];
			if(a[r]-a[l] < r-l) {
				cout << -1;
				return 0;
			}
			lis.clear();
			for(int j = l+1;j < r;j++) {
				if(a[j]-(a[l]+j-l) < 0||(a[r]-r+j)-a[j] < 0) continue;
				if(lis.empty()||lis.back() <= a[j]-(a[l]+j-l)) lis.pb(a[j]-(a[l]+j-l));
				else {
					int it = upper_bound(all(lis),a[j]-(a[l]+j-l))-lis.begin();
					lis[it] = a[j]-(a[l]+j-l);
				}
			}
			ans += (int)lis.size();
		}
		cout << n-ans-k << '\n';
	}
}