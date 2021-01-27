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
int n,st,ans,d[100005],c[100005];
vec v[100005];
queue <pi> q;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);   
	cin >> n >> st;
	for(int i = 1;i < n;i++) {
		int x,y; cin >> x >> y;
		v[x].pb(y), v[y].pb(x);
	}
	memset(d,-1,sizeof(d));
	for(int i = 1;i <= n;i++) {
		if(v[i].size() == 1) q.push({0,i});
	}
	while(!q.empty()) {
		auto now = q.front(); q.pop();
		if(d[now.y] != -1) continue;
		d[now.y] = now.x;
		for(int i : v[now.y]) q.push({now.x+1,i});
	}
	q.push({0,st});
	while(!q.empty()) {
		auto now = q.front(); q.pop();
		if(c[now.y]) continue; c[now.y] = 1;
		if(d[now.y] <= now.x) {ans++; continue;}
		for(int i : v[now.y]) q.push({now.x+1,i});
	}
	cout << ans;
}