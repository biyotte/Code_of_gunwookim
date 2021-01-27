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
const long long llINF = 1e18;
const long long mod = 1e9+7;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,k,sum[300005],dp[300005];
char a[300005];
multiset <int> s[300005],d;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k >> a+1;
	for(int i = 1;i <= n;i++) {
		if(a[i] == 'H') sum[i] = sum[i-1]+1;
		else sum[i] = sum[i-1]-1;
	}
	d.insert(0), s[0].insert(0);
	for(int i = 1;i <= n;i++) {
		int val = *d.begin();
		dp[i] = val+(*s[val].begin() >= sum[i]);
		d.insert(dp[i]), s[dp[i]].insert(sum[i]);
		if(i >= k) d.erase(d.find(dp[i-k])), s[dp[i-k]].erase(s[dp[i-k]].find(sum[i-k]));
	}
	cout << dp[n];
}
