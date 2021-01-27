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
int n,m,correct,cnt[26],cnt2[26];
char a[1505],b[1505];
set <vec> s;

bool isok(int mid) {
	s.clear();
	vec v(26,0);
	for(int i = 1;i <= m;i++) {
		v[b[i]-'a']++;
		if(i >= mid) {
			if(i > mid) v[b[i-mid]-'a']--;
			s.insert(v);
		}
	}
	v.clear(), v.resize(26);
	for(int i = 1;i <= n;i++) {
		v[a[i]-'a']++;
		if(i >= mid) {
			if(i > mid) v[a[i-mid]-'a']--;
			if(s.find(v) != s.end()) return true;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); 
	cin >> a+1 >> b+1;
	n = strlen(a+1), m = strlen(b+1);
	int i;
	for(i = min(n,m);i;i--) if(isok(i)) break;
	cout << i;
}
