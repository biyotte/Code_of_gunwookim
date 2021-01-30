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
int n,m,k,wi[20],wh[100005];
int dist[20][20],c[100005];
int d[1 << 17][17];
queue <pi> q;
vec v[100005];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); 
	cin >> n >> m;
	for(int i = 1;i <= m;i++) {
		int x,y; cin >> x >> y;
		v[x].pb(y), v[y].pb(x);
	}
	cin >> k;
	for(int i = 1;i <= k;i++) cin >> wi[i], wh[wi[i]] = i;
	for(int i = 1;i <= k;i++) for(int j = 1;j <= k;j++) dist[i][j] = INF;
	for(int st = 1;st <= k;st++) {
		memset(c,0,sizeof(c));
		q.push({wi[st],0});
		while(!q.empty()) {
			int x = q.front().x, y = q.front().y; q.pop();
			if(c[x]) continue; c[x] = 1;
			if(wh[x]) dist[st][wh[x]] = y;
			for(int i : v[x]) q.push({i,y+1});
		}
	}
	for(int i = 0;i < (1 << k);i++) for(int j = 1;j <= k;j++) d[i][j] = INF;
	for(int st = 1;st <= k;st++) {
		d[1 << (st-1)][st] = 1;
	}
	for(int i = 0;i < (1 << k);i++) {
		for(int j = 1;j <= k;j++) {
			if(i & (1 << (j-1))) {
				for(int l = 1;l <= k;l++) {
					if((i & (1 << (l-1)))&&j^l) {
						d[i][j] = min(d[i][j],d[i-(1 << (j-1))][l]+dist[l][j]);
					}
				}
			}
		}
	}
	int ans = INF;
	for(int i = 1;i <= k;i++) ans = min(ans,d[(1 << k)-1][i]);
	if(ans >= INF) ans = -1;
	cout << ans;
}