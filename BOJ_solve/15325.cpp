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
int n;
ll k,ans,a[45],h[45],cnt[45];
vec v[45];

void go(int x,ll sum) {
	if(sum >= k) {
		ans += cnt[x];
		return;
	}
	for(int i : v[x]) go(i,sum+a[i]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	for(int i = 1;i <= n;i++) cin >> h[i] >> a[i];
	for(int i = 1;i <= n;i++) {
		for(int j = i+1;j <= n;j++) {
			if(h[i] <= h[j]) v[i].pb(j);
		}
	}
	for(int i = n;i >= 1;i--) {
		cnt[i] = 1;
		for(int j : v[i]) cnt[i] += cnt[j];
	}
	for(int i = 1;i <= n;i++) go(i,a[i]);
	cout << ans;
}