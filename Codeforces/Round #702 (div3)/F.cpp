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
int cnt[200005],n;
map <int,int> cn;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while(T--) {
		cin >> n;
		cn.clear();
		for(int i = 0;i <= n;i++) cnt[i] = 0;
		for(int i = 1;i <= n;i++) {
			int x; cin >> x;
			cn[x]++;
		}
		for(pi i : cn) cnt[i.y]++;
		ll ans = n,sum = n,sz = 0,dep = 0;
		for(ll i = n;i >= 0;i--) {
			sum -= cnt[i]*i;
			sz += cnt[i];
			dep += cnt[i]*i;
			ans = min(ans,dep-sz*i+sum);
		}
		cout << ans << '\n';
	}
}