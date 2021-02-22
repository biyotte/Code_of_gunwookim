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
const long long mod = 998244353;
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
int n,m;
ll s[2005][2005],a[2005][2005],k;

ll sum(int x1,int y1,int x2,int y2) {
	return s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1];
}

bool isokY(int ey1,int ey2) {
	int x1 = 1, y1 = 1, x2 = n, y2 = m;
	int T = n+m-(ey2-ey1+1)-1;
	while(T--) {
		if(x1 < x2&&sum(x1,y1,x1,y2) <= k) x1++;
		else if(x1 < x2&&sum(x2,y1,x2,y2) <= k) x2--;
		else if(y1 < ey1&&sum(x1,y1,x2,y1) <= k) y1++;
		else if(ey2 < y2&&sum(x1,y2,x2,y2) <= k) y2--;
		else return false;
	}
	return (sum(x1,y1,x2,y2) <= k);
}

bool isokX(int ex1,int ex2) {
	int x1 = 1, y1 = 1, x2 = n, y2 = m;
	int T = n+m-(ex2-ex1+1)-1;
	while(T--) {
		if(y1 < y2&&sum(x1,y1,x2,y1) <= k) y1++;
		else if(y1 < y2&&sum(x1,y2,x2,y2) <= k) y2--;
		else if(x1 < ex1&&sum(x1,y1,x1,y2) <= k) x1++;
		else if(ex2 < x2&&sum(x2,y1,x2,y2) <= k) x2--;
		else return false;
	}
	return (sum(x1,y1,x2,y2) <= k);
}

int get() {
	int ans = 0;
	for(int l = 1,r = 1;l <= m;l++) {
		r = max(r,l);
		while(r <= m&&isokY(l,r)) r++;
		ans = max(ans,r-l);
	}
	for(int l = 1,r = 1;l <= n;l++) {
		r = max(r,l);
		while(r <= n&&isokX(l,r)) r++;
		ans = max(ans,r-l);
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> k >> m >> n;
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= m;j++) {
			cin >> a[i][j];
			s[i][j] = s[i][j-1]+s[i-1][j]-s[i-1][j-1]+a[i][j];
		}
	}
	cout << n+m-get();
}