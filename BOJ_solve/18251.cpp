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
int n,g;
ll a[1 << 18],b[1 << 18],d[1 << 18],ans = -llINF;

void pre(int x,int l,int r,int dep) {
	if(l == r) {a[++g] = b[x], d[g] = dep; return;}
	int mid = (l + r) >> 1;
	pre(x*2,l,mid-1,dep+1), a[++g] = b[x], d[g] = dep, pre(x*2+1,mid+1,r,dep+1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> b[i];
	pre(1,1,n,1);
	for(int i = 1;i <= 18;i++) {
		for(int j = i;j <= 18;j++) {
			ll val = 0;
			for(int k = 1;k <= n;k++) {
				if(d[k] < i||d[k] > j) continue;
				val = max(a[k],val+a[k]);
				ans = max(ans,val);
			}
		}
	}
	cout << ans;
}