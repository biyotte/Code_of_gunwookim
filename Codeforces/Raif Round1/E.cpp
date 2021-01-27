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
int n,k;
ll a[100005];

ll calc(ll x,ll y) {
	ll nam = x%y;
	ll m = x/y;
	return m*m*(y-nam)+(m+1)*(m+1)*nam;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	//int T; cin >> T;
	int T; T = 1;
	priority_queue <pair<ll,pl>> q;
	while(T--) {
		cin >> n >> k;
		ll ans = 0;
		for(int i = 1;i <= n;i++) cin >> a[i], ans += a[i]*a[i], q.push({a[i]*a[i]-(a[i]/2)*(a[i]/2)-((a[i]+1)/2)*((a[i]+1)/2),{i,1}});
		for(int i = n+1;i <= k;i++) {
			auto x = q.top(); q.pop();
			ans -= x.x;
			ll t = x.y.y;
			q.push({calc(a[x.y.x],t+1)-calc(a[x.y.x],t+2),{x.y.x,t+1}});
		}
		cout << ans;
	}
}