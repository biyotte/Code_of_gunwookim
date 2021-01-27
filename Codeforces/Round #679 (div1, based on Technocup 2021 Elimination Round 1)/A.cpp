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
long long mod;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,m,a[10],b[100005],cnt;
int ch[100005];
vector<pair<ll,int>> c;

bool isok(ll mid) {
	int l = 1, r = -1;
	memset(ch,0,sizeof(ch));
	int cnt = 0;
	for(l = 0;l < m-1;l++) {
		while(c[r+1].x-c[l].x <= mid) {
			if(!ch[c[r+1].y]) cnt++;
			ch[c[r+1].y]++;
			r++;
		}
		if(cnt == n) return true;
		ch[c[l].y]--;
		if(!ch[c[l].y]) cnt--;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	//int T; cin >> T;
	int T = 1;
	while(T--) {
		for(int i = 1;i <= 6;i++) cin >> a[i];
		cin >> n;
		for(int i = 1;i <= n;i++) {
			cin >> b[i];
			for(int j = 1;j <= 6;j++) if(b[i]-j > 0) c.pb({b[i]-a[j],i});
		}
		sort(all(c));
		c.pb({llINF,-1});
		m = c.size();
		sort(b+1,b+n+1);
		ll l = 0,r = 2*INF;
		while(l < r) {
			ll mid = (l + r) >> 1;
			if(isok(mid)) r = mid;
			else l = mid+1;
		}
		cout << l;
	}
}