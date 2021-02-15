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
int n,k,used[200005];
int l[200005],r[200005];
ll h[200005],d[200005];
priority_queue <pl> q;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); 
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> h[i];
	for(int i = 1;i <= n;i++) {
		d[i] = h[i];
		l[i] = i-1, r[i] = i+1;
		q.push({d[i],i});
	}
	d[0] = d[n+1] = -llINF;
	r[0] = 1, l[n+1] = n; 
	q.push({-llINF,0}), q.push({-llINF,n+1});
	ll ans = 0; k = (n+1)/2;
	while(k--) {
		auto X = q.top(); q.pop();
		if(used[X.y]) {k++; continue;}
		ans += X.x;
		ll x = X.y;
		d[x] = d[l[x]]+d[r[x]]-d[x];
		used[r[x]] = used[l[x]] = 1;
		l[x] = l[l[x]], r[x] = r[r[x]];
		l[r[x]] = x, r[l[x]] = x;
		q.push({d[x],x});
		cout << ans << '\n';
	}
}