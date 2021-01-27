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
typedef pair <int,int> pl;
typedef pair <ll,ll> pi;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,m,Q,st,p[300005],d[2][300005];
vec v[300005],tv[150005];

void dfs(int wi,int x,int dist) {
	if(d[wi][x] != -1) {
		d[wi][x] = dist; return;
	}
	d[wi][x] = dist;
	for(int i : v[x]) dfs(wi,i,dist+1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> st; st++;
	for(int i = 1;i <= m;i++) {
		int x,y; cin >> x >> y;
		x++, y++;
		tv[x].pb(y), tv[y].pb(x);
	}
	for(int i = 1;i <= n;i++) {
		//i+n : 가장 아름다운 길로 들어온 정점 (두번째로 아름다운 길로 나가야 함)
		//i : 가장 아름다운 길로 들어오지 않은 정점 (가장 아름다운 길로 나가야 함)
		if(tv[i].size() > 1) {
			if(tv[tv[i][1]][0] == i) p[i+n] = tv[i][1]+n; // 받는 입장이 아름다운 길인 경우
			else p[i+n] = tv[i][1]; // 받는 입장이 아름답지 않은 경우
		}
		else {
			if(tv[tv[i][0]][0] == i) p[i+n] = tv[i][0]+n; // 받는 입장이 아름다운 길인 경우
			else p[i+n] = tv[i][0]; // 받는 입장이 아름답지 않은 경우
		}
		if(tv[tv[i][0]][0] == i) p[i] = tv[i][0]+n; // 받는 입장이 아름다운 길인 경우
		else p[i] = tv[i][0]; // 받는 입장이 아름답지 않은 경우
		v[p[i]].pb(i), v[p[i+n]].pb(i+n);
		d[0][i] = d[0][i+n] = d[1][i] = d[1][i+n] = -1;
	}
	dfs(0,st,0), dfs(1,st+n,0);
	cin >> Q;

	while(Q--) {
		int k,cnt = 0; cin >> k;
		for(int i = 1;i <= n;i++) {
			if(d[0][i] < k&&d[0][i] > 0&&d[0][st] > 0&&d[0][i] % d[0][st] == k % d[0][st]) {cnt++; continue;}
			if(d[1][i] < k&&d[1][i] > 0&&d[1][st+n] > 0&&d[1][i] % d[1][st+n] == k % d[1][st+n]) {cnt++; continue;}
			if(k == d[0][i]||k == d[1][i]) {cnt++; continue;}
		}
		cout << cnt << '\n';
	}
}