#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define all(v) v.begin(),v.end()
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
using namespace std;
const long long INF = 2e9;
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
int n;
pi a[3005];
vecpi v;
ll ans;

bool cmp(pi x,pi y) {return x.x*y.y > y.x*x.y;}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i].x >> a[i].y;
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;i++) {
		v.clear();
		for(int j = i+1;j <= n;j++) v.pb({a[j].x-a[i].x,a[j].y-a[i].y});
		sort(all(v),cmp);
	 	ll sx = 0,sy = 0;
	 	for(pi j : v) {
	 		ans += sx*j.y-sy*j.x;
	 		sx += j.x, sy += j.y;
	 	}
	}
	cout << ans/2 << "." << (ans%2 ? 5 : 0);
}
