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
ll d[5005][5005];

struct Work {
	int d,c,s;
}a[5005];

bool cmp(Work x,Work y) {
	if(x.d == y.d) {
		if(x.c == y.c) return x.s < y.s;
		return x.c < y.c;
	}
	return x.d < y.d;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) {
		cin >> a[i].d >> a[i].c >> a[i].s;
	}
	sort(a+1,a+n+1,cmp);
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= 5000;j++) {
			d[i][j] = max(d[i-1][j],d[i][j-1]);
			if(j-a[i].c >= 0&&j <= a[i].d) {
				d[i][j] = max(d[i][j],d[i-1][j-a[i].c]+a[i].s);
			}
		}
	}
	cout << d[n][5000];
}
