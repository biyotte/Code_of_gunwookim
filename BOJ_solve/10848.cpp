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
const long long llINF = 1e19;
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
int n,k,m;
ll pre,lsum,rsum,cnt,kl[100005],kr[100005];
priority_queue <ll> l,r;
pl a[100005];

bool cmp(pl x,pl y) {
	return x.x+x.y < y.x+y.y;
}

void update(ll x,ll y) {
	l.push(x), l.push(y);
	lsum += x+y;
	r.push(-l.top());
	rsum += l.top();
	lsum -= l.top();
	l.pop();
	r.push(-l.top());
	rsum += l.top();
	lsum -= l.top();
	l.pop();
	l.push(-r.top());
	lsum += -r.top();
	rsum -= -r.top();
	r.pop();
	cnt++;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> k >> n;
	for(int i = 1;i <= n;i++) {
		char op1,op2; int x1,x2;
		cin >> op1 >> x1 >> op2 >> x2;
		if(op1^op2) a[++m] = {x1,x2};
		else pre += abs(x1-x2);
	}
	sort(a+1,a+m+1,cmp);
	for(int i = 1;i <= m;i++) {
		update(a[i].x,a[i].y);
		kl[i] = rsum-lsum+cnt;
	}
	while(!l.empty()) l.pop();
	while(!r.empty()) r.pop();
	lsum = rsum = cnt = 0;
	for(int i = m;i >= 1;i--) {
		update(a[i].x,a[i].y);
		kr[i] = rsum-lsum+cnt;
	}
	if(k == 1) {
		cout << kl[m]+pre;
		return 0;
	}
	ll ans = llINF;
	for(int i = 1;i <= m;i++) {
		ans = min(ans,kl[i]+kr[i+1]);
	}
	cout << ans+pre;
}