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
int n,p[1000005],c[1000005],c2[1000005];
int is[1000005];
int ind[1000005],ansmx,ansmn;

void find_cycle(int x,int live) {
	if(c2[x]) {
		cycle.pb(x);
		for(st = p[x];st != x;st = p[x]) cycle.pb(st);
		return;
	}
	if(c[x]) return;
	c[x] = c2[x] = 1;
	find_cycle(p[x],live^1);
	c2[x] = 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n, ansmx = ansmn = n;
	for(int i = 1;i <= n;i++) cin >> p[i], ind[p[i]]++;
	for(int i = 1;i <= n;i++) {
		if(!ind[i]) {
			ansmx--;
			cycle.clear();
			find_cycle(i,1);
			if(!cycle.empty()) {
				for(int )
			}
		}
	}
}