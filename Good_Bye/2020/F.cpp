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
int n;
ll a[500005],d[500005];

// not solved

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a+1,a+n+1), reverse(a+1,a+n+1);
	for(int i = 1;i < n;i++) d[i] = a[i]-a[i+1];
	ll ans = llINF;
	for(int i = 1;i <= n-6;i++) {
		if(a[i] < a[i+1]+a[i+2]&&a[i+1]+a[i+2] < a[i+3]+a[i+4]+a[i+5]+a[i+6]) ans = min(ans,a[i]+a[i+1]+a[i+2]+a[i+3]+a[i+4]+a[i+5]+a[i+6]);
	}
	if(ans == llINF) ans = -1;
	cout << ans;
}