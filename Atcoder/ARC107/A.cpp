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
int n,k;
int a[55][55],cx[55][55],cy[55][55],ch[55];
ll cntx,cnty,fact[55];

int dfsx(int x) {
	if(ch[x]) return 0;
	ch[x] = 1;
	int sz = 1;
	for(int i = 1;i <= n;i++) {
		if(cx[x][i] == n||cx[i][x] == n) sz += dfsx(i);
	}
	return sz;
}

int dfsy(int x) {
	if(ch[x]) return 0;
	ch[x] = 1;
	int sz = 1;
	for(int i = 1;i <= n;i++) {
		if(cy[x][i] == n||cy[i][x] == n) sz += dfsy(i);
	}
	return sz;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) cin >> a[i][j];
	}
	fact[0] = 1;
	for(int i = 1;i <= n;i++) fact[i] = fact[i-1]*i%mod;
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) {
			for(int l = j+1;l <= n;l++) if(a[i][j]+a[i][l] <= k) cx[j][l]++;
		}
	}
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) {
			for(int l = j+1;l <= n;l++) if(a[j][i]+a[l][i] <= k) cy[j][l]++;
		}
	}
	ll ans = 1;
	for(int i = 1;i <= n;i++) {
		int co = dfsx(i);
		ans = ans*fact[co]%mod;
	}
	memset(ch,0,sizeof(ch));
	for(int i = 1;i <= n;i++) {
		int co = dfsy(i);
		ans = ans*fact[co]%mod;
	}
	cout << ans;
}