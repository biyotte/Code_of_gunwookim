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
ll d,m,sum,cnt,a[500005];
int n;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> m >> d >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a+1,a+n+1), reverse(a+1,a+n+1);
	for(int i = 1;i <= n&&sum < m;i++) {
		if(a[i]-abs(sum-d) <= 0) continue;
		cnt++, sum += a[i]-abs(sum-d);
	}
	if(sum >= m) {
		cout << cnt;
		return 0;
	}
	reverse(a+1,a+n+1);
	int it = lower_bound(a+1,a+n+1,m-d)-a; it = n-it+1;
	if(it == n+1) {
		cout << 0;
		return 0;
	}
	reverse(a+1,a+n+1);
	cnt = 1, sum = 0;
	for(int i = 1;i <= n&&sum < d;i++) {
		if(i == it) continue;
		if(a[i]-abs(sum-d) <= 0) continue;
		cnt++, sum += a[i]-abs(sum-d);
	}
	if(sum+a[it]-abs(d-sum) >= m) cout << cnt;
	else cout << 0;
} 