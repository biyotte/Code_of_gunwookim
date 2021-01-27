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
ll sg[100005],sd[100005];
ll lmx[100005];

struct Gold {
	ll x,g,d;
}a[100005];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) {
		cin >> a[i].x >> a[i].g >> a[i].d;
		sg[i] = sg[i-1]+a[i].g;
		sd[i] = sd[i-1]+a[i].d;
		lmx[i] = sd[i]-a[i].x;
	}
	ll ans = 0;
	for(int i = n-1;i >= 1;i--) lmx[i] = max(lmx[i],lmx[i+1]);
	for(int i = 1;i <= n;i++) {
		int l = i, r = n;
		while(l < r) {
			int mid = (l + r + 1) >> 1;
			if(sd[i-1]-a[i].x <= lmx[mid]) l = mid;
			else r = mid-1;
		}
		ans = max(ans,sg[l]-sg[i-1]);
	}
	cout << ans;
}