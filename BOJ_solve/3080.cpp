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
const long long llINF = 1e18;
long long mod = 1e9+7;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi; 
typedef long long ll;
int n,len[3005];
char a[3005][3005];
ll ans = 1,fact[35];
vec v[3005];

void go(int x,int y) {
	for(int i = 0;i < n)
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	vec b;
	for(int i = 1;i <= n;i++) {
		cin >> a[i]+1, b.pb(i);
		len[i] = strlen(a[i]+1)+1;
		a[i][len[i]] = 'Z', a[i][len[i]]++;
	}
	fact[0] = 1;
	for(int i = 1;i <= 30;i++) fact[i] = fact[i-1]*i%mod;
	go(1,b);
	cout << ans;
}