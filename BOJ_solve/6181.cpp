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
int n,p[100005],sz[100005];
ll k;

int Find(int x) {return (x^p[x] ? p[x] = Find(p[x]) : x);}

void merge(int x,int y) {
	x = Find(x), y = Find(y);
	if(x == y) return;
	p[y] = x;
	sz[x] += sz[y];
}

struct Point {
	ll x,y,idx;
}a[100005],tmp[100005];

bool cmpx(Point x,Point y) {
	return x.x < y.x;
}

void DnC(int l,int r) {
	if(l == r) return;
	int mid = (l + r) >> 1;
	int wx = a[mid].x;
	DnC(l,mid), DnC(mid+1,r);
	deque <int> L,R;
	int li = l,ri = mid+1,g = l;
	while(li <= mid||ri <= r) {
		if(ri > r||(li <= mid&&a[li].y < a[ri].y)) {
			while(!L.empty()&&a[li].y-a[L.front()].y > k) L.pop_front();
			if(!L.empty()&&abs(a[L.front()].x-a[li].x) <= k) merge(a[L.front()].idx,a[li].idx);
			while(!R.empty()&&abs(a[R.back()].x-wx) > abs(a[li].x-wx)) R.pop_back();
			R.pb(li); tmp[g++] = a[li++];
		}
		else {
			while(!R.empty()&&a[ri].y-a[R.front()].y > k) R.pop_front();
			if(!R.empty()&&abs(a[R.front()].x-a[ri].x) <= k) merge(a[R.front()].idx,a[ri].idx);
			while(!L.empty()&&abs(a[L.back()].x-wx) > abs(a[ri].x-wx)) L.pop_back();
			L.pb(ri); tmp[g++] = a[ri++];
		}
	}
	for(int i = l;i <= r;i++) a[i] = tmp[i];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	for(int i = 1;i <= n;i++) {
		ll x,y; cin >> x >> y;
		a[i] = {x+y,x-y,i};
		p[i] = i, sz[i] = 1;
	}
	sort(a+1,a+n+1,cmpx);
	DnC(1,n);
	int cnt = 0,mx = 0;
	for(int i = 1;i <= n;i++) {
		if(Find(i) == i) cnt++, mx = max(mx,sz[i]);
	}
	cout << cnt << ' ' << mx;
}