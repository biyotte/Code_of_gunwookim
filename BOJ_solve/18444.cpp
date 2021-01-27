#include <bits/stdc++.h>
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast")
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pi;
int n,m;
ll a[8005],cnt[8005];
ll d[805][8005],ans = 5e18;

ll cost(int l,int r) {
	return (cnt[r]-cnt[l-1])*(r-l+1);
}

void go(int x,int l,int r,int p,int q) {
	if(l > r) return;
	int mid = (l + r) >> 1;
	d[x][mid] = 1e18;
	int wh = -1;
	for(int i = p;i <= q;i++) {
		ll v = d[x-1][i]+cost(i+1,mid);
		if(d[x][mid] > v) {
			d[x][mid] = v, wh = i;
		}
	}
	go(x,l,mid-1,p,wh), go(x,mid+1,r,wh,q);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= n;i++) cnt[i] = cnt[i-1]+a[i];

	for(int i = 0;i <= n;i++) d[1][i] = cost(1,i);
	for(int i = 2;i <= m;i++) go(i,0,n,0,n);
	cout << d[m][n];
	return 0;
}
