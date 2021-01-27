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
int n,co,in[50005],out[50005],pos[50005];
int c[50005],color[50005],cnt[50005];
vecpi v[50005];

void update(int l,int r,int val) {cnt[l] += val, cnt[r+1] -= val;}

void dfs_numbering(int x,int pr) {
	in[x] = ++co;
	pos[co] = x;
	for(pi i : v[x]) {
		if(i.x != pr) dfs_numbering(i.x,x);
	}
	out[x] = co;
}

void dfs(int x,int pr) {
	for(pi i : v[x]) c[i.y]++;
	for(pi i : v[x]) {
		if(c[i.y] >= 2) {
			if(i.x != pr) update(in[i.x],out[i.x],1);
			else {
				update(1,n,1);
				update(in[x],out[x],-1);
			}
		}
	}
	for(pi i : v[x]) c[i.y] = 0;
	for(pi i : v[x]) {
		if(i.x != pr) dfs(i.x,x);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i < n;i++) {
		int x,y,z; cin >> x >> y >> z;
		v[x].pb({y,z}), v[y].pb({x,z});
	}
	dfs_numbering(1,-1);
	dfs(1,-1);
	vec ans;
	for(int i = 1;i <= n;i++) {
		cnt[i] += cnt[i-1];
		if(!cnt[i]) ans.pb(pos[i]);
	}
	sort(all(ans));
	cout << ans.size() << '\n';
	for(int i : ans) cout << i << '\n';
}