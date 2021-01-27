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
const long long mod = 1e18;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,m;
ll a[200005],b[200005];
ll d[200005];

ll gcd(ll x,ll y) {
	if(!y) return x;
	return gcd(y,x%y);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= m;i++) cin >> b[i];
	sort(a+1,a+n+1);
	ll g;
	for(int i = 1;i < n;i++) {
		d[i] = a[i+1]-a[i];
		if(i == 1) g = d[i];
		else g = gcd(g,d[i]);
	}
	for(int i = 1;i <= m;i++) {
		if(n == 1) cout << a[1]+b[i] << ' ';
		else cout << gcd(a[1]+b[i],g) << ' ';
	}
}