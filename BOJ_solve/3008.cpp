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
int n,co;
pl a[1505];
set <pair<ld,ll>> s;

ld getGi(int x,int y) {
	if(a[x].x == a[y].x) return llINF;
	return (ld)(a[y].y-a[x].y)/(a[y].x-a[x].x);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i].x >> a[i].y;
	ll ans = 0;
	for(int i = 1;i <= n;i++) {
		for(int j = i+1;j <= n;j++) {
			ld gi = getGi(i,j);
			auto it = s.lower_bound({gi,0});
			if((*it).x != gi) s.insert({gi,1});
			else {
				ll val = (*it).y;
				s.erase(it);
				s.insert({gi,val+1});
			}
			it = s.lower_bound({(gi == llINF ? (ld)0.0 : (ld)-1.0/gi),0});
			if((*it).x != gi) continue;
			ans += (*it).y;
		}
	}
	cout << ans;
}