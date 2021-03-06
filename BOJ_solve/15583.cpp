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
int n,k,la[100005];
int d[100005][105][105];
vecpi wi;

// not solved

struct L {
	int l,r;
}tt[100005],a[100005];

bool cmp(L x,L y) {
	if(x.l == y.l) return x.r > y.r;
	return x.l < y.l;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	for(int i = 1;i <= n;i++) {
		cin >> tt[i].l >> tt[i].r;
	}
	sort(tt+1,tt+n+1,cmp);
	int tn = 0,mx = 0;
	for(int i = 1;i <= n;i++) {
		if(tt[i].r <= mx) {k--; continue;}
		mx = tt[i].r;
		a[++tn] = tt[i];
	}
	k = max(0,k);
	n = tn;
	int idx = 0;
	a[0].r = -1;
	for(int i = 1;i <= n;i++) {
		while(idx <= i&&a[idx].r < a[i].l) idx++;
		la[i] = idx-1;
	}
	for(int i = 1;i <= n;i++) {
		for(int j = 0;j <= k;j++) {
			d[i][j] = d[i-1][j]+a[i].r-a[i-1].r;
			if(i-la[i] >= j) {
				d[i][j] = max(d[i][j],d[la[i]][j-(i-la[i])]);
			}
			for(int l = 1)
			cout << d[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << d[n][k];
}