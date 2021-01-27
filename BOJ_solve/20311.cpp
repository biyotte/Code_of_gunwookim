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
const long long mod = 998244353;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n;
priority_queue <pi> q;
vec ans;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); 
	cin >> n >> n;
	for(int i = 1;i <= n;i++) {
		int x; cin >> x;
		q.push({x,i});
	}
	while((int)q.size() > 1) {
		pi x = q.top(); q.pop();
		pi y = q.top(); q.pop();
		ans.pb(x.y), ans.pb(y.y);
		if(--x.x) q.push(x);
		if(--y.x) q.push(y);
	}
	if(!q.empty()&&q.top().x > 1) cout << -1;
	else {
		if(!q.empty()) ans.pb(q.top().y);
		for(int i : ans) cout << i << ' ';
	}
}