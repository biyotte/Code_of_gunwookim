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
const int mod = 1e9+7;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,p[500005],c[500005],l,r;
ll A,B,lcm;

int go(int x) {
	if(c[x]) return 1;
	c[x] = 1;
	return go(p[x])+1;
}

ll gcd(ll x,ll y) {
	if(!x) return y;
	return gcd(y%x,x);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> A >> B >> l >> r;
	for(int i = 1;i <= n;i++) cin >> p[i];
	lcm = 1;
	for(int i = l+1;i <= n-r;i++) {
		ll tmp = go(i);
		if(tmp != 1) tmp--;
		lcm = lcm*tmp/gcd(lcm,tmp);
		if(lcm >= B) {
			cout << (A == 1);
			return 0;
		}
	}
	cout << (B+lcm-1)/lcm-(A+lcm-2)/lcm;
}