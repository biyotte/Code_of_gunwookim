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
int n;
ll p,a[1000005],nam,diff;

ll mpow(ll x,ll M) {
	if(!M) return 1;
	ll tmp = mpow(x,M/2);
	if(M & 1) return tmp*tmp%mod*x%mod;
	return tmp*tmp%mod;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while(T--) {
		cin >> n >> p;
		ll mn = 0,gop = 1;
		while(1) {
			if(p == 1) {
				mn = INF;
				break;
			}
			gop *= p;
			mn++;
			if(gop >= n) break;
		}
		for(int i = 1;i <= n;i++) cin >> a[i];
		sort(a+1,a+n+1);
		a[0] = -1;
		ll la = a[n],cnt = 1;
		nam = 0;
		diff = 0;
		ll dif = 0;
		for(int i = n-1;i >= 0;i--) {
			if(la != a[i]) {
				if(dif >= mn&&nam) nam = n;
				else nam = min((ll)n,nam*mpow(p,dif));

				dif = la-a[i];
				ll nam2 = min(nam,cnt);
				nam -= nam2;
				if(!nam) {
					diff = 0;
					cnt -= nam2;
					if(cnt % 2) diff = mpow(p,la), nam = 1;
				}
				else {
					diff = (diff-mpow(p,la)*cnt%mod+mod)%mod;
				}
				cnt = 0;
				la = a[i];
			}
			cnt++;
		}
		cout << diff << '\n';
	}
}
