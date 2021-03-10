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
int n,lc[100005],hc[100005];
int a[100005];
priority_queue <pair<int,pi>> q;

void dfs_low(int x) {
	if(lc[x]) return;
	lc[x] = 1;
	if(x > 1&&a[x-1] < a[x]) {
		dfs_low(x-1);
		lc[x] = max(lc[x],lc[x-1]+1);
	}
	if(x < n&&a[x+1] < a[x]) {
		dfs_low(x+1);
		lc[x] = max(lc[x],lc[x+1]+1);
	}
}

void dfs_hi(int x) {
	if(hc[x]) return;
	hc[x] = 1;
	if(x > 1&&a[x-1] > a[x]) {
		dfs_hi(x-1);
		hc[x] = max(hc[x],hc[x-1]+1);
	}
	if(x < n&&a[x+1] > a[x]) {
		dfs_hi(x+1);
		hc[x] = max(hc[x],hc[x+1]+1);
	}
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++) dfs_low(i), dfs_hi(i);
	for(int i = 1;i <= n;i++) {
		if(i > 1&&a[i-1] > a[i]) q.push({hc[i-1]+1,{i-hc[i-1],i}});
		if(i < n&&a[i+1] > a[i]) q.push({hc[i+1]+1,{i+hc[i+1],i}});
	}
	int ans = 0;
	for(int i = 2;i < n;i++) {
		if(a[i-1] < a[i]&&a[i] > a[i+1]) {
			int mn = min(lc[i-1],lc[i+1])+1, mx = max(lc[i-1],lc[i+1])+1,fl;
			if(mn <= mx-mx%2) continue;
			vector <pair<int,pi>> roll;
			int ffl = 1;
			while(!q.empty()) {
				auto now = q.top(); q.pop();
				roll.pb(now);
				if(now.x < mx) break;
				if(now.y.x == i) continue;
				ffl = 0;
				break;
			}
			if(ffl) ans++;
			for(auto j : roll) q.push(j);
		}
	}
	cout << ans;
}