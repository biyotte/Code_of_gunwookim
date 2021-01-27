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
string s;
int n;

vec getPi(string ss) {
	int m = ss.size(), j = 0;
	vec p(m,0);
	for(int i = 1;i < m;i++) {
		while(j&&ss[i]^ss[j]) j = p[j-1];
		if(ss[i] == ss[j]) p[i] = ++j;
	}
	return p;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t = 0;
	while(1) {
		t++;
		cin >> n;
		if(!n) break;
		cin >> s;
		auto p = getPi(s);
		cout << "Test case #" << t << '\n';
		for(int i = 1;i < n;i++) {
			if(p[i] != 0&&(i+1)%(i+1-p[i]) == 0) {
				cout << i+1 << ' ' << (i+1)/(i+1-p[i]) << '\n';
			}
		}
		cout << '\n';
	}
	
}