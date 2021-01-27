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
const long long llINF = 5e18;
long long mod;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi; 
typedef long long ll;
int n;
int b[1005][1005];
int mx[1005][1005];

struct X {
	int l,r,h;
}a[1005];

int getMax(int x,int l,int r) {
	if(l > r) return 0;
	stack <int> s;
	int m = r-l+1;
	for(int i = 1;i <= m;i++) a[i].h = mx[x][i+l-1];
	a[m+1].h = 0;
	a[0].h = 0;
	for(int i = 1;i <= m+1;i++) {
	    if(i == 1) {
			s.push(1);
			continue;
	    }
	    while(!s.empty()&&a[i].h < a[s.top()].h) {
			a[s.top()].r = i-1; s.pop();
	    }
	    s.push(i);
	}
	while(!s.empty()) s.pop();
	for(int i = m;i >= 0;i--) {
		if(i == m) {
			s.push(m);
			continue;
		}
		while(!s.empty()&&a[i].h < a[s.top()].h) {
			a[s.top()].l = i+1; s.pop();
		}
		s.push(i);
	}
	int ret = 0;
	for(int i = 1;i <= m;i++) ret = max(ret,a[i].h*(a[i].r-a[i].l+1));
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) cin >> b[i][j];
	}
	for(int i = n;i >= 1;i--) {
		for(int j = 1;j <= n;j++) {
			if(b[i][j] == 1) mx[i][j] = 0;
			else mx[i][j] = mx[i+1][j]+1;
		}
	}
	int l;
	int ans = 0;
	for(int i = 1;i <= n;i++) {
		l = 1;
		b[i][n+1] = 1;
		for(int j = 1;j <= n+1;j++) {
			if(b[i][j] == 1) {
				ans = max(ans,getMax(i,l,j-1));
				l = j+1;
			}
		}
	}
	cout << ans;
}