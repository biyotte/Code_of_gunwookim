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
ll d[105][1000005],m;
int n,k;
ll su[105];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k >> m;
	d[0][0] = 1;
	for(int i = 1;i <= n;i++) {
		memset(su,0,sizeof(su));
		for(int j = 0;j <= i*(i+1)/2*k;j++) {
			su[j%i] += d[i-1][j]-(j-i*(k+1) >= 0 ? d[i-1][j-i*(k+1)] : 0);
			su[j%i] = (su[j%i]+3*m)%m;
			d[i][j] = su[j%i];
		}
	}
	for(int i = 1;i <= n;i++) {
		ll ans = 0;
		for(int j = 0;j <= i*(i+1)/2*k;j++) ans = (ans+d[i-1][j]*d[n-i][j])%m;
		ans = (ans*(k+1)-1)%m;
		cout << ans << '\n';
	}
}