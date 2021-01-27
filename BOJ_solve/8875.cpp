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
int n,m,k;
int a[50005],b[50005];
pi c[1000005];

bool isok(int mid) {
	priority_queue <int> q;
	int pv = 1;
	for(int i = 1;i <= n;i++) {
		while(pv <= k&&c[pv].x < a[i]) q.push(c[pv++].y);
		for(int j = 1;j <= mid&&!q.empty();j++) q.pop();
	}
	while(pv <= k) q.push(c[pv++].y);
	for(int i = m;i >= 1;i--) {
		if(q.empty()||b[i] <= q.top()) break;
		for(int j = 1;j <= mid&&!q.empty();j++) q.pop();
	}
	return q.empty();
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> k;
	for(int i = 1;i <= n;i++) cin >> a[i];	
	for(int i = 1;i <= m;i++) cin >> b[i];
	for(int i = 1;i <= k;i++) cin >> c[i].x >> c[i].y;
	sort(a+1,a+n+1), sort(b+1,b+m+1), sort(c+1,c+k+1);
	int l = 1,r = k;
	while(l < r) {
		int mid = (l + r) >> 1;
		if(isok(mid)) r = mid;
		else l = mid+1;
	}
	if(isok(l)) cout << l;
	else cout << -1;
}