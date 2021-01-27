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
int n,Q,m;
vec rev;
int ans[100005];
int t[600005];

void update(int x,int val) {
	for(;x <= m;x += x&-x) t[x] += val;
}

int query(int l,int r) {
	if(l > r) return 0;
	int ret = 0;
	for(;r;r -= r&-r) ret += t[r];
	for(l--;l;l -= l&-l) ret -= t[l];
	return ret;
}

struct Score {
	int x,y,z,idx;
}a[100005],q[100005];

bool cmp(Score x,Score y) {
	if(x.x == y.x) {
		if(x.y == y.y) return x.z < y.z;
		return x.y < y.y;
	}
	return x.x < y.x;
}

void DnC(int nl,int nr,int ql,int qr) {
	if(ql > qr) return;
	if(ql == qr||nl == nr) {
		for(int i = nl;i <= nr;i++) {
			for(int j = ql;j <= qr;j++) {
				ans[q[j].idx] += (a[i].x >= q[j].x&&a[i].y >= q[j].y&&a[i].z >= q[j].z);
			}
		}
		return;
	}
	int midn = (nl + nr) >> 1;
	int midq = ql,g = 0;
	while(midq <= qr&&q[midq].x <= a[midn].x) midq++;
	vector <Score> L,R;
	for(int i = midn+1;i <= nr;i++) R.pb({-a[i].y,a[i].z,i});
	for(int i = ql;i < midq;i++) L.pb({-q[i].y,q[i].z,i});
	sort(all(L),cmp), sort(all(R),cmp);
	for(Score i : L) {
		while(g < R.size()&&R[g].x <= i.x) update(R[g++].y,1);
		ans[q[i.z].idx] += query(i.y,m);
	}
	for(int i = 0;i < g;i++) update(R[i].y,-1);
	DnC(nl,midn,ql,midq-1);
	DnC(midn+1,nr,midq,qr);
}

int getIdx(int x) {return lower_bound(all(rev),x)-rev.begin()+1;}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> Q;
	for(int i = 1;i <= n;i++) {
		cin >> a[i].x >> a[i].y;
		a[i].z = a[i].x+a[i].y;
		rev.pb(a[i].x), rev.pb(a[i].y), rev.pb(a[i].z);
	}
	for(int i = 1;i <= Q;i++) {
		cin >> q[i].x >> q[i].y >> q[i].z;
		q[i].idx = i;
		rev.pb(q[i].x), rev.pb(q[i].y), rev.pb(q[i].z);
	}
	sort(all(rev)); rev.erase(unique(all(rev)),rev.end());
	m = rev.size();
	for(int i = 1;i <= n;i++) {
		a[i].x = getIdx(a[i].x);
		a[i].y = getIdx(a[i].y);
		a[i].z = getIdx(a[i].z);
	}
	for(int i = 1;i <= Q;i++) {
		q[i].x = getIdx(q[i].x);
		q[i].y = getIdx(q[i].y);
		q[i].z = getIdx(q[i].z);
	}
	sort(a+1,a+n+1,cmp), sort(q+1,q+Q+1,cmp);
	DnC(1,n,1,Q);
	for(int i = 1;i <= Q;i++) cout << ans[i] << '\n';
}