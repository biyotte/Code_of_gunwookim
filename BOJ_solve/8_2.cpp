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
const long long llINF = 5e18;
const long long mod = 1e9+7;
const long long hmod1 = 1e9+409;
const long long hmod2 = 1e9+433;
const long long base = 257;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
string a,b;
int n,m,cnt[30];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	cin >> a >> b;
	n = a.length(), m = b.length();
	for(int i = 0;i < m-1;i++) {
		cnt[b[i]-'a']++;
	}
	ll ans = 1LL*n*m;
	for(int i = 1;i < n;i++) ans -= cnt[a[i]-'a'];
	cout << ans;
}
