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
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int T,n,cnv[2005];
int st[1005],top;

struct Point {
	ld x,y;
	ld gi;
}a[1005];

bool cmp(Point x,Point y) {
	if(x.x == y.x) return x.y < y.y;
	return x.x < y.x;
}

bool cmp2(Point x,Point y) {
	if(x.gi == y.gi) return x.x < y.x;
	return x.gi < y.gi;
}

int ccw(int A,int B,int C) {
	ll op = a[A].x*a[B].y+a[B].x*a[C].y+a[C].x*a[A].y;
	op -= a[A].y*a[B].x+a[B].y*a[C].x+a[C].y*a[A].x;
	if(op > 0) return 1;
	else if(op < 0) return -1;
	return 0;
}

ll Area(int A,int B,int C) {
	ll op = a[cnv[A]].x*a[cnv[B]].y+a[cnv[B]].x*a[cnv[C]].y+a[cnv[C]].x*a[cnv[A]].y;
	op -= a[cnv[A]].y*a[cnv[B]].x+a[cnv[B]].y*a[cnv[C]].x+a[cnv[C]].y*a[cnv[A]].x;
	return abs(op);
}

ll getAns(int stx,int sty) {
	int l = stx+1, r = sty-1;
	while(l < r) {
		int ml = (2*l + r) / 3;
		int mr = (l + 2*r) / 3;
		if(Area(stx,ml,sty) < Area(stx,mr,sty)) l = ml+1;
		else r = mr;
	}
	ll ret = Area(stx,l,sty);
	l = sty+1, r = stx+top-1;
	while(l < r) {
		int ml = (2*l + r) / 3;
		int mr = (l + 2*r) / 3;
		if(Area(stx,ml,sty) < Area(stx,mr,sty)) l = ml+1;
		else r = mr;
	}
	return ret+Area(stx,l,sty);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	while(T--) {
		cin >> n;
		for(int i = 1;i <= n;i++) cin >> a[i].x >> a[i].y;
		sort(a+1,a+n+1,cmp);
		for(int i = 2;i <= n;i++) {
			if(a[1].x == a[i].x) a[i].gi = INF;
			else a[i].gi = (a[1].y-a[i].y)/(a[1].x-a[i].x);
		}
		sort(a+2,a+n+1,cmp2);
		st[top = 1] = 1;
		for(int i = 2;i <= n;i++) {
			while(top >= 2&&ccw(st[top-1],st[top],i) <= 0) top--;
			st[++top] = i;
		}
		while(top >= 3&&ccw(st[top-1],st[top],1) <= 0) top--;
		for(int i = 1;i <= top;i++) cnv[i] = st[i];
		for(int i = 1;i <= top;i++) cnv[i+top] = st[i];
		ll ans = 0;
		for(int i = 1;i <= top;i++) {
			for(int j = i+1;j <= top;j++) {
				ans = max(ans,getAns(i,j));
			}
		}
	}
}
