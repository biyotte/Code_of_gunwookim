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
const long long mod = 998244353;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
vector <ll> sum;
int n,Q;
int a[100005];
ll s[100005];

void go(int l,int r) {
	if(l > r) return;
	sum.pb(s[r]-s[l-1]);
	if(a[l] == a[r]) return;
	int mid = (a[l]+a[r]) >> 1;
	int it = upper_bound(a+l+1,a+r+1,mid)-a-1;
	go(l,it), go(it+1,r);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); 
	int T; cin >> T;
	while(T--) {
		cin >> n >> Q;
		for(int i = 1;i <= n;i++) cin >> a[i];
		sort(a+1,a+n+1);
		for(int i = 1;i <= n;i++) s[i] = s[i-1]+a[i];
		sum.clear();
		go(1,n);
		sort(all(sum));
		while(Q--) {
			ll x; cin >> x;
			auto it = lower_bound(all(sum),x);
			if(it == sum.end()) cout << "No\n";
			else cout << (((*it) == x) ? "Yes\n" : "No\n");
		}
	}
}