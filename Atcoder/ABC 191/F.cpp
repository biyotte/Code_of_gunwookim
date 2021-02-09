#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define all(v) v.begin(),v.end()
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
using namespace std;
const long long INF = 1e9;
const int TMX = 1 << 18;
const long long llINF = 1e18;
const long long mod = 1e9+7;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n;
int a[2005];
vec v;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	v.pb(a[1]);
	for(int i = 1;i <= n;i++) {
		for(int j = i+1;j <= n;j++) {
			int tmp = __gcd(a[i],a[j]);
			if(tmp <= a[1]) v.pb(tmp);
		}
	}
	sort(all(v)), v.erase(unique(all(v)),v.end());
	cout << v.size();
}
