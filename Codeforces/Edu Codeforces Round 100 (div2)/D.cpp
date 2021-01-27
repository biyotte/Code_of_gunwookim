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
int n,c[400005];
int a[200005];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while(T--) {
		cin >> n;
		for(int i = 1;i <= 2*n;i++) c[i] = -1;
		for(int i = 1;i <= n;i++) cin >> a[i];
		for(int i = 1;i <= n;i++) c[a[i]] = 1;
		int l = 0,r = 0,cnt = 0;
		for(int i = 1;i <= 2*n;i++) {
			cnt += c[i];
			l = max(l,cnt);
		}
		cnt = 0;
		for(int i = 2*n;i >= 1;i--) {
			cnt += c[i];
			r = max(r,cnt);
		}
		r = n-r;
		cout << r-l+1 << '\n';
	}
}