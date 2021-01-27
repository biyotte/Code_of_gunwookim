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
const long long mod = 998244353;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int T,n;
pl a[100005];
multiset <ll> s;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); 
	cin >> T;
	while(T--) {
		cin >> n;
		ll ans = llINF;
		s.clear();
		for(int i = 1;i <= n;i++) cin >> a[i].x >> a[i].y, s.insert(a[i].y);
		sort(a+1,a+n+1);
		ll mx = -llINF;
		for(int i = n;i >= 1;i--) {
			s.erase(s.find(a[i].y));
			auto itr = s.lower_bound(a[i].x);
			if(a[i].x <= mx) {
				ans = min(ans,mx-a[i].x);
				break;
			}
			ans = min(ans,abs(mx-a[i].x));
			if(itr != s.end()) ans = min(ans,abs((*itr)-a[i].x));
			if(itr != s.begin()) {
				auto itl = prev(itr);
				ans = min(ans,abs((*itl)-a[i].x));
			}
			mx = max(mx,a[i].y);
		}
		cout << ans << '\n';
	}
}