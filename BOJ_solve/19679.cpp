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
const long long mod = 1e9+7;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n;
ll h[100005],w[100005],sw;

struct Stack {
	ll x,y,idx;
};

stack <Stack> s;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> h[i];
	for(int i = 1;i <= n;i++) cin >> w[i];
	ll ans = 0;
	s.push({0,0});
	for(int i = 1;i <= n+1;i++) {
		while(s.size() > 1&&s.top().y >= h[i]) {
			ll y = s.top().y; s.pop();
			ll len = s.top().y;
			ll wlen = (sw-s.top().x-w[s.top().idx])%mod;
			ans += y*(y+1)/2LL%mod*(wlen*(wlen+1)/2LL%mod)%mod;
			ans -= max(len,h[i])*(max(len,h[i])+1)/2LL%mod*(wlen*(wlen+1)/2LL%mod)%mod;
			ans %= mod;
			ans += mod;
			ans %= mod;
		}
		s.push({sw,h[i],i});
		sw += w[i];
	}
	cout << ans;
}
