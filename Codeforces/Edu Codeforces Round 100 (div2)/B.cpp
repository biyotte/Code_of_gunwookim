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
int n;
ll a[55];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while(T--) {
		cin >> n;
		ll sum = 0,odd = 0,even = 0;
		for(int i = 1;i <= n;i++) {
			cin >> a[i];
			sum += a[i];
			if(i % 2) odd += a[i];
			else even += a[i];
		}
		if(odd < even) {
			for(int i = 1;i <= n;i += 2) a[i] = 1;
		}
		else {
			for(int i = 2;i <= n;i += 2) a[i] = 1;
		}
		for(int i = 1;i <= n;i++) cout << a[i] << ' ';
		cout << '\n';
	}
}