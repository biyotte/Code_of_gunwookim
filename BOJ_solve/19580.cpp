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
int n,m,ans;
pl a[500005],b[500005];

bool cmp(pl x,pl y) {
	return x.y > y.y;
}

bool cmp2(pl x,pl y) {
	return x.x > y.x;
}

priority_queue <ll> q;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i].x >> a[i].y;
	for(int i = 1;i <= m;i++) cin >> b[i].x >> b[i].y;
	sort(a+1,a+n+1,cmp);
	sort(b+1,b+m+1,cmp2);
	for(int i = 1,p = 1;i <= m;i++) {
		while(p <= n&&a[p].y >= b[i].x) q.push(a[p++].x);
		for(int j = 1;j <= b[i].y;j++) {
			while(!q.empty()&&q.top() > b[i].x) q.pop();
			if(q.empty()) break;
			q.pop();
			ans++;
		}
	}
	cout << ans;
}
