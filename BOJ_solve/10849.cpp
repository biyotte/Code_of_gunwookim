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
int n,P,m,T,taxi;
int c[20005],wi[20005];
int p[20],dist[20][20];
ll d[1<<16][17],d2[1<<16][17][2];
vecpi v[20005];

ll dfs(int bit,int la) {
	if(d[bit][la] != -1) return d[bit][la];
	if(bit == (1 << P)-1) return dist[la][1];
	d[bit][la] = llINF;
	for(int i = 1;i <= P;i++) {
		if(bit & (1 << (i-1))) continue;
		d[bit][la] = min(d[bit][la],dfs(bit|(1 << (i-1)),i)+dist[la][i]);
	}
	return d[bit][la];
}

ll dfs2(int bit,int la,int used) {
	if(d2[bit][la][used] != -1) return d2[bit][la][used];
	if(bit == (1 << P)-1) return (used ? dist[la][1] : min(dist[la][1],taxi));
	d2[bit][la][used] = llINF;
	for(int i = 1;i <= P;i++) {
		if(bit & (1 << (i-1))) continue;
		d2[bit][la][used] = min(d2[bit][la][used],dfs2(bit|(1 << (i-1)),i,used)+dist[la][i]);
		if(!used) d2[bit][la][used] = min(d2[bit][la][used],dfs2(bit|(1 << (i-1)),i,1)+taxi);
	}
	return d2[bit][la][used];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> P >> m >> T >> taxi;
	p[1] = 1, wi[1] = 1, P++;
	for(int i = 2;i <= P;i++) {
		int x; cin >> p[i] >> x;
		p[i]++;
		T -= x;
		wi[p[i]] = i;
	}
	for(int i = 1;i <= m;i++) {
		int x,y,w; cin >> x >> y >> w;
		x++, y++;
		v[x].pb({y,w}), v[y].pb({x,w});
	}
	for(int st = 1;st <= P;st++) {
		priority_queue <pi> q;
		memset(c,0,sizeof(c));
		q.push({0,p[st]});
		while(!q.empty()) {
			auto now = q.top(); q.pop();
			if(c[now.y]) continue;
			c[now.y] = 1;
			if(wi[now.y]) {
				dist[st][wi[now.y]] = -now.x;
				if(p[wi[now.y]] == p[1]) dist[st][1] = -now.x; 
			}
			for(pi i : v[now.y]) q.push({now.x-i.y,i.x});
		}
	}
	memset(d,-1,sizeof(d));
	memset(d2,-1,sizeof(d2));
	if(dfs(1,1) <= T) cout << "possible without taxi";
	else if(dfs2(1,1,0) <= T) cout << "possible with taxi";
	else cout << "impossible";
}