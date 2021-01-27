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
ll a[200005];
int n;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while(T--) {
		cin >> n;
		for(int i = 1;i <= n;i++) a[i] = i;
		vecpi ans;
		for(ll i = n-1;i >= 3;i--) {
			if((i+1)*(i+1) <= a[n]) {
				ans.pb({n,i});
				a[n] = a[n]/i+(a[n]%i > 0);
			}
			ans.pb({i,n});
		}
		while(a[n] > 2) a[n] = (a[n]+1)/2, ans.pb({n,2});
		ans.pb({2,n});
		if(ans.size() > n+5) return -1;
		cout << ans.size() << '\n';
		for(pi i : ans) cout << i.x << ' ' << i.y << '\n';
	}
}