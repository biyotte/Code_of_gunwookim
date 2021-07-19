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
const long long llINF = 1e18+10;
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
int n,sum[100005],t[400005];
char a[100005];

void build(int x,int l,int r) {
	if(l == r) {t[x] = sum[l]; return;}
	int mid = (l + r) >> 1;
	build(x*2,l,mid), build(x*2+1,mid+1,r);
	t[x] = min(t[x*2],t[x*2+1]);
}

int query(int x,int l,int r,int rl,int rr) {
	if(rl > r||l > rr) return INF;
	if(rl <= l&&r <= rr) return t[x];
	int mid = (l + r) >> 1;
	return min(query(x*2,l,mid,rl,rr),query(x*2+1,mid+1,r,rl,rr));
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> a+1;
	n = strlen(a+1);
	for(int i = 1;i <= n;i++) sum[i] = sum[i-1]+(a[i] == '(' ? 1 : -1);
	build(1,1,n);
	int Q,ans = 0; cin >> Q;
	while(Q--) {
		int l,r; cin >> l >> r;
		ans += (query(1,1,n,l,r) >= sum[l-1]&&sum[r] == sum[l-1]);
	}
	cout << ans;
}
