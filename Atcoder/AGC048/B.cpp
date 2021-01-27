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
const long long llINF = 5e18;
long long mod;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi; 
typedef long long ll;
int n;
int a[100005],b[100005];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= n;i++) cin >> b[i];
	ll ans = 0;
	for(int i = 1;i <= n;i++) {
		if((i & 1) == 0) swap(a[i],b[i]);
		ans += a[i];
		b[i] -= a[i];
	}
	sort(b+1,b+n+1);
	reverse(b+1,b+n+1);
	for(int i = 1;i <= n/2;i++) ans += b[i];
	cout << ans;
}