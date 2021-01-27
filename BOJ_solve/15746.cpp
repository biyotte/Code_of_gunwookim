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
const int mod = 1e9+7;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,p[100005];
char s[100005];
vec v[100005];
ll a[100005],din[100005],dout[100005],sz[100005],tot;
//din[i] : i 부트리 안을 최소로 도는 
//dout[i] : i 부트리 밖을 최소로 도는

void dfs1(int x) {
	sz[x] = v[x].empty();
	for(int i : v[x]) {
		dfs1(i);
		sz[x] += sz[i];
		din[x] += din[i]+sz[i]*(a[i]+1);
	}
}

void dfs2(int x) {
	if(x != 1) dout[x] = dout[p[x]]+din[p[x]]-din[x]+3*(tot-sz[p[x]]+sz[p[x]]-sz[x])-(a[x]+1)*sz[x]; 
	for(int i : v[x]) dfs2(i);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) {
		int cn; cin >> s+1 >> cn;
		a[i] = strlen(s+1);
		if(!cn) tot++;
		while(cn--) {
			int x; cin >> x;
			v[i].pb(x);
			p[x] = i;
		}
	}
	dfs1(1), dfs2(1);
	ll mn = llINF;
	for(int i = 1;i <= n;i++) mn = min(mn,din[i]+dout[i]);
	cout << mn-tot;
}