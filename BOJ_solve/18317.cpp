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
int n,Q;
ll d[5005][5005],cnt[5005][5005],a[5005];
ll cnt2[2000005];
// d[i][j] : i~j 구간에 있는 개수
// cnt[i][j] : s[i] + s[j] + x = 0인 x의 개수

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); 
	cin >> n >> Q;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= n;i++) {
		for(int j = i+1;j <= n;j++) {
			ll val = 1000000-a[i]-a[j];
			if(0 <= val&&val <= 2000000) cnt[i][j] = cnt2[val];
			cnt2[1000000+a[j]]++;
		}
		for(int j = i+1;j <= n;j++) cnt2[1000000+a[j]]--;
	}
	for(int i = n;i >= 1;i--) {
		for(int j = i+1;j <= n;j++) {
			d[i][j] = cnt[i][j]+d[i+1][j]+d[i][j-1]-d[i+1][j-1];
		}
	}
	while(Q--) {
		int l,r; cin >> l >> r;
		cout << d[l][r] << '\n';
	}
}
