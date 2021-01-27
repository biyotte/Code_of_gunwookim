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
const int MAXN = 100000;
const int MAXM = 1000000;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,m,la,p[500005];
int u[500005];
vecpi v[500005];
vec ans;
pi a[500005];

int Find(int x) {return (x^p[x] ? p[x] = Find(p[x]) : x);}

int merge(int x,int y) {
	x = Find(x), y = Find(y);
	if(x == y) return 0;
	p[y] = x;
	return 1;
}

ll mpow(int M) {
	if(!M) return 1;
	ll tmp = mpow(M/2);
	if(M % 2) return tmp*tmp*2%mod;
	return tmp*tmp%mod;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= m;i++) p[i] = i;
	for(int i = 1;i <= n;i++) {
		int K,x,x2 = 0;
		cin >> K >> x;
		if(K == 2) cin >> x2;
		if(x2&&x > x2) swap(x,x2);
		if(!x2) {
			if(!la) ans.pb(i);
			else if(merge(la,x)) ans.pb(i);
			la = x;
		}
		else if(merge(x,x2)) ans.pb(i);
	}
	cout << mpow((int)ans.size()) << ' ' << ans.size() << '\n';
	for(int i : ans) cout << i << ' ';
}