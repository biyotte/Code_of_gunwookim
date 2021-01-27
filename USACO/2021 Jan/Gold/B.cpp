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
const long long llINF = 1e16;
const long long mod = 1e9+7;
const long long hashmod = 100003;
const int MAXN = 100000;
const int MAXM = 1000000;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
char is[51][51];
int n,k,co[50005],c[50005],dist[50005];
vec v[50005];
vec wi[55];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	for(int i = 1;i <= n;i++) cin >> co[i], wi[co[i]].pb(i);
	for(int i = 1;i <= k;i++) cin >> is[i]+1;
	for(int co1 = 1;co1 <= k;co1++) {
		for(int co2 = 1;co2 <= k;co2++) {
			int lp = 0, rp = 0;
			while(lp < wi[co1].size()&&rp < wi[co2].size()) {
				if(wi[co1][lp] < wi[co2][rp]) v[wi[co1][lp++]].pb(wi[co2][rp]);
				else v[wi[co1][lp]].pb(wi[co2][rp++]);
			}
		}
	}
	priority_queue <pi> q;
	memset(dist,-1,sizeof(dist));
	c[1] = 1, dist[1] = 0;
	for(int i = 1;i <= n;i++) {
		if(is[co[1]][co[i]]-'0') q.push({1-i,i});
	}
	while(!q.empty()) {
		int cost = -q.top().x, x = q.top().y; q.pop();
		if(c[x]) continue;
		c[x] = 1, dist[x] = cost;
		for(int i : v[x]) if(co[x] == co[i]||is[co[x]][co[i]]-'0') q.push({-cost-abs(x-i),i});
	}
	cout << dist[n];
}
