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
int a[5005],mi[5005];
ll ans;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while(T--) {
		cin >> n;
		ans = 0;
		for(int i = 1;i <= n;i++) cin >> a[i], mi[i] = 0;
		for(int i = 1;i <= n;i++) {
			int li = min(n,i+a[i]);
			mi[i+1] += max(0,mi[i]-a[i]+1);
			for(int j = i+2;j <= li;j++) mi[j]++;
			ans += max(0,a[i]-mi[i]-1);
		}
		cout << ans << '\n';
	}
}