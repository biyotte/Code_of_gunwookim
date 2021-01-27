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
ll k;
int n,m;
int c[1505];
vec st;

vec gop(vec x,vec y) {
	memset(c,0,sizeof(c));
	for(int i : x) {
		for(int j : y) c[i*j%n] = 1; 
	}
	vec ret;
	for(int i = 0;i < n;i++) if(c[i]) ret.pb(i);
	return ret;
}

vec mpow(ll x) {
	if(x == 1) return st;
	vec tmp = mpow(x/2);
	tmp = gop(tmp,tmp);
	if(x % 2) return gop(tmp,st);
	return tmp;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> k >> n >> m;
	for(int i = 1;i <= m;i++) {
		int x; cin >> x;
		st.pb(x);
	}
	vec ans = mpow(k);
	for(int i : ans) cout << i << ' ';
}