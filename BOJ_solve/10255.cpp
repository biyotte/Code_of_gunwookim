#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define all(v) v.begin(),v.end()
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
using namespace std;
const long long INF = 1e9;
const int TMX = 1 << 18;
const long long llINF = 1e18;
const long long mod = 1e9+7;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pl;
typedef pair <ll,ll> pi;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
#define Point pair<pi,pi>
bool isno;

ll ccw(pi a,pi b,pi c) {
    ll op = a.x*b.y+b.x*c.y+c.x*a.y;
    op -= (a.y*b.x+b.y*c.x+c.y*a.x);
    if(op > 0) return 1;
    else if(op == 0) return 0;
    else return -1;
}
 
ll IsMaching(Point x,Point y) {
    pi a = x.x, b = x.y, c = y.x, d = y.y;
    if((a.x == b.x&&b.x == c.x&&c.x == d.x)||(a.y == b.y&&b.y == c.y&&c.y == d.y)) {
    	if(a.x == b.x&&b.x == c.x&&c.x == d.x) {
    		if(a.y > b.y) swap(a,b);
    		ll l = max(a.y,c.y),r = min(b.y,d.y);
    		if(l > r) return 0;
    		if(l == r) return 1;
    		return INF/4;
    	}
    	else {
    		if(a.x > b.x) swap(a,b);
    		ll l = max(a.x,c.x),r = min(b.x,d.x);
    		if(l > r) return 0;
    		if(l == r) return 1;
    		return INF/4;
    	}
    }
    ll ab = ccw(a,b,c)*ccw(a,b,d);
    ll cd = ccw(c,d,a)*ccw(c,d,b);
    if(ab == 0&&cd == 0) {
        if(a > b) swap(a,b);
        if(c > d) swap(c,d);
        if(a == c||a == d||b == c||b == d) return 1;
        return INF/4;
    }
    return ab <= 0&&cd <= 0;
}
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while(T--) {
		ll xmin,ymin,xmax,ymax,x1,y1,x2,y2;
		cin >> xmin >> ymin >> xmax >> ymax;
		cin >> x1 >> y1 >> x2 >> y2;
		xmin *= 1000, ymin *= 1000, xmax *= 1000, ymax *= 1000;
		x1 *= 1000, y1 *= 1000, x2 *= 1000, y2 *= 1000;
		Point line_up = {{xmin,ymin},{xmin,ymax}};
		Point line_down = {{xmax,ymin},{xmax,ymax}};
		Point line_left = {{xmin+1,ymin},{xmax-1,ymin}};
		Point line_right = {{xmin+1,ymax},{xmax-1,ymax}};
		Point line = {{x1,y1},{x2,y2}};
		ll bit = 0;
		bit += IsMaching(line,line_up);
		bit += IsMaching(line,line_down);
		bit += IsMaching(line,line_left);
		bit += IsMaching(line,line_right);
		if(bit > 2) cout << "4\n";
		else cout << bit << '\n';

	}
}
