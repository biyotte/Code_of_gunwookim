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
const long long llINF = 1e18+10;
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
int n,val,wi;
int a[100005];
int cnt[200005];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> val;
	for(int i = 1;i <= n;i++) {
		int x; cin >> x;
		if(x < val) a[i] = 1;
		else if(x == val) wi = i, a[i] = 0;
		else a[i] = -1;
	}
	ll ans = 1;
	for(int i = wi-1;i >= 1;i--) {
		a[i] += a[i+1];
		cnt[a[i]+n]++;
		if(!a[i]) ans++;
	}
	for(int i = wi+1;i <= n;i++) {
		a[i] += a[i-1];
		if(!a[i]) ans++;
		ans += cnt[-a[i]+n];
	}
	cout << ans;
}
