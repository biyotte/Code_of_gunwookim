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
const long long llINF = 1e18;
const long long mod = 998244353;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n;
vec a;

vec getPi(vec ss) {
	int m = ss.size(), j = 0;
	vec P(m,0);
	for(int i = 1;i < m;i++) {
		while(j&&ss[i]^ss[j]) j = P[j-1];
		if(ss[i] == ss[j]) P[i] = ++j;
	}
	return P;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); 
	cin >> n;
	a.resize(n);
	for(int i = 0;i < n;i++) cin >> a[i];
	reverse(all(a));
	auto p = getPi(a);
	int ak = n,ap = n;
	for(int i = 0;i < n;i++) {
		int tp = i-p[i]+1, tk = n-i-1;
		if(ak+ap > tk+tp||(ak+ap == tk+tp&&ap > tp)) ak = tk, ap = tp;
	}
	cout << ak << ' ' << ap;
}
