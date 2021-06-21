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
ll t[800005],a[200005];
int n,Q;
ll S,T;

void update(int x,int l,int r,int rl,int rr,int val) {
	if(rl > r||l > rr) return;
	if(rl <= l&&r <= rr) {
		t[x] += val;
		return;
	}
	int mid = (l + r) >> 1;
	update(x*2,l,mid,rl,rr,val), update(x*2+1,mid+1,r,rl,rr,val);
}

ll query(int x,int l,int r,int wi) {
	if(wi < l||r < wi) return 0;
	if(l == r) return t[x];
	int mid = (l + r) >> 1;
	return query(x*2,l,mid,wi)+query(x*2+1,mid+1,r,wi)+t[x];
}

ll Val(int now) {
	if(!now) return 0;
	return a[now]+query(1,1,n,now);
}

ll f(int now) {
	if(now == n+1) return 0;
	if(Val(now-1) < Val(now)) return S*(Val(now-1)-Val(now));
	return T*(Val(now-1)-Val(now));
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> Q >> S >> T;
	for(int i = 0;i <= n;i++) cin >> a[i];
	ll ans = 0;
	for(int i = 1;i <= n;i++) ans += f(i);
	while(Q--) {
		int l,r,x; cin >> l >> r >> x;
		ans -= f(l)+f(r+1);
		update(1,1,n,l,r,x);
		ans += f(l)+f(r+1);
		cout << ans << '\n';
	}

}