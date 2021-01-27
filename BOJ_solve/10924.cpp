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
int n,m;
int a[200005],b[200005],bgo[200005],c[200005],cgo[200005];
pi q[600005],ans[600005];

bool isok(int mid) {
	for(int i = 1;i <= n;i++) {
		b[i] = bgo[i] = i;
		c[i] = a[i], cgo[c[i]] = i;
	}
	for(int i = mid;i >= 1;i--) {
		swap(b[q[i].x],b[q[i].y]);
		swap(bgo[b[q[i].x]],bgo[b[q[i].y]]);
	}
	queue <int> Q;
	for(int i = 1;i <= n;i++) {
		if(b[i]^c[i]) Q.push(b[i]);
	}
	for(int i = 1;i <= mid;i++) {
		int x = q[i].x, y = q[i].y;
		swap(b[x],b[y]), swap(bgo[b[x]],bgo[b[y]]);
		swap(c[x],c[y]), swap(cgo[c[x]],cgo[c[y]]);
		while(!Q.empty()&&bgo[Q.front()] == cgo[Q.front()]) Q.pop();
		if(!Q.empty()) {
			int idx = Q.front(); Q.pop();
			int X = bgo[idx], Y = cgo[idx];
			ans[i] = {X-1,Y-1};
			swap(c[X],c[Y]), swap(cgo[c[X]],cgo[c[Y]]);
		}
		else ans[i] = {0,0};
	}
	for(int i = 1;i <= n;i++) if(i^c[i]) return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	bool End = true;
	for(int i = 1;i <= n;i++) cin >> a[i], a[i]++, End &= (a[i] == i);
	cin >> m;
	for(int i = 1;i <= m;i++) {
		cin >> q[i].x >> q[i].y;
		q[i].x++, q[i].y++;
	}
	if(End) {
		cout << 0;
		return 0;
	}
	int l = 1, r = n;
	while(l < r) {
		int mid = (l + r) >> 1;
		if(isok(mid)) r = mid;
		else l = mid+1;
	}
	isok(l);
	cout << l << '\n';
	for(int i = 1;i <= l;i++) {
		cout << ans[i].x << ' ' << ans[i].y << '\n';
	}
}