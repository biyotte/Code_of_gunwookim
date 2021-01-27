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
const long long mod = 1e9+7;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int k,T;
int cnt[105];

bool cmp(pi x,pi y) {
	return (x.x-T)*x.y < (y.x-T)*y.y;
}

int dfs(int go,int ans,vecpi a) {
	if(a.empty()) return ans;
	if(go == k) return INF;
	int ret = INF;
	sort(all(a));
	int n = a.size(), t = a[0].x; T = t;
	sort(all(a),cmp);
	vecpi nx;
	for(int i = n-1;i >= 0;i--) {
		ret = min(ret,dfs(go+1,ans+(a[i].x-t)*a[i].y,nx)+30);
		nx.pb(a[i]);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n >> k;
	memset(cnt,-1,sizeof(cnt));
	vecpi a;
	for(int i = 1;i <= n;i++) {
		int x,y; cin >> x >> y;
		cnt[x] = max(cnt[x],y);
	}
	for(int i = 1;i <= 100;i++) if(cnt[i] != -1) a.pb({i,cnt[i]});
	cout << dfs(0,0,a);
} 
