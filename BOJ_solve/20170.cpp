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
int a[6],b[6],n1,n2 = 36;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	for(int i = 0;i < 6;i++) cin >> a[i];
	for(int i = 0;i < 6;i++) cin >> b[i];
	for(int i = 0;i < 6;i++) {
		for(int j = 0;j < 6;j++) {
			if(a[i] > b[j]) n1++;
		}
	}
	int g = __gcd(n1,n2);
	n1 /= g, n2 /= g;
	cout << n1 << '/' << n2;
}
