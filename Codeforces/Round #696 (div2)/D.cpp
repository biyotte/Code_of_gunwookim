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
typedef long long ll;
int n;
int a[200005],b[200005];
int l[200005],lc[200005];
int r[200005],rc[200005];

// not solved

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while(T--) {
		cin >> n;
		for(int i = 1;i <= n;i++) cin >> a[i], b[i] = a[i];
		for(int i = 0;i <= n+1;i++) lc[i] = rc[i] = 0;
		int fl = 0;
		for(int i = 1;i < n;i++) {
			if(a[i] > a[i+1]) lc[i] = 1, fl++, swap(a[i],a[i+1]);
			lc[i] += lc[i-1];
			a[i+1] -= a[i];
		}
		fl = 0;
		for(int i = n;i > 1;i--) {
			if(b[i] > b[i-1]) rc[i] = 1, fl++, swap(b[i],b[i-1]);
			rc[i] += rc[i+1];
			b[i-1] -= b[i];
		}
		if(a[n]&&b[1]) {
			cout << "NO\n";
			continue;
		}
		fl = 0;
		for(int i = 1;i <= n;i++) {
			if(lc[i-1]+rc[i+1] <= 1) {
				fl = 1;
				break;
			}
		}
		if(fl) cout << "YES\n";
		else cout << "NO\n";
	}
}