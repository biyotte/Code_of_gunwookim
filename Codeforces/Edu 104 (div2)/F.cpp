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
const int MAXN = 20000;
const int MAXM = 4000000;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
char in[55];
int n,a[55],cnt[55],ans;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> in+1;
	n = strlen(in+1);
	for(int i = 1;i <= n;i++) a[n-i+1] = in[i]-'0';
	for(int i = n;i >= 1;i--) {
		cnt[i] = a[i];
		int val = min(cnt[i],cnt[i+1]);
		cnt[i+1] -= val, ans += val;
	}
	for(int i = 1;i <= n;i++) cout << cnt[i] << ' ', ans += (2*i-1)*cnt[i];
	cout << ans;
}
