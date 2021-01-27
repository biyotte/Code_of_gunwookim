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
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,m;
int a[200005];
int sz[200005];
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); 
	cin >> n >> m;
	for(int i = 1;i <= m;i++) cin >> a[i];
	sort(a+1,a+m+1);
	a[0] = 0;
	a[m+1] = n+1;
	int g = 0;
	for(int i = 1;i <= m+1;i++) {
		if(a[i-1]+1 != a[i]) sz[++g] = a[i]-a[i-1]-1;	
	}
	int mn = INF;
	for(int i = 1;i <= g;i++) {
		mn = min(mn,sz[i]);
	}
	int ans = 0;
	for(int i = 1;i <= g;i++) {
		ans += sz[i]/mn+(sz[i]%mn > 0);
	}
	cout << ans;
}