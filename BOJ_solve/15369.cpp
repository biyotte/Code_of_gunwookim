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
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,k;
int a[500005];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	if(a[n-k] > k) {
		cout << -1;
		return 0;
	}
	for(int i = 1;i <= k;i++) if(a[n-k+i] <= i-1) {
		cout << -1;
		return 0;
	}
	for(int i = 1;i <= n-k;i++) cout << a[i] << ' ';
	for(int i = n;i > n-k;i--) cout << a[i] << ' ';
} 
