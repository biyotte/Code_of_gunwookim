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
int a[105];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	int ans = a[2]-a[1];
	for(int i = 3;i <= n;i++) {
		ans = __gcd(ans,a[i]-a[i-1]);
	}
	vec res;
	for(int i = 1;i*i <= ans;i++) {
		if(ans % i == 0) {
			if(i != 1) res.pb(i);
			if(ans/i != i&&ans/i != 1) res.pb(ans/i);
		}
	}
	sort(all(res));
	for(int i : res) cout << i << ' ';
}