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
int L,T,n;
int a[500005];
vecpi gu;

void process() {
	cin >> n;
	int wl = 0,wr = L;
	for(int i = 1;i <= n;i++) cin >> a[i], wl += a[i];
	for(int i = n;i >= 1;i--) {
		if(wl > wr-a[i]) {
			gu.pb({wr-a[i]+1,1});
			gu.pb({wl+1,-1});
		}
		wl -= a[i];
		wr -= a[i];
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); 
	cin >> L >> T;
	while(T--) process();
	sort(all(gu));
	int cnt = 0,ans = 0,la = 0;
	for(pi i : gu) {
		if(cnt > 0) ans += i.x-la;
		cnt += i.y, la = i.x;
	}
	cout << ans;
}
