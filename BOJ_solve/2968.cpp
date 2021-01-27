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
const long long llINF = 1e18;
long long mod;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,m,line,val;
int ch;
ll k,tmp;

int f(int x,int y) {
	int ret = 0;
	for(int i = 20;i >= 0;i--) {
		if(y & (1 << i)) {
			int cnt = __builtin_popcount(x & ((1 << i)-1));
			ret += (1 << (i-cnt));
			if(x & (1 << i)) return ret;
		}
	}
	return ret;
}

int getAns(int x) {
	int r = line-x;
	if(line & 1) {
		int tm = max(0,line-m+1);
		if(x >= tm&&x < val+tm) r++;
	}
	else {
		int tm = line-max(0,line-n+1);
		if(x <= tm&&tm < val+x) r++;
	}
	return f(x,min(max(r,0),m));
}

void go(int x) {
	tmp += x;
	if(tmp > k) {ch = 1; return;}
	line++;
	val = k-tmp;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> k;
	int mn = min(n,m);
	for(int i = 1;i <= mn;i++) {
		if(ch) break;
		go(i);
		if(ch) break;
	}
	for(int i = 0;i < abs(n-m);i++) {
		if(ch) break;
		go(mn);
		if(ch) break;
	}
	for(int i = mn-1;i;i--) {
		if(ch) break;
		go(i);
		if(ch) break;
	}
	ll ans = 0;
	for(int i = 0;i < n;i++) ans += getAns(i);
	cout << ans;
}