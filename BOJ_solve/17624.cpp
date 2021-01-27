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
int n,B,isblack[5005],cnt[5005];
int dmin[5005][5005],dmax[5005][5005],tmax[5005],tmin[5005];
int amin[5005],amax[5005];
vec v[5005];

void dfs(int x,int pr) {
	//cnt[x] = isblack[x];
	for(int nx : v[x]) {
		if(nx == pr) continue;
		dfs(nx,x);
		memset(tmax,0,sizeof(tmax));
		memset(tmin,0x3f,sizeof(tmin));
		for(int i = 0,j;i <= cnt[nx];i++) {
			for(j = 0;j <= cnt[x];j++) {
				tmin[i+j] = min(tmin[i+j],dmin[nx][i]+dmin[x][j]);
				tmax[i+j] = max(tmax[i+j],dmax[nx][i]+dmax[x][j]);
			}
		}
		cnt[x] += cnt[nx];
		for(int i = 0;i <= cnt[x];i++) {
			dmin[x][i] = tmin[i], dmax[x][i] = tmax[i];
		}
	}
	for(int i = 0;i <= cnt[x];i++) {
		dmin[x][i]++, dmax[x][i]++;
	}
	if(isblack[x]) {
		cnt[x]++;
		for(int i = cnt[x];i;i--) {
			dmin[x][i] = dmin[x][i-1];
			dmax[x][i] = dmax[x][i-1];
		}
	}
	if(isblack[x]) dmax[x][0] = 0;
	dmin[x][0] = 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); 
	cin >> n >> B;
	for(int i = 1;i <= B;i++) {
		int x; cin >> x;
		isblack[x] = 1;
	}
	for(int i = 1;i < n;i++) {
		int x,y; cin >> x >> y;
		v[x].pb(y), v[y].pb(x);
	}
	memset(dmin,0x3f,sizeof(dmin));
	for(int i = 1;i <= n;i++) dmin[i][0] = 0;
	dfs(1,-1);
	for(int i = 0;i <= B;i++) {
		amin[i] = INF, amax[i] = -INF;
	}
	for(int i = 1;i <= n;i++) {
		for(int j = 0;j <= cnt[i];j++) {
			amin[j] = min(amin[j],dmin[i][j]);
			amax[j] = max(amax[j],dmax[i][j]);
		}
	}
	int Q,ans = 0;
	cin >> Q;
	while(Q--) {
		int x,y; cin >> x >> y;
		if(amin[y] <= x&&x <= amax[y]) ans++;
	}
	cout << ans;
}
