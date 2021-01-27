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
long long mod = 998244353;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef vector <int> vec;
typedef vector <pi> vecpi; 
typedef long long ll;
int n,p[200005],ind[200005],c[200005];
vec v[200005];
ll a[200005],b[200005],su[200005];

bool isok(ll mid) {
	queue <pair<int,ll>> q;
	for(int i = 1;i <= n;i++) {
		b[i] = a[i];
		if(!ind[i]) {
			q.push({i,mid-a[i]});
			if(a[i] > mid) return false;
		}
	}
	memset(su,0,sizeof(su));
	memset(c,0,sizeof(c));
	while(!q.empty()) {
		auto x = q.front(); q.pop();
		if(x.x == 1) break;
		int nx = p[x.x];
		ll tmp = min(x.y,b[nx]);
		x.y -= tmp, b[nx] -= tmp;
		su[nx] += x.y;
		if(su[nx] >= llINF) return true;
		if(++c[nx] == ind[nx]) {
			if(b[nx] > 0) return false;
			q.push({nx,su[nx]});
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	//int T; cin >> T;
	int T = 1;
	while(T--) {
		cin >> n;
		for(int i = 2;i <= n;i++) {
			cin >> p[i];
			v[p[i]].pb(i);
			ind[p[i]]++;
		}
		for(int i = 1;i <= n;i++) cin >> a[i];
		ll l = 0,r = llINF;
		while(l < r) {
			ll mid = (l + r) >> 1;
			if(isok(mid)) r = mid;
			else l = mid+1;
		}
		cout << l;
	}
}