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
int n,m,k,p,start,ans;
int cost1[100005],costn[100005];
// cost1[i] = cost(i,1), costn[i] = cost(i,n)

vector <int> le[100005],ri[100005];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> k >> p;
	for(int i = 1;i <= k;i++) {
		int x,y,op; cin >> x >> y >> op;
		if(op) le[x+1].pb(m-y);
		else ri[x].pb(m-y);
	}
	for(int i = 1;i <= n;i++) {
		sort(all(le[i])), reverse(all(le[i]));
		sort(all(ri[i])), reverse(all(ri[i]));
	}
	vec lis;
	for(int i = 1;i <= n;i++) {
		for(int j : le[i]) {
			if(lis.empty()||lis.back() <= j) lis.pb(j);
			else {
				int it = upper_bound(all(lis),j)-lis.begin();
				lis[it] = j;
			}
		}
		cost1[i] = i-1-(int)lis.size();
	}
	lis.clear();
	for(int i = n;i >= 1;i--) {
		for(int j : ri[i]) {
			if(lis.empty()||lis.back() <= j) lis.pb(j);
			else {
				int it = upper_bound(all(lis),j)-lis.begin();
				lis[it] = j;
			}
		}
		costn[i] = n-i-(int)lis.size();
	}
	for(int i = 1;i <= n;i++) start += !(cost1[i]+costn[i]);
	for(int l = 1,r = 1;l <= n;l++) {
		r = max(r,l);
		while(r <= n&&cost1[r]+costn[l] <= p) r++;
		ans = max(ans,r-l);
	}
	cout << ans-start;
}