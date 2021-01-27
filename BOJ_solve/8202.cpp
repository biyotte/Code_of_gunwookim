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
int n,sum,a[5005];
int cnt[5005];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) {
		int x,y; cin >> x;
		cnt[x]++;
		sum += x;
		a[i] = x;
		while(x--) cin >> y;
	}
	sort(a+1,a+n+1), reverse(a+1,a+n+1);
	int ans = 0,s = 0;
	for(int i = 1;i < n;i++) {
		s += a[i]-i+1;
		if(s*2 == sum) {
			if(a[i] == a[i+1]) ans += cnt[a[i]];
			else ans++;
		}
	}
	cout << ans;
}