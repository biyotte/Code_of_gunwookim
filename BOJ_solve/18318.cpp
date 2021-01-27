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
int t[800005];
int n,m,d[200005];
vec revx,revy;
vecpi v[200005];

struct Line {
	int x1,y1,x2,y2;
	int rx1,ry1,rx2,ry2;
}a[100005];

void update(int x,int l,int r,int wi,int val) {
	if(wi < l||r < wi) return;
	if(l == r) {t[x] = min(t[x],val); return;}
	int mid = (l + r) >> 1;
	update(x*2,l,mid,wi,val), update(x*2+1,mid+1,r,wi,val);
	t[x] = min(t[x*2],t[x*2+1]);
}

int query(int x,int l,int r,int rl,int rr) {
	if(rl > r||l > rr) return INF;
	if(rl <= l&&r <= rr) return t[x];
	int mid = (l + r) >> 1;
	return min(query(x*2,l,mid,rl,rr),query(x*2+1,mid+1,r,rl,rr));
}

bool cmp(pi x,pi y) {
	int x1 = (x.y == 1 ? a[x.x].y1 : a[x.x].y2);
	int x2 = (y.y == 1 ? a[y.x].y1 : a[y.x].y2);
	return x1 < x2;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= m;i++) {
		cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;
		a[i].rx1 = a[i].x1, a[i].ry1 = a[i].y1, a[i].rx2 = a[i].x2, a[i].ry2 = a[i].y2;
		revx.pb(a[i].x1), revx.pb(a[i].x2);
		revy.pb(a[i].y1), revy.pb(a[i].y2);
	}
	sort(all(revx)), revx.erase(unique(all(revx)),revx.end());
	sort(all(revy)), revy.erase(unique(all(revy)),revy.end());
	for(int i = 1;i <= m;i++) {
		a[i].x1 = lower_bound(all(revx),a[i].x1)-revx.begin()+1;
		a[i].y1 = lower_bound(all(revy),a[i].y1)-revy.begin()+1;
		a[i].x2 = lower_bound(all(revx),a[i].x2)-revx.begin()+1;
		a[i].y2 = lower_bound(all(revy),a[i].y2)-revy.begin()+1;
		v[a[i].x1].pb({i,1}); // getAns
		v[a[i].x2].pb({i,-1}); // insert tree
	}
	for(int i = 1;i <= 2*m;i++) {
		sort(all(v[i]),cmp);
		for(pi tmp : v[i]) {
			int idx = tmp.x, op = tmp.y;
			if(op == 1) {
				d[idx] = a[idx].rx1+a[idx].ry1+query(1,1,2*m,1,a[idx].y1);
			}
			else {
				update(1,1,2*m,a[idx].y2,d[idx]-a[idx].rx2-a[idx].ry2);
			}
		}
	}
	int ans = 2*INF;
	for(int i = 1;i <= m;i++) ans = min(ans,d[i]-a[i].rx2-a[i].ry2);
	cout << 2*n+ans;
}
