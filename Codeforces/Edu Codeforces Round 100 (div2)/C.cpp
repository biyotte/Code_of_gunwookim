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
const long long mod = 1e18;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n;
ll t[100005],wi[100005];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while(T--) {
		cin >> n;
		for(int i = 1;i <= n;i++) cin >> t[i] >> wi[i];
		t[n+1] = llINF;
		ll en = 0,x = 0,bu = 1,ans = 0;
		wi[0] = -1;
		for(int i = 1;i <= n+1;i++) {
			ll go = min(en,t[i]-t[i-1]);
			ll l = x, r = x+bu*go;
			en -= go, x += bu*go;
			if(l > r) swap(l,r);
			if(l <= wi[i-1]&&wi[i-1] <= r) ans++;
			if(!en) {
				en = abs(wi[i]-x);
				if(wi[i] == x) bu = 1;
				else bu = (wi[i]-x)/abs(wi[i]-x);
			}
		}
		cout << ans << '\n';
	}
}