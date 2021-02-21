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
const int MAXN = 20000;
const int MAXM = 4000000;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pl;
typedef pair <ll,ll> pi;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n;
pl a[200005];
bool isok[200005];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while(T--) {
		cin >> n;
		ll sum = 0;
		for(int i = 1;i <= n;i++) cin >> a[i].x, sum += a[i].x, a[i].y = i;
		sort(a+1,a+n+1);
		sum -= a[n].x;
		vec ans; ans.pb(a[n].y);
		for(int i = n-1;i >= 1;i--) {
			if(sum >= a[i+1].x) ans.pb(a[i].y);
			else break;
			sum -= a[i].x;
		}
		sort(all(ans));
		cout << ans.size() << '\n';
		for(int i : ans) cout << i << ' ';
		cout << '\n';
	}
}