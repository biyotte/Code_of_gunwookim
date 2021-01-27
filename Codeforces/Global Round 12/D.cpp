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
int n,c[300005];
int p[300005],a[300005];
int l[300005],r[300005],ans[300005];
vec v[300005];
set <int> s;

int Find(int x) {return (x^p[x] ? p[x] = Find(p[x]) : x);}

void merge(int x,int y) {
	x = Find(x), y = Find(y);
	if(x == y) return;
	p[y] = x;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); 
	int T; cin >> T;
	while(T--) {
		cin >> n;
		s.clear();
		for(int i = 1;i <= n;i++) cin >> a[i], p[i] = i, c[i] = 0, v[i].clear();
		c[0] = c[n+1] = 1;
		s.insert(0), s.insert(n+1);
		for(int i = 1;i <= n;i++) v[a[i]].pb(i), l[i] = 1, r[i] = n;
		for(int i = 1;i <= n;i++) {
			if(v[i].empty()) {
				l[i] = n+1, r[i] = 0;
				continue;
			}
			for(int j : v[i]) {
				c[j] = 1;
				if(c[j-1]) merge(j-1,j);
				if(c[j+1]) merge(j,j+1);
			}
			if(!s.empty()) {
				for(int x : v[i]) {
					if(c[x-1]||c[x+1]) {
						int R = *s.lower_bound(x);
						int L = *prev(s.upper_bound(x));
						l[i] = max(l[i],1), r[i] = min(r[i],R-L-1);
					}
					else {
						int R = *s.lower_bound(x);
						int L = *prev(s.upper_bound(x));
						l[i] = max(l[i],R-L-1), r[i] = min(r[i],R-L-1);
					}
				}
			}
			for(int j : v[i]) s.insert(j);
		}
		int L = 1,R = n;
		for(int i = 1;i <= n;i++) {
			L = max(L,l[i]), R = min(R,r[i]);
			if(L <= n-i+1&&n-i+1 <= R) ans[n-i+1] = 1;
			else ans[n-i+1] = 0;
			//cout << l[i] << ' ' << r[i] << '\n';
		}
		int nope = 0;
		for(int i = 1;i <= n;i++) {
			if(v[i].empty()) nope = 1;
		}
		if(!nope) ans[1] = 1;
		for(int i = 1;i <= n;i++) cout << ans[i];
		cout << '\n';
	}
}