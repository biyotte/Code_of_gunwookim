#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define all(v) v.begin(),v.end()
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
using namespace std;
const long long INF = 1e8;
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
ld sx,sy,R;
map <ll,int> l,r;

ld dist(ld x,ld y) {
	return (x-sx)*(x-sx)+(y-sy)*(y-sy);
}

bool isSafe(ld x,ld y) {
	return INF*dist(x,y) <= INF*R*R;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> sx >> sy >> R;
	ll y = ceil(sy);
	for(ll x = ceil(sx-R);x <= floor(sx);x++) {
		while(isSafe(x,y)) y++;
		r[x] = y-1;
	}
	y = ceil(sy);
	for(ll x = floor(sx+R);x >= ceil(sx);x--) {
		while(isSafe(x,y)) y++;
		r[x] = y-1;
	}

	y = floor(sy);
	for(ll x = ceil(sx-R);x <= floor(sx);x++) {
		while(isSafe(x,y)) y--;
		l[x] = y+1;
	}
	y = floor(sy);
	for(ll x = floor(sx+R);x >= ceil(sx);x--) {
		while(isSafe(x,y)) y--;
		l[x] = y+1;
	}
	vector <ll> p;
	for(auto i : l) p.pb(i.x);
	ll sum = 0;
	for(ll i : p) {
		cout << i << " : " << l[i] << ' ' << r[i] << '\n';
		if(r[i]-l[i]+1 < 0) return -1;
		sum += r[i]-l[i]+1;
	}
	cout << sum;
}
