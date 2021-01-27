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
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n;
int a[3005],sum[3005];

int s(int l,int r) {
	return sum[r]-sum[l-1];
}
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while(T--) {
		cin >> n;
		for(int i = 1;i <= n;i++) cin >> a[i], sum[i] = sum[i-1]+a[i];
		int ans = n-1;
		for(int i = 1;i <= n;i++) {
			int val = s(1,i);
			int nope = 0,cnt = 1,su = 0;
			for(int j = i+1;j <= n;j++) {
				if(su+a[j] == val) {
					cnt++; su = 0;
					continue;
				}
				if(su+a[j] > val) {
					nope = 1;
					break;
				}
				su += a[j];
			}
			if(su&&su < val) {
				nope = 1;
			}
			if(!nope) ans = min(ans,n-cnt);
		}
		cout << ans << '\n';
	}
}