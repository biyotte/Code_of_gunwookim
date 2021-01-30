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
const long long mod = 998244353;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n;
ll c[100005];
ll a[100005],b[100005];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); 
	int T; cin >> T;
	while(T--) {
		cin >> n;
		for(int i = 1;i <= n;i++) cin >> c[i];
		for(int i = 1;i <= n;i++) cin >> a[i];
		for(int i = 1;i <= n;i++) cin >> b[i];
		ll mx = 0,ans = 0;
		if(a[2] > b[2]) swap(a[2],b[2]);
		mx = b[2]-a[2];
		for(int i = 3;i <= n;i++) {
			if(a[i] > b[i]) swap(a[i],b[i]);
			// a[i] <= b[i]
			ans = max(ans,mx+c[i-1]+1);
			if(a[i] == b[i]) mx = 0;
			else mx = max(mx+2+a[i]-1+c[i-1]-b[i],b[i]-a[i]);
		}
		ans = max(ans,mx+c[n]+1);
		cout << ans << '\n';
	}
}