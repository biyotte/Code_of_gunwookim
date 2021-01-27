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
const long long llINF = 2e18;
const long long mod = 1e18;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,m;
int t[10005];
pi a[2505];
vec xrev,yrev;

void build(int x,int l,int r) {
	t[x] = 0;
	if(l == r) return;
	int mid = (l + r) >> 1;
	build(x*2,l,mid), build(x*2+1,mid+1,r);
}

void update(int x,int l,int r,int wi) {
	if(wi < l||r < wi) return;
	if(l == r) {t[x]++; return;}
	int mid = (l + r) >> 1;
	update(x*2,l,mid,wi), update(x*2+1,mid+1,r,wi);
	t[x] = t[x*2]+t[x*2+1];
}

int query(int x,int l,int r,int rl,int rr) {
	if(rl > rr) return 0;
	if(rl > r||l > rr) return 0;
	if(rl <= l&&r <= rr) return t[x];
	int mid = (l + r) >> 1;
	return query(x*2,l,mid,rl,rr)+query(x*2+1,mid+1,r,rl,rr);
}

ll query(int l,int r) {
	if(l > r) swap(l,r);
	return 1LL*(query(1,1,m,1,l-1)+1)*(query(1,1,m,r+1,m)+1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) {
		int x,y; cin >> x >> y;
		xrev.pb(x), yrev.pb(y);
		a[i] = {x,y};
	}
	sort(all(xrev)), xrev.erase(unique(all(xrev)),xrev.end());
	sort(all(yrev)), yrev.erase(unique(all(yrev)),yrev.end());
	m = yrev.size();
	for(int i = 1;i <= n;i++) {
		a[i].x = lower_bound(all(xrev),a[i].x)-xrev.begin()+1;
		a[i].y = lower_bound(all(yrev),a[i].y)-yrev.begin()+1;
	}
	sort(a+1,a+n+1);
	ll ans = 1;
	for(int i = 1;i <= n;i++) {
		build(1,1,m);
		for(int j = i;j <= n;j++) {
			ans += query(a[i].y,a[j].y);
			update(1,1,m,a[j].y);
		}
	}
	cout << ans;
}