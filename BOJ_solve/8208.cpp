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
int n,ans,sum[1000005];
char a[1000005];
vec v[26];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> a+1;
	for(int i = 1;i <= n;i++) v[a[i]-'a'].pb(i);
	for(int i = 0;i < 26;i++) v[i].pb(n);
	for(int mxi = 0;mxi < 26;mxi++) {
		for(int i = 1;i <= n;i++) sum[i] = sum[i-1]+(a[i] == 'a'+mxi);
		for(int mni = 0;mni < 26;mni++) {
			if(mxi == mni) continue;
			int mn = 0;
			for(int i = 1;i < v[mni].size();i++) {
				ans = max(ans,sum[v[mni][i]]-i-mn);
				mn = min(mn,sum[v[mni][i-1]]-i);
			}
		}
	}
	cout << ans;
}
