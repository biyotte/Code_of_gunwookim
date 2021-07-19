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
const long long llINF = 1e18+10;
const long long mod = 998244353;
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
ll n,k;
int st,a[25],cn;

struct T {
	int x,f;
	ll g;
};

map <pair<int,pair<pi,ll>>,ll> d;

pair <int,pair <pi,ll>> F(int x,int f,int s,int g) {
	return make_pair(x,make_pair(make_pair(f,s),g));
}

ll go(int x,int f,int s,ll g) {
	if(d.find(F(x,f,s,g)) != d.end()) return d[F(x,f,s,g)];
	if(g > k) g = k+1;
	if(x == -1) return s&&(g > k);
	if(!f) {
		ll sum = 0;
		if(!s) {
			sum += go(x-1,0,0,g);
			for(int i = 1;i <= 9;i++) {
				sum += go(x-1,0,1,g*i);
			}
			return d[F(x,f,s,g)] = sum;
		}
		for(int i = 0;i <= 9;i++) sum += go(x-1,0,1,g*i);
		return d[F(x,f,s,g)] = sum;
	}
	else {
		ll sum = 0;
		if(!s) {
			sum += go(x-1,0,0,g);
		}
		sum += go(x-1,1,1,g*a[x]);
		for(int i = 0;i < a[x];i++) {
			if(!i&&!s) continue;
			sum += go(x-1,0,1,g*i);
		}
		return d[F(x,f,s,g)] = sum;
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	ll rn = n;
	while(rn) {
		a[cn++] = rn%10;
		rn /= 10;
	}
	cn--;
	st = cn;
	cout << go(cn,1,0,1) << ' ';
}
