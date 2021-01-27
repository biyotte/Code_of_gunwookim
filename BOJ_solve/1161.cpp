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
int n,k,mx;
multiset <int> s;
vec v[20005];

struct Bus {
	int s,e,val;
}a[50005];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); 
	cin >> n >> k >> mx;
	for(int i = 1;i <= n;i++) {
		cin >> a[i].s >> a[i].e >> a[i].val;
		v[a[i].s].pb(i);
		v[a[i].e].pb(-i);
	}
	int ans = 0;
	for(int i = 1;i <= k;i++) {
		sort(all(v[i]));
		for(int j : v[i]) {
			if(j < 0) {
				j = -j;
				while(!s.empty()&&(*s.begin()) == i) {
					ans++, s.erase(s.begin());
				}
			}
			else {
				for(int l = 1;l <= a[j].val;l++) {
					if((int)s.size() == mx) {
						if((*prev(s.end())) <= a[j].e) break;
						s.erase(prev(s.end()));
					}
					s.insert(a[j].e);
				}
			}
		}
	}
	cout << ans;
}