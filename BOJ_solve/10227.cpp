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
int n,m,L,R;
int sum[3005][3005],a[3005][3005];

bool isok(int x) {
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= m;j++) {
			sum[i][j] = sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]+(a[i][j] <= x ? -1 : 1);
		}
	}
	for(int i = L;i <= n;i++) {
		for(int j = R;j <= m;j++) {
			if(sum[i][j]-sum[i-L][j]-sum[i][j-R]+sum[i-L][j-R] <= -1) return true;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); 
	cin >> n >> m >> L >> R;
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= m;j++) cin >> a[i][j];
	}
	int l = 1, r = n*m;
	while(l < r) {
		int mid = (l + r) >> 1;
		if(isok(mid)) r = mid;
		else l = mid+1;
	}
	cout << l;
}
