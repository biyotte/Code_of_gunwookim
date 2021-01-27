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
ll d[105][105][105];
int a[105],n;

ll go(int l,int r,int mn) {
	if(l > r) return 1; if(!mn) return 0;
	if(d[l][r][mn] != -1) return d[l][r][mn];
	d[l][r][mn] = 0;
	for(int i = l;i <= r;i++) {
		d[l][r][mn] = (d[l][r][mn]+go(l,i-1,min(mn,a[i]))*go(i+1,r,min(mn,a[i])-1))%mod;
	}
	return d[l][r][mn];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i], a[i] = min(n,a[i]);
	memset(d,-1,sizeof(d));
	cout << go(1,n,n);
}