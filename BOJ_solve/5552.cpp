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
int w,h,n;
pl a[100005];
ll x[100005],y[100005];
ll sx,sy,di[100005],ans = llINF;

ll dist(pl x,pl y) {return abs(x.x-y.x)+abs(x.y-y.y);}

void go(ll x,ll y) {
	ll sum = 0,mx = 0;
	for(int i = 1;i <= n;i++) {
		sum += dist({x,y},a[i])*2;
		mx = max(mx,dist({x,y},a[i]));
	}
	if(sum-mx < ans) {
		ans = sum-mx;
		sx = x, sy = y;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> w >> h >> n;
	for(int i = 1;i <= n;i++) cin >> a[i].x >> a[i].y, x[i] = a[i].x, y[i] = a[i].y, sx += a[i].x, sy += a[i].y;
	sort(x+1,x+n+1), sort(y+1,y+n+1);
	ll px = x[(n+1)/2], py = y[(n+1)/2];
	go(x[(n+1)/2],y[(n+1)/2]), go(x[(n+1)/2],y[(n+1)/2+1]), go(x[(n+1)/2+1],y[(n+1)/2]), go(x[(n+1)/2+1],y[(n+1)/2+1]);
	cout << ans << '\n' << sx << ' ' << sy;
}