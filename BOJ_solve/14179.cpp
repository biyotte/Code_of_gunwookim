#include <bits/stdc++.h>
#define x first
#define w second
#define pb push_back
#define all(v) v.begin(),v.end()
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
using namespace std;
const int INF = 1e9;
const int TMX = 1 << 18;
const long long llINF = 2e18;
const long long mod = 1e9+7;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pl;
typedef pair <ll,ll> pi;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,k,cn;
pi a[5005];
ll cntw[5005],cnt[5005],cost[5005][5005];
ll d[2][5005];

void go(int x,int l,int r,int p,int q) {
	if(l > r) return;
	int mid = (l + r) >> 1;
	d[x%2][mid] = 1e18;
	int wh = -1;
	for(int i = p;i <= q;i++) {
		ll v = d[(x-1)%2][i]+cost[i+1][mid];
		if(d[x%2][mid] > v) {
			d[x%2][mid] = v, wh = i;
		}
	}
	go(x,l,mid-1,p,wh), go(x,mid+1,r,wh,q);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	for(int i = 1;i <= n;i++) cin >> a[i].x >> a[i].w;
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;i++) cntw[i] = cntw[i-1]+a[i].w, cnt[i] = cnt[i-1]+a[i].w*a[i].x;
	for(int i = 1;i <= n;i++) {
		int wi = i;
		for(int j = i;j <= n;j++) {
			while(cntw[wi]-cntw[i-1] < (cntw[j]-cntw[i-1]+1)/2) wi++;
			cost[i][j] = a[wi].x*(cntw[wi]-cntw[i-1])-(cnt[wi]-cnt[i-1]);
			cost[i][j] += cnt[j]-cnt[wi]-a[wi].x*(cntw[j]-cntw[wi]);
			//cost[j][i] = cost[i][j];
		}
	}
	for(int i = 0;i <= n;i++) d[1][i] = cost[1][i];
	for(int i = 2;i <= k;i++) go(i,i-1,n-(k-i),i-1,n-(k-i+1));
	cout << d[k%2][n];
	return 0;
}