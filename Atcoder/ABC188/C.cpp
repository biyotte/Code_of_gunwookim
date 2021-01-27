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
int n,m;
int a[70000];

pi Win(int l,int r) {
	if(l+1 == r) {
		if(a[l] < a[r]) return {r,l};
		return {l,r};
	}
	int mid = (l + r) >> 1;
	pi L = Win(l,mid), R = Win(mid+1,r);
	pi ret;
	if(a[L.x] > a[R.x]) {
		ret.x = L.x;
		ret.y = R.x;
	}
	else {
		ret.x = R.x;
		ret.y = L.x;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	m = (1 << n);
	for(int i = 1;i <= m;i++) cin >> a[i];
	cout << Win(1,m).y;
}