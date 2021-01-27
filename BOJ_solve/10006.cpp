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
int n,m,a[1000005];
int cnt[1000005],correct;
int c[1000005];
pi input[1000005];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); 
	cin >> n >> m;
	for(int i = 1;i <= m;i++) cin >> input[i].x;
	for(int i = 1;i <= m;i++) {
		cin >> input[i].y;
		c[input[i].y] = input[i].x;
	}
	for(int i = 1;i <= n;i++) cin >> a[i];
	int r = 1,ans = 0;
	for(int l = 1;l <= n;l++) {
		r = max(r,l);
		while(r <= n&&c[a[r]] >= cnt[a[r]]+1) {
			if(++cnt[a[r]] == c[a[r]]) correct++;
			if(correct == m) ans++;
			r++;
		}
		if(l != r&&cnt[a[l]] == c[a[l]]) correct--;
		if(l != r) cnt[a[l]]--;
	}
	cout << ans;
}
