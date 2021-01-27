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
int n,k,cnt[300005];
int a[300005],la;
int now[300005];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	for(int i = 1;i <= n;i++) {
		int x; cin >> x;
		a[i] = x;
		cnt[x]++;
	}
	sort(a+1,a+n+1);
	now[0] = k;
	for(int i = 0;i <= n;i++) {
		for(int j = 1;j <= cnt[i];j++) {
			if(now[i]) {
				now[i]--;
				now[i+1]++;
			}
		}
	}
	int ans = 0;
	for(int i = 0;i <= n;i++) ans += now[i]*i;
	cout << ans;
}