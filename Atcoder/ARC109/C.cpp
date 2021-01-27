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
int a[205];
int n,k;

int f(int x,int y) {
	if(x == y) return x;
	if(x > y) swap(x,y);
	if(x == 0&&y == 2) return 2;
	return x;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	cin >> n >> k;
	for(int i = 1;i <= n;i++) {
		char x; cin >> x;
		if(x == 'R') a[i] = 0;
		if(x == 'S') a[i] = 1;
		if(x == 'P') a[i] = 2;
		a[n+i] = a[i];
	}
	for(int i = 1;i <= k;i++) {
		for(int j = 1;j <= n;j++) a[j] = f(a[j*2-1],a[j*2]);
		for(int j = 1;j <= n;j++) a[n+j] = a[j];
	}
	cout << (!a[1] ? 'R' : (a[1] & 1 ? 'S' : 'P'));
}
