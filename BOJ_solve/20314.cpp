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
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,ans[200005];
int h[200005],t[200005];
pi a[200005];
pair<int,pi>> lange;
deque <pi> dq;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); 
	cin >> n;
	for(int i = 1;i <= n;i++) {
		cin >> h[i];
		a[i] = {h[i],i};
	}
	for(int i = 1;i < n;i++) cin >> t[i];
	memset(ans,-1,sizeof(ans));
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;i++) {
		while(!dq.empty()&&dq.front().y < i) dq.pop_front();
		dq.push_back({});
	}
	for(int i = n;i >= 1;i--) {
		ans[a[i].y] = max(ans[a[i].y],a[i].x);
		int l = a[i].y, r = a[i].y;
		int cnt = 0,mn = a[i].x;
		while(l > 1) {
			mn = min(mn-t[l-1],h[l-1]);
			if(mn < 0) break;
			ans[l-1] = max(ans[l-1],a[i].x);
			l--;
		}
		mn = a[i].x;
		while(r < n) {
			mn = min(mn-t[r],h[r+1]);
			if(mn < 0) break;
			ans[r+1] = max(ans[r+1],a[i].x);
			r++;
		}
	}
	for(int i = 1;i <= n;i++) cout << ans[i] << ' ';
}