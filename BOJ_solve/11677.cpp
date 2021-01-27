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
const long long mod = 1e18;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,m,A,B,c[5005],ind[5005],cnt[5005];
vec v[5005],rv[5005];

int dfs(int x) {
	if(c[x]) return 0;
	c[x] = 1;
	int ret = 1;
	for(int i : rv[x]) ret += dfs(i);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> A >> B >> n >> m;
	for(int i = 1;i <= m;i++) {
		int x,y; cin >> x >> y;
		x++, y++; ind[y]++;
		v[x].pb(y), rv[y].pb(x);
	}
	int ansA = 0,ansB = 0,ansnot = 0;
	for(int i = 1;i <= n;i++) {
		queue <int> q;
		memset(c,0,sizeof(c));
		memset(cnt,0,sizeof(cnt));
		for(int j = 1;j <= n;j++) if(!ind[j]) q.push(j);
		int reachA = 0,reachB = 0;
		for(int go = 1;go <= B;go++) {
			if(q.empty()) {
				if(go <= A) reachA = 1;
				reachB = 1;
				break;
			}
			int x = q.front(); q.pop();
			if(x == i) {go--; continue;}
			for(int j : v[x]) {
				if(++cnt[j] == ind[j]) q.push(j);
			}
		}
		int need = dfs(i);
		if(need <= A&&reachA) ansA++;
		if(need <= B&&reachB) ansB++;
		if(need > B) ansnot++;
	}
	cout << ansA << '\n' << ansB << '\n' << ansnot;
}