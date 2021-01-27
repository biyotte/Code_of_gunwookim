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
int n,m,cs1,ce1,cnam;
int c[40005];
int ds1[40005],de1[40005],nam[40005];
vec v[40005];
pi edge[1000005];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= m;i++) {
		int x,y; cin >> x >> y;
		edge[i] = {x,y};
		v[x].pb(y), v[y].pb(x);
	}
	queue <int> q;
	memset(ds1,-1,sizeof(ds1));
	memset(de1,-1,sizeof(de1));
	ds1[1] = 0, q.push(1);
	while(!q.empty()) {
		int x = q.front(); q.pop();
		for(int i : v[x]) {
			if(ds1[i] == -1) {
				ds1[i] = ds1[x]+1;
				q.push(i);
			}
		}
	}
	de1[2] = 0, q.push(2);
	while(!q.empty()) {
		int x = q.front(); q.pop();
		for(int i : v[x]) {
			if(de1[i] == -1) {
				de1[i] = de1[x]+1;
				q.push(i);
			}
		}
	}
	for(int i = 3;i <= n;i++) {
		if(ds1[i] == 1) {cs1++; c[i] = 1;}
		else if(de1[i] == 1) {ce1++; c[i] = 2;}
		else {cnam++; c[i] = 3;}
	}
	int ans = cs1*(cs1-1)/2+ce1*(ce1-1)/2+cnam*(cnam-1)/2;
	for(int i = 1;i <= m;i++) {
		int x = edge[i].x, y = edge[i].y;
		if(c[x] == c[y]) ans--;
	}
	for(int i = 1;i <= n;i++) {
		int cs = 0,ce = 0;
		if(c[i] == 3) {
			for(int j : v[i]) {
				if(ds1[j] == 1) cs++;
				if(de1[j] == 1) ce++;
			}
			if(!cs&&!ce) ans += max(cs1,ce1);
			else if(!cs) ans += ce1-ce;
			else ans += cs1-cs;
		}
	}
	cout << ans;
}