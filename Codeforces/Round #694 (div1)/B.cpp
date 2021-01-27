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
int n,Q,q[300005],ans0,ans1;
int cn[1000005];
ll a[300005];
vec rev;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while(T--) {
		cin >> n;
		rev.clear();
		for(int i = 1;i <= n;i++) {
			a[i] = 1;
			int x,cnt; cin >> x;
			for(int j = 2;j*j <= x;j++) {
				if(x % j == 0) {
					cnt = 0;
					while(x % j == 0) {
						cnt ^= 1;
						x /= j;
					}
					if(cnt) a[i] *= j;
				}
			}
			a[i] *= x;
			rev.pb(a[i]);
			cn[a[i]]++;
		}
		int pl = 0;
		ans0 = 0;
		for(int i : rev) {
			ans0 = max(ans0,cn[i]);
			if(cn[i] % 2 == 0||i == 1) pl += cn[i];
			cn[i] = 0;
		}
		cin >> Q;
		while(Q--) {
			ll x; cin >> x;
			if(!x) cout << ans0 << '\n';
			else cout << max(ans0,pl) << '\n';
		}
	}
}