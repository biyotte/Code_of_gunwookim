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
const long long llINF = 1e18;
const long long mod = 998244353;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,m;
char a[100005],b[100005];
pi d[100005];
int wi[100005];
int t[400005],cnt[100005];
int t2[400005],cnt2[100005];
priority_queue <pi> q;

void build(int x,int l,int r) {
	if(l == r) {
		t[x] = cnt[l];
		t2[x] = cnt2[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(x*2,l,mid), build(x*2+1,mid+1,r);
}

void update(int x,int l,int r,int rl,int rr,int val) {
	if(rl > r||l > rr) return;
	if(rl <= l&&r <= rr) {
		t[x] += val;
		return;
	}
	int mid = (l + r) >> 1;
	update(x*2,l,mid,rl,rr,val), update(x*2+1,mid+1,r,rl,rr,val);
}

int query(int x,int l,int r,int wi) {
	if(!wi) return 0;
	if(wi < l||r < wi) return 0;
	if(l == r) return t[x];
	int mid = (l + r) >> 1;
	return query(x*2,l,mid,wi)+query(x*2+1,mid+1,r,wi)+t[x];
}

void update2(int x,int l,int r,int rl,int rr,int val) {
	if(rl > r||l > rr) return;
	if(rl <= l&&r <= rr) {
		t2[x] += val;
		return;
	}
	int mid = (l + r) >> 1;
	update2(x*2,l,mid,rl,rr,val), update2(x*2+1,mid+1,r,rl,rr,val);
}

int query2(int x,int l,int r,int wi) {
	if(wi == n+1) return 0;
	if(wi < l||r < wi) return 0;
	if(l == r) return t2[x];
	int mid = (l + r) >> 1;
	return query2(x*2,l,mid,wi)+query2(x*2+1,mid+1,r,wi)+t2[x];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); 
	cin >> n >> a+1;
	for(int i = 1;i <= n;i++) {
		b[i] = a[i];
		if(a[i] == '?') {
			wi[++m] = i;
		}
	}
	ll ans = 0;
	for(int i = 1;i <= m;i++) {
		cin >> d[i].x >> d[i].y;
		a[wi[i]] = '(';
		ans += d[i].x;
		q.push({-(d[i].y-d[i].x),wi[i]});
	}

	int sum;
	for(int i = 1;i <= n;i++) {
		cnt[i] = cnt[i-1];
		if(a[i] == '(') cnt[i]++;
		else cnt[i]--;
	}
	for(int i = n;i >= 1;i--) {
		cnt2[i] = cnt2[i+1];
		if(a[i] == '(') cnt2[i]--;
		else cnt2[i]++;
	}
	build(1,1,n);
	while(!q.empty()) {
		pi x = q.top(); q.pop();
		int val = query(1,1,n,x.y-1);
		int val2 = query2(1,1,n,x.y+1);
		cout << x.x << ' ' << x.y << ' ' << val << ' ' << val2 << '\n';
		if(val > val2) {
			ans += -x.x, a[x.y] = ')';
			update(1,1,n,x.y,n,2);
			update2(1,1,n,1,x.y,2);
		}
	}
	cout << ans << '\n';
	for(int i = 1;i <= n;i++) cout << a[i];
}