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
const long long llINF = 1e16;
const long long mod = 1e9+7;
const long long hashmod = 100003;
const int MAXN = 100000;
const int MAXM = 1000000;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n;
pl a[1505];
vector <pair<pair<pi,ll>,pi>> v; 

// not solved

ld Rect(int lx,int ly,int rx) {
	return sqrt((a[lx].x-a[rx].x)*(a[lx].x-a[rx].x)+(a[lx].y-a[rx].y)*(a[lx].y-a[rx].y))*sqrt((a[ly].x-a[rx].x)*(a[ly].x-a[rx].x)+(a[ly].y-a[rx].y)*(a[ly].y-a[rx].y));;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i].x >> a[i].y;
	for(int i = 1;i <= n;i++) {
		for(int j = i+1;j <= n;j++) {
			v.pb({{{(a[i].x+a[j].x),(a[i].y+a[j].y)},(a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y)},{i,j}});
		}
	}
	sort(all(v));
	vecpi c;
	ll len = v[0].x.x.y;
	ld ans = 0;
	for(auto i : v) {
		if(len^i.x.x.y) {
			for(int j = 0;j < c.size();j++) {
				for(int k = j+1;k < c.size();k++) {
					ans = max(ans,Rect(c[j].x,c[j].y,c[k].x));
				}
			}
			len = i.x.x.y;
			c.clear();
		}
		c.pb(i.y);
	}
	cout << fixed << setprecision(0);
	cout << ans;
}
