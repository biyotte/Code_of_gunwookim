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
//long long mod;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi; 
typedef long long ll;
ll A,B,lcm = 1;
ll a[105],ans;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> A >> B;
	a[2] = 1;
	for(ll i = 2;i <= 100;i++) {
		for(ll j = 2;j < i;j++) {
			if(i % j) {a[i] = a[j]+1; break;}
		}
		ll ch = 0, tmp = i,la;
		for(ll j = 2;j <= i;j++) {
			if(tmp % j) continue;
			ch++, la = j;
			while(tmp % j == 0) tmp /= j;
		}
		if(ch == 1) lcm *= la, la = lcm/la;
		else la = lcm;
		ans += (B/la-(A-1)/la)*(a[i]+1);
		if(lcm > B||lcm < 0) break;
		ans -= (B/lcm-(A-1)/lcm)*(a[i]+1);
	}
	cout << ans;
}