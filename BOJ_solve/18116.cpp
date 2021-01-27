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
int n,p[1000005],sz[1000005];

int Find(int x) {return (x^p[x] ? p[x] = Find(p[x]) : x);}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); 
	cin >> n;
	for(int i = 1;i <= 1000000;i++) p[i] = i, sz[i] = 1;
	while(n--) {
		char op; int x,y;
		cin >> op >> x;
		if(op == 'I') {
			cin >> y;
			if(Find(x) == Find(y)) continue;
			sz[Find(x)] += sz[Find(y)], p[Find(y)] = Find(x);
		}
		else cout << sz[Find(x)] << '\n';
	}
}