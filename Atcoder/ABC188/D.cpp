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
const long long mod = 1e9+7;
const long long hashmod = 100003;
const int MAXN = 100000;
const int MAXM = 1000000;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,la;
ll C;
map <int,ll> M;

struct L {
	int l,r; ll val;
}a[200005];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> C;
	for(int i = 1;i <= n;i++) {
		cin >> a[i].l >> a[i].r >> a[i].val;
		M[a[i].l] += a[i].val;
		M[a[i].r+1] -= a[i].val;
	}
	ll ans = 0,sum = 0;
	for(auto i : M) {
		ans += 1LL*min(C,sum)*(i.x-la);
		la = i.x;
		sum += i.y;
	}
	cout << ans;
}