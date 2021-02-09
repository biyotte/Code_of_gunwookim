#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define all(v) v.begin(),v.end()
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
using namespace std;
const long long INF = 1e9;
const int TMX = 1 << 18;
const long long llINF = 1e18;
const long long mod = 1e9+7;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,m,c[2005];
vecpi v[2005];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= m;i++) {
		int x,y,z; cin >> x >> y >> z;
		v[x].pb({y,z});
	}
	priority_queue <pi> q;
	for(int st = 1;st <= n;st++) {
		while(!q.empty()) q.pop();
		memset(c,0,sizeof(c));
		q.push({0,st});
		int fl = 0;
		while(!q.empty()) {
			int cost = -q.top().x, now = q.top().y; q.pop();
			if(now == st&&c[now]) {
				fl = 1;
				cout << cost << '\n';
				break;
			}
			if(c[now]) continue;
			c[now] = 1;
			for(pi i : v[now]) q.push({-cost-i.y,i.x});
		}
		if(!fl) cout << "-1\n";
	}
}
