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
int Q;
int t[100005];
ll ans[100005];

struct Point {
	int x,y,ti,w;
};
vector <Point> a;

bool cmp(Point x,Point y) {
	if(x.x^y.x) return x.x < y.x;
	if(x.y^y.y) return x.y < y.y;
	return abs(x.w) < abs(y.w);
}

bool cmpDnC(Point x,Point y) {
	return x.y < y.y;
}

void update(int x,int val) {
	for(;x <= Q;x += x&-x) t[x] += val;
}

int query(int x) {
	int ret = 0;
	for(;x;x -= x&-x) ret += t[x];
	return ret;
}

void DnC(int l,int r) {
	if(l == r) return;
	int mid = (l + r) >> 1;
	DnC(l,mid), DnC(mid+1,r);
	vector <Point> L,R;
	for(int i = l;i <= mid;i++) L.pb(a[i]);
	for(int i = mid+1;i <= r;i++) R.pb(a[i]);
	sort(all(L),cmpDnC), sort(all(R),cmpDnC);
	int pv = R.size()-1;
	for(int i = L.size()-1;i >= 0;i--) {
		while(pv >= 0&&L[i].y <= R[pv].y) {
			if(R[pv].w) update(R[pv].ti,R[pv].w);
			pv--;
		}
		if(!L[i].w) ans[L[i].ti] += query(L[i].ti);
	}
	for(int i = pv+1;i < R.size();i++) if(R[i].w) update(R[i].ti,-R[i].w);
	pv = 0;
	for(int i = 0;i < R.size();i++) {
		while(pv < L.size()&&L[pv].y <= R[i].y) {
			if(!L[pv].w) update(L[pv].ti,1);
			pv++;
		}
		if(R[i].w) ans[R[i].ti] += R[i].w*query(R[i].ti);
	}
	for(int i = 0;i < pv;i++) {
		if(!L[i].w) update(L[i].ti,-1);
	}
}

int readInt () {
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if(ch == '-') break;
		if(ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if(ch == '-') minus = true;
	else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0'||ch > '9') break;
		result = result*10+(ch-'0');
	}
	if(minus) return -result;
	else return result;
}

int main() {
	Q = readInt();
	int op,x,y,x2,y2;
	for(int i = 1;i <= Q;i++) {
		op = readInt(), x = readInt(), y = readInt();
		if(op == 2) {
			x2 = readInt(), y2 = readInt();
			a.pb({x-1,y-1,i,1});
			a.pb({x2,y-1,i,-1});
			a.pb({x-1,y2,i,-1});
			a.pb({x2,y2,i,1});
		}
		else a.pb({x,y,i,0});
	}
	sort(all(a),cmp);
	DnC(0,(int)a.size()-1);
	for(int i = 1;i <= Q;i++) printf("%lld\n",(ans[i]+=ans[i-1]));
}