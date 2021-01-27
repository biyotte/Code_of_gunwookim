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
const int mod = 998244353;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,m,st,en,a[1000005];
int ans[1000005];
priority_queue <pi> q;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> st >> en;
	for(int i = 1;i <= n;i++) cin >> a[i], m += a[i];
	if(n == 1) {
		if(a[1] != 1) cout << 0;
		else cout << 1;
		return 0;
	}
	a[n+1] = a[en]; a[n+1]--;
	ans[1] = st, ans[m] = en;
	if(st == en) st = n+1;
	a[st]--;
	if(a[n+1] < 0) {
		cout << 0;
		return 0;
	}
	for(int i = 1;i <= n;i++) {
		if(!a[i]) continue;
		if(i == en) q.push({a[n+1],n+1});
		else q.push({a[i],i});
	}
	int la = st;
	for(int g = 2;g <= m-1;g++) {
		pi x = q.top(); q.pop();
		if(x.y == la) {
			if(q.empty()) {
				cout << 0;
				return 0;
			}
			pi y = q.top(); q.pop();
			if(y.y == n+1) ans[g] = en;
			else ans[g] = y.y;
			if(y.x > 1) q.push({y.x-1,y.y});
			q.push(x);
			la = y.y;
		}
		else {
			if(x.x > 1) q.push({x.x-1,x.y});
			if(x.y == n+1) ans[g] = en;
			else ans[g] = x.y;
			la = x.y;
		}
	}
	int ch = 0;
	if(ans[m] == ans[m-1]) {
		for(int i = 2;i <= m-2;i++) {
			if(ans[m-1] != ans[i-1]&&ans[m-1] != ans[i+1]&&ans[i] != ans[m]) {
				ch = 1;
				swap(ans[i],ans[m-1]);
				break;
			}
		}
	}
	if(ans[m] == ans[m-1]) {
		cout << 0;
		return 0;
	}
	for(int i = 1;i <= m;i++) cout << ans[i] << ' ';
} 
