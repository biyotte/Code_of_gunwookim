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
const int mod = 998244353;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n;
int a[205],c[205],d[205];

void nope() {
	cout << "No";
	exit(0);
}

bool isok(int l,int r) {
	int mid = (l + r) >> 1;
	for(int i = l;i <= mid;i++) {
		if(c[i] == 2) return false;
	}
	for(int i = mid+1;i <= r;i++) {
		if(c[i] == 1) return false;
		if(c[i] == 2&&c[i-(r-mid)] == 1&&!a[i]) return false;
	}
	for(int i = l;i <= r;i++) {
		if(a[i]&&r-mid != a[i]) return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) {
		int x,y; cin >> x >> y;
		if(x != -1) {
			if(c[x]) nope();
			c[x] = 1;
		}
		if(y != -1) {
			if(c[y]) nope();
			c[y] = 2;
		}
		if(x != -1&&y != -1) {
			if(y < x) nope();
			a[x] = y-x;
			a[y] = y-x;
		}
	}
	d[0] = 1;
	for(int i = 2;i <= 2*n;i += 2) {
		for(int j = 0;j < i;j += 2) {
			if(d[j]) {
				if(isok(j+1,i)) {
					d[i] = true;
					break;
				}
			}
		}
	}
	cout << (d[2*n] ? "Yes" : "No");
}