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
int n,ans;
int a[1000005],sum[1000005];
multiset <int> s;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i], a[i+n] = a[i];
	for(int i = 1;i <= 2*n;i++) sum[i] = sum[i-1]+a[i];
	for(int i = n/2;i < n;i++) s.insert(sum[i]-sum[i-n/2]);
	for(int i = n;i < 2*n;i++) {
		s.insert(sum[i]-sum[i-n/2]);
		s.erase(s.find(sum[i-n/2-n%2]-sum[i-n]));
		ans = max(ans,sum[n]-*(s.rbegin()));
	}
	cout << ans;
} 
