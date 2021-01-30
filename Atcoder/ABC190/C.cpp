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
int n,m,k,is[105];
int a[105],b[105];
int c[105],d[105];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); 
	cin >> n >> m;
	for(int i = 1;i <= m;i++) cin >> a[i] >> b[i];
	cin >> k;
	for(int i = 1;i <= k;i++) {
		cin >> c[i] >> d[i];
	}
	int ans = 0;
	for(int i = 0;i < (1 << k);i++) {
		for(int j = 1;j <= n;j++) is[j] = 0;
		for(int j = 1;j <= k;j++) {
			if(i&(1 << (j-1))) is[c[j]] = 1;
			else is[d[j]] = 1;
		}
		int cnt = 0;
		for(int j = 1;j <= m;j++) {
			if(is[a[j]]&&is[b[j]]) cnt++;
		}
		ans = max(ans,cnt);
	}
	cout << ans;
}