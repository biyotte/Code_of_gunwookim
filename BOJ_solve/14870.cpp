#include <bits/stdc++.h>
#define MAXN 200005
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
int n,L[1505],R[1505];
ll a[1505][1505];
ll t[1505][1505],ans;

void update(int x,int l,int r,int val) {
	for(;l <= n;l += l&-l) t[x][l] += val;
	for(r++;r <= n;r += r&-r) t[x][r] -= val;
}

ll query(int x,int y) {
	ll ret = 0;
	for(;y;y -= y&-y) ret += t[x][y];
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); 
	cin >> n;
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) {
			cin >> a[i][j]; 
			a[i][j] += max(a[i-1][j],a[i][j-1]);
			ans += a[i][j];
		}
	}
	cout << ans << '\n';
	for(int Q = 1;Q <= n;Q++) {
		char op; int x,y,val; 
		cin >> op >> x >> y;
		val = (op == 'U' ? 1 : -1);
		int l = y, r = y;
		for(int i = x;i <= n;i++) L[i] = n+1, R[i] = 0;
		L[x] = R[x] = y; 
		for(int i = x;i <= n;) {
			if(r < n&&max(a[i][r]+query(i,r),a[i-1][r+1]+query(i-1,r+1))+val == max(a[i][r]+query(i,r)+val,a[i-1][r+1]+query(i-1,r+1))) r++;
			else i++;
			if(i > n) break;
			R[i] = r;
		}
		for(int i = x;l <= n;) {
			if(i < n&&max(a[i][l]+query(i,l),a[i+1][l-1]+query(i+1,l-1))+val == max(a[i][l]+query(i,l)+val,a[i+1][l-1]+query(i+1,l-1))) i++;
			else l++;
			if(l > n||R[i] < l) break;
			L[i] = min(L[i],l);
		}
		for(int i = x;i <= n;i++) {
			if(L[i] > R[i]) continue;
			update(i,L[i],R[i],val);
			ans += val*(R[i]-L[i]+1);
		}
		cout << ans << '\n';
	}
}
