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
const long long llINF = 1e16;
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
 int n;
vec a;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 1;i <= n;i++) {
		int x; cin >> x; a.pb(x);
	}
	a.erase(unique(all(a)),a.end());
	int ans = 0;
	for(int i = 0;i < a.size();i++) {
		if(i >= 2&&((a[i-2] < a[i-1]&&a[i-1] > a[i])||(a[i-2] > a[i-1]&&a[i-1] < a[i]))) ans++;
	}
	cout << ans;
}