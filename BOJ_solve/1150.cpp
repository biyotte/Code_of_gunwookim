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
int n,k,used[100005];
int l[100005],r[100005];
int h[100005],d[100005];
priority_queue <pi> q;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); 
	cin >> n >> k;
	for(int i = 1;i <= n;i++) cin >> h[i];
	for(int i = 1;i < n;i++) {
		d[i] = h[i+1]-h[i];
		l[i] = i-1, r[i] = i+1;
		q.push({-d[i],i});
	}
	d[0] = d[n] = INF;
	r[0] = 1, l[n] = n-1; 
	q.push({-INF,0}), q.push({-INF,n});
	int ans = 0;
	while(k--) {
		auto X = q.top(); q.pop();
		if(used[X.y]) {k++; continue;}
		ans -= X.x;
		int x = X.y;
		d[x] = d[l[x]]+d[r[x]]-d[x];
		used[r[x]] = used[l[x]] = 1;
		l[x] = l[l[x]], r[x] = r[r[x]];
		l[r[x]] = x, r[l[x]] = x;
		q.push({-d[x],x});
	}
	cout << ans;
}