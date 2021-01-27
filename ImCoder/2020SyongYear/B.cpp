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
int n,T;
ll a[100005],sum[100005];

ll go(int st,int en) {
	return sum[en]+sum[en-1];
}

ll Turn(int x) {
	ll t = T-(x*2-2);
	return (t/2)*(a[x]+a[x+1]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> T;
	for(int i = 1;i <= n;i++) cin >> a[i], sum[i] = sum[i-1]+a[i];
	ll ans = 0;
	for(int i = 1;i < n;i++) {
		if(T-(i*2-2) < 0) continue;
		ans = max(ans,go(1,i)+Turn(i));
	}
	cout << ans;
}