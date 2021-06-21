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
int n;

// not solved

struct St {
	ll st,en,t;
}a[200005];

bool cmp(St x,St y) {
	if(x.st == y.st) return x.t < y.t;
	return x.st < y.st;
}

int main() {
	//ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) {
		cin >> a[i].st >> a[i].en >> a[i].t;
	}
	sort(a+1,a+n+1,cmp);
	ll now = 0;
	int use = 1;
	priority_queue <pl> q;
	for(int j = 1;j <= 30&&!q.empty();j++) {
		ll t,en;
		do {
			if(q.empty()) {
				if(use > n) {
					cout << ans;
					return 0;
				}
				q.push({-a[use].t,a[use].en});
			}
			t = -q.top().x, en = q.top().y; q.pop();
		}while(now+t > en);
		q.push({-t,en});
		int pv = use;
		ll mn = llINF*3;
		while(use <= n&&now+t >= a[use].st) {
			mn = min(mn,a[use].st+a[use].t);
			use++;
		}
		cout << now+t << " : " << mn << '\n';
		if(now+t < mn) now += t;
		else now = mn;
		for(int i = pv;i < use;i++) q.push({-a[i].t,a[i].en});
		cout << now << '\n';
	}
}
