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
const long long mod = 998244353;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,k,a[100005],t[100005];

void update(int x) {for(;x <= n;x += x&-x) t[x]++;}
int query(int x) {int ret = 0; for(;x;x -= x&-x) ret += t[x]; return ret;}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n, a[n+1] = INF;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = n;i >= 1;i--) {
		if(a[i] > a[i+1]) {k = i; break;}
	}
	for(int i = k+1;i <= n;i++) update(a[i]);
	cout << k << '\n';
	for(int i = 1;i <= k;i++) {
		cout << k-i+query(a[i]) << ' ';
		update(a[i]);
	}
}