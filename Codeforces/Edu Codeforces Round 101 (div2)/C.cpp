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
int n,k;
int a[200005];

// not solved

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while(T--) {
		cin >> n >> k;
		for(int i = 1;i <= n;i++) cin >> a[i];
		int l = 0,r = 0,fl = 1;
		for(int i = 2;i <= n;i++) {
			if(a[i-1] > a[i]) {
				l = max(0,l+(a[i-1]-a[i])-(k-1));
				r = k-1;
			}
			else if(a[i-1] < a[i]) {
				l = 0;
				r = min(k-1,r+(k-1)-(a[i]-a[i-1]));
			}
			else l = 0, r = k-1;
			if(r < 0||l >= k) fl = 0;
		}
		reverse(a+1,a+n+1);
		for(int i = 2;i <= n;i++) {
			if(a[i-1] > a[i]) {
				l = max(0,l+(a[i-1]-a[i])-(k-1));
				r = k-1;
			}
			else if(a[i-1] < a[i]) {
				l = 0;
				r = min(k-1,r+(k-1)-(a[i]-a[i-1]));
			}
			else l = 0, r = k-1;
			if(r < 0||l >= k) fl = 0;
		}
		if(fl) cout << "Yes\n";
		else cout << "No\n";
	}
}