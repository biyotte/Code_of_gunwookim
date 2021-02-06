#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define all(v) v.begin(),v.end()
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
using namespace std;
const long long INF = 2e9;
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
int n,Q,L,R,mx,a[1000005];
int g[1000005],sum[1000005];
char in[1000005];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> Q >> in+1;
	for(int i = 1;i <= n;i++) a[i] = (in[i] == 'T' ? 2 : 1), sum[i] = sum[i-1]+a[i];
	for(int i = n;i >= 1;i--) {
		if(a[i] == 2) g[i] = g[i+1]+1;
		else g[i] = 0;
		if(mx < g[i]) mx = g[i], L = i, R = i+g[i]-1;
	}
	while(Q--) {
		int k; cin >> k;
		if(k % 2 == 0&&k/2 <= mx) {
			cout << L << ' ' << R << '\n';
			continue;
		}
		int it = lower_bound(sum+1,sum+n+1,k)-sum;
		int l = 1, r = it;
		if(it == n+1) {
			cout << "NIE\n";
			continue;
		}
		if(sum[it] == k) {
			cout << "1 " << it << '\n';
			continue;
		}
		int lm = g[2], rm = g[it+1];
		int len = min(lm,rm);
		l += len+1, r += len+1;
		if(lm < rm) l++;
		if(r == n+1||sum[r]-sum[l-1] != k) {
			cout << "NIE\n";
			continue;
		} 
		cout << l << ' ' << r << '\n';
	}
}