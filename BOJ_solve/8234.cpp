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
int n;
int a[250005];
pi b[250005];
ll t[1000005];
vec ans;
set <pl> s;

void build(int x,int l,int r) {
	if(l == r) {t[x] = a[l]; return;}
	int mid = (l + r) >> 1;
	build(x*2,l,mid), build(x*2+1,mid+1,r);
	t[x] = t[x*2]+t[x*2+1];
}

void update(int x,int l,int r,int wi,ll val) {
	if(wi < l||r < wi) return;
	if(l == r) {
		t[x] = val;
		return;
	}
	int mid = (l + r) >> 1;
	update(x*2,l,mid,wi,val), update(x*2+1,mid+1,r,wi,val);
	t[x] = t[x*2]+t[x*2+1];
}

ll query(int x,int l,int r,int rr) {
	if(l > rr) return 0;
	if(r <= rr) return t[x];
	int mid = (l + r) >> 1;
	return query(x*2,l,mid,rr)+query(x*2+1,mid+1,r,rr);
}

void up(int x,ll val) {
	auto it = s.lower_bound({x+1,0});
	it--;
	vector <pl> er;
	while(it->y < val) {
		er.pb(*it);
		update(1,1,n,it->x,0);
		val -= it->y;
		it--;
	}
	int wi = it->x;
	val = it->y-val;
	update(1,1,n,wi,val);
	er.pb(*it);
	for(pl i : er) s.erase(i);
	if(val) s.insert({wi,val});
}

int main() {
	ios_base::sync_with
	.03_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i], s.insert({i,a[i]});
	for(int i = 1;i <= n;i++) cin >> b[i].x, b[i].y = i;
	sort(b+1,b+n+1); build(1,1,n);
	for(int i = 1;i <= n;i++) {
		int idx = b[i].y;
		if(query(1,1,n,idx) >= b[i].x) {
			up(idx,b[i].x);
			ans.pb(idx);
		}
	}
	sort(all(ans));
	cout << ans.size() << '\n';
	for(int i : ans) cout << i << ' ';
}
