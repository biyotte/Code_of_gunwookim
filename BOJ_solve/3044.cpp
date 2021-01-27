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
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,m,cango[10005];
int c[10005],ind[10005];
int d[10005],num[10005];
vec v[10005],rv[10005];
void Cango(int x) {
	if(cango[x]) return;
	cango[x] = 1;
	if(x == 2) return;
	for(int i : v[x]) Cango(i);
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1;i <= m;i++) {
		int x,y; scanf("%d %d", &x, &y);
		ind[y]++, v[x].pb(y), rv[y].pb(x);
	}
	Cango(1);
	if(!cango[2]) {
		cout << 0;
		return 0;
	}
	for(int i = 1;i <= n;i++) {
		for(int j : rv[i]) if(!cango[j]) ind[i]--;
	}
	queue <int> q;
	q.push(1), d[1] = 1;
	while(!q.empty()) {
		int x = q.front(); q.pop();
		if(c[x]) continue;
		c[x] = 1;
		for(int i : v[x]) {
			if(d[i]+d[x] >= 1000000000) num[i] = 1;
			d[i] = (d[i]+d[x])%1000000000;
			num[i] |= num[x];
			if(!--ind[i]) q.push(i);
		}
	}
	if(!c[2]) {
		cout << "inf";
		return 0;
	}
	if(num[2]) printf("%09d",d[2]);
	else printf("%d",d[2]);
}