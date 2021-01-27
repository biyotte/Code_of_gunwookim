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
ll n,k;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int T; cin >> T;
	//int T = 1;
	while(T--) {
		cin >> n >> k;
		ll x,y,g;
		for(g = 1;g*g+g*g <= n*n/(k*k);g++);
		g--; x = y = g;
		for(;x*x+y*y <= n*n/(k*k);y++);
		y--;
		if((x+y) % 2 == 0) cout << "Utkarsh\n";
		else cout << "Ashish\n"; 
	}
}
