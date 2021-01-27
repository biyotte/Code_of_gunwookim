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
const long long llINF = 5e18;
long long mod;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi; 
typedef long long ll;
int n,m;
int T,a[105],b[105],c[105],d[105];

int isok(int x) {
	ll a1 = 0,a2 = 0;
	int c1 = 0,c2 = 0;
	for(int i = 1;i <= n;i++) {
		if(x >= a[i]) a1 += (x-a[i])/b[i]+1;
		if((x-a[i]) % b[i] == 0) c1++;
	}
	for(int i = 1;i <= m;i++) {
		if(T >= c[i]+x) a2 += (T-c[i]-x)/d[i]+1;
		if((T-c[i]-x) % d[i] == 0) c2++;
	}
	//cout << x << " : " << a1 << ' ' << a2 << '\n';
	if(a1-c1+1 > a2) return 1;
	if(a1 < a2) return -1;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> T >> n;
	for(int i = 1;i <= n;i++) cin >> a[i] >> b[i];
	cin >> m;
	for(int i = 1;i <= m;i++) cin >> c[i] >> d[i];
	int l = 0, r = T;
	while(l < r) {
		int mid = (l + r) >> 1;
		if(isok(mid) == -1) l = mid+1;
		else r = mid;
	}
	if(isok(l) == 1) l--;
	cout << l;
}