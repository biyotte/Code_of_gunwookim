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
const long long mod = 998244353;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n;
ll a[105],k,ans,sum;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); 
	int T; cin >> T;
	while(T--) {
		cin >> n >> k;
		sum = ans = 0;
		for(int i = 1;i <= n;i++) cin >> a[i];
		sum = a[1];
		for(int i = 2;i <= n;i++) {
			if(a[i]*100 > k*sum) ans += (100*a[i]+k-1)/k-sum, sum = (100*a[i]+k-1)/k;
			sum += a[i];
		}
		cout << ans << '\n';
	}
}