#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define all(v) v.begin(),v.end()
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
int n,Q,mx,a[1000005];
int dgo[1000005],lgo[1000005];
int dba[1000005],lba[1000005];
int i,l,r,ans;
ll sum,su;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> Q;
	for(i = 1;i <= n;i++) cin >> a[i], su += a[i], mx = max(mx,a[i]);
	a[0] = a[n];
	while(Q--) {
		int s; cin >> s;
		if(s < mx) {
			cout << "NIE\n";
			continue;
		}
		if(s >= su) {
			cout << "1\n";
			continue;
		}
		sum = 0;
		for(l = 1,r = 1;l <= n;l++) {
			while(sum+a[r] <= s) {
				sum += a[r++];
				if(r > n) r = 1;
			}
			lgo[l] = r;
			sum -= a[l];
		}
		sum = 0;
		for(l = n,r = n;r >= 1;r--) {
			while(sum+a[l-1] <= s) {
				sum += a[--l];
				if(l == 0) l = n;
			}
			lba[r] = l;
			sum -= a[r-1];
		}
		for(i = 1;i <= n;i++) {
			if(lba[i] >= i) dgo[i] = 0;
			else dgo[i] = dgo[lba[i]]+1;
		}
		for(i = n;i >= 1;i--) {
			if(lgo[i] <= i) dba[i] = 0;
			else dba[i] = dba[lgo[i]]+1;
			dgo[i] += dba[i];
		}
		for(i = 1;i <= n;i++) {
			if(lba[i] >= i) lba[i] = i;
			else lba[i] = lba[lba[i]];
		}
		for(i = n;i >= 1;i--) {
			if(lgo[i] <= i) dba[i] = i;
			else dba[i] = dba[lgo[i]];
		}
		ans = INF;
		for(i = 1;i <= n;i++) {
			l = lgo[dba[i]], r = lba[i];
			while(l < r) l = lgo[l], dgo[i]++;
			ans = min(ans,dgo[i]+1);
		}
		cout << ans << '\n';
	}
}