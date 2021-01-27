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
const long long hmod1 = 1e9+409;
const long long hmod2 = 1e9+433;
const long long base = 257;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
ll a[100005],sum,need[100005];
int n;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	//int T = 1;
	while(T--) {
		cin >> n;
		sum = 0;
		for(int i = 1;i <= n;i++) {
			cin >> a[i];
			sum += a[i];
		}
		sort(a+1,a+n+1); reverse(a+1,a+n+1);
		ll ans = -llINF,mx;
		for(int i = 1;i <= n;i++) {
			if(i == 1) mx = a[2];
			else mx = a[1];
			if(mx*(n-1)-sum >= 0) need[i] = mx*(n-1)-sum;
			else need[i] = ((n-1)-sum%(n-1))%(n-1);
			ans = max(ans,need[i]);
		}
		cout << ans << '\n';
	}
}
// A < C < D < B <<<<<<<<<<<<<<<<<<<<<<<<<<<<<< E