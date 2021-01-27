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
int n,m,a[1000005];
ll cnt[2000005];

ll mpow(int x) {
	if(!x) return 1;
	ll tmp = mpow(x/2);
	if(x&1) return tmp*tmp*2%mod;
	return tmp*tmp%mod;
}

void go(int l,int r) {
	if(l+1 == r) {
		cnt[l] = mpow(cnt[l]);
		return;
	}
	int mid = (l + r) >> 1;
	for(int i = l;i < mid;i++) cnt[mid+i-l] += cnt[i];
	go(l,mid), go(mid,r);
	for(int i = l;i < mid;i++) {
		cnt[mid+i-l] = (cnt[mid+i-l]-cnt[i]+mod)%mod;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) {
		int cn,x; cin >> cn;
		while(cn--) cin >> x, a[i] |= (1 << (x-1));
		cnt[a[i]]++;
	}
	go(0,1 << m);
	cout << cnt[(1 << m)-1];
}