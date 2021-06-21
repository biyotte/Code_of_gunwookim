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
const long long llINF = 1e16;
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
ll a[2005],sum[2005];
ll d[2005][2005];

ll len(int x,int y) {
	return sum[y]-sum[x-1]+y-x;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> m >> n;
	for(int i = 1;i <= n;i++) cin >> a[i], sum[i] = sum[i-1]+a[i];
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) d[i][j] = llINF;
	}
	for(int j = 1;j <= n;j++) {
		ll mn = llINF;
		for(int i = j,k = j-1;i <= n;i++) {
			if(len(j,i) > m) break;
			while(k&&len(k,j-1) <= len(j,i)) {
				mn = min(mn,d[j-1][k]-len(k,j-1));
				k--;
			}
			d[i][j] = (mn == llINF? llINF : mn+len(j,i));
		}
		mn = llINF;
		for(int i = n,k = 1;i >= j;i--) {
			if(len(j,i) > m) continue;
			while(k < j&&len(k,j-1) >= len(j,i)) {
				if(len(k,j-1) > m) {k++; continue;}
				mn = min(mn,d[j-1][k]+len(k,j-1));  
				k++;
			}
			d[i][j] = min(d[i][j],(mn == llINF? llINF : mn-len(j,i)));
		}
		for(int i = j;i <= n;i++) {
			if(d[i][j] == llINF) d[i][j] = 0;
		}
	}
	ll ans = llINF;
	for(int i = 1;i <= n;i++) {
		if(len(i,n) <= m) ans = min(ans,d[n][i]);
	}
	cout << ans;
}