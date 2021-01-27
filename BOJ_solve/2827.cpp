#include <bits/stdc++.h>
#define t first
#define c second
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
int n,Q,la[200005];
ll t[400005],cnt[400005],sumT,sumL;
vecpi rev;

struct Query {
	int x,t,c;
}a[400005];

int getWi(int idx) {
	return lower_bound(all(rev),make_pair(-a[idx].t,idx))-rev.begin();
}

ll queryT(int x) {
	ll ret = 0;
	for(;x;x -= x&-x) ret += t[x];
	return ret;
}

ll queryCnt(int x) {
	ll ret = 0;
	for(;x;x -= x&-x) ret += cnt[x];
	return ret;
}

ll queryT(int l,int r) {return queryT(r+1)-queryT(l);}
ll queryCnt(int l,int r) {return queryCnt(r+1)-queryCnt(l);}
void updateT(int x,ll val) {for(x++;x <= n+Q;x += x&-x) t[x] += val;}
void updateCnt(int x,ll val) {for(x++;x <= n+Q;x += x&-x) cnt[x] += val;}

void pushpop(int pos,int x,ll val) {
	sumT += val*((queryCnt(0,pos-1)+1)*a[x].t+queryT(pos+1,n+Q-1));
	sumL += val*a[x].c;
	updateT(pos,val*a[x].t);
	updateCnt(pos,val);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> Q;
	for(int i = 1;i <= n;i++) {
		cin >> a[i].c >> a[i].t;
		rev.pb({-a[i].t,i});
	}
	for(int i = 1;i <= Q;i++) {
		cin >> a[i+n].x >> a[i+n].c >> a[i+n].t;
		rev.pb({-a[i+n].t,i+n});
	}
	sort(all(rev));
	for(int i = 1;i <= n;i++) {
		pushpop(getWi(i),i,1);
		la[i] = i;
	}
	cout << sumL-sumT << '\n';
	for(int i = n+1;i <= n+Q;i++) {
		pushpop(getWi(la[a[i].x]),la[a[i].x],-1);
		pushpop(getWi(i),i,1);
		la[a[i].x] = i;
		cout << sumL-sumT << '\n';
	}
}
