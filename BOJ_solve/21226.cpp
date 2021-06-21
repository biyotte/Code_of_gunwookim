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
int n,Q,t[200005],ans[200005];
int a[200005],w[200005];
vec v[200005];
stack <pi> st;
struct Query {int x,y,idx;}q[200005];

bool cmp(Query x,Query y) {
	return x.x < y.x;
}

void update(int x) {
	for(;x <= n;x += x&-x) t[x]++;
}

int query(int x) {
	int ret = 0;
	for(;x;x -= x&-x) ret += t[x];
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> Q;
	st.push({0,0});
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
		while(st.top().x > a[i]) st.pop();
		if(st.top().x == a[i]) w[i] = st.top().y;
		st.push({a[i],i});
		v[w[i]].pb(i);
	}
	for(int i = 1;i <= Q;i++) {
		cin >> q[i].x >> q[i].y;
		q[i].idx = i;
	}
	sort(q+1,q+Q+1,cmp);
	int pv = 0;
	for(int i = 1;i <= Q;i++) {
		for(;pv < q[i].x;pv++) {
			for(int j : v[pv]) update(j);
		}
		ans[q[i].idx] = query(q[i].y)-q[i].x+1;
	}
	for(int i = 1;i <= Q;i++) cout << ans[i] << '\n';
}		