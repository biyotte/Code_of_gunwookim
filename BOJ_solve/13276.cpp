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
const long long mod = 998244353;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
string a,st,en;
int n,slen,elen;
vec pa,pb;
vec l,r;

vec getPi(string ss) {
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
	cin >> a >> st >> en;
	n = a.length(), slen = st.length(), elen = en.length();
	pa = getPi(st), pb = getPi(en);
	for(int i = 0,j = 0;i < n;i++) {
		while(j&&a[i] != st[j]) j = pa[j-1];
		if(a[i] == st[j]) {
			if(j == slen-1) {
				l.pb(i-slen+1);
				j = pa[j];
			}
			else j++;
		}
	}
	for(int i = 0,j = 0;i < n;i++) {
		while(j&&a[i] != en[j]) j = pb[j-1];
		if(a[i] == en[j]) {
			if(j == elen-1) {
				r.pb(i);
				j = pb[j];
			}
			else j++;
		}
	}
	unordered_set <string> s;
	for(int L : l) {
		for(int R : r) {
			if(L > R||max(slen,elen) > R-L+1) continue;
			s.insert(a.substr(L,R-L+1));
		}
	}
	cout << s.size();
}