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
const int mod = 998244353;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n;
int a[300005];
ll s[300005];

ll sum(int l,int r) {
	return s[r]-s[l-1];
}

bool isok(ll x) {
	if(sum(1,n) < x) return false;
	for(int l = 1,r = 1,k;l <= n;l++) {
		while(sum(l,r) < x) r++;
		if(l == 1) k = r+1;
		while(sum(r+1,k) < x) k++;
		if(l+n-1 <= k+1) continue;
		if(sum(k+1,l+n-1) >= x) return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= n;i++) {
		a[i+n] = a[i+2*n] = a[i];
	}
	for(int i = 1;i <= 3*n;i++) s[i] = s[i-1]+a[i];
	ll l = 1,r = llINF;
	while(l < r) {
		ll mid = (l + r + 1) >> 1;
		if(isok(mid)) l = mid;
		else r = mid-1;
	}
	cout << l;
} 
