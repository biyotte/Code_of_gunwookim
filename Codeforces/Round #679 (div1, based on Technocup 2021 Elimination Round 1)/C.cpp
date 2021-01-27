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
long long mod;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
ll a,b,c,d;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	//int T = 1;
	while(T--) {
		cin >> a >> b >> c >> d;
		if(a > b*c) {
			cout << "-1\n";
			continue;
		}
		ll wi = a/b;
		wi /= d;
		ll cnt = wi+1;
		ll g = cnt*(cnt-1)/2;
		cout << cnt*a-g*b*d << '\n';
	}
}