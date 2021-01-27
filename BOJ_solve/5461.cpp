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
const int mod = 998244353;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n;
ld w;
pl a[500005],an[500005];
pair <ld,int> b[500005];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> w;
	for(int i = 1;i <= n;i++) {
		cin >> a[i].x >> a[i].y;
		b[i] = {(ld)a[i].x/a[i].y,i};
	}
	sort(b+1,b+n+1);
	priority_queue <pl> q;
	ll s = 0;
	int mx = 0,wi = 0;
	ld ans = 0;
	for(int i = 1;i <= n;i++) {
		an[i] = {a[b[i].y].y,b[i].y};
		q.push({a[b[i].y].y,b[i].y}), s += a[b[i].y].y;
		while(s*b[i].x > w) s -= q.top().x, q.pop();
		if(mx < q.size()) mx = q.size(), wi = i, ans = s*b[i].x;
		else if(mx == q.size()&&ans > s*b[i].x) mx = q.size(), wi = i, ans = s*b[i].x;
	}
	sort(an+1,an+wi+1);
	cout << mx << '\n';
	for(int i = 1;i <= mx;i++) cout << an[i].y << '\n';
}