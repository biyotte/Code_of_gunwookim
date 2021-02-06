#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define all(v) v.begin(),v.end()
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
using namespace std;
const long long INF = 2e9;
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
int n,k,go[1000005],ans[1000005],tmp[1000005];
ll m,a[1000005];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k >> m;
	for(int i = 1;i <= n;i++) cin >> a[i], ans[i] = i;
	int l = 1, r = k+1;
	for(int i = 1;i <= n;i++) {
		while(r < n&&a[i]-a[l] > a[r+1]-a[i]) l++, r++;
		if(a[i]-a[l] < a[r]-a[i]) go[i] = r;
		else go[i] = l;
	}
	while(m) {
		if(m & 1) for(int i = 1;i <= n;i++) ans[i] = go[ans[i]];
		for(int i = 1;i <= n;i++) tmp[i] = go[go[i]];
		for(int i = 1;i <= n;i++) go[i] = tmp[i];
		m /= 2;
	}
	for(int i = 1;i <= n;i++) cout << ans[i] << ' ';
}