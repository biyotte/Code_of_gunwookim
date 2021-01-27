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
long long mod;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi; 
typedef long long ll;
int n,k,a[21][21];
int d[1 << 20];

int go(int bit) {
	if(d[bit] != -1) return d[bit];
	int cnt = 0;
	for(int i = 1;i <= n;i++) {
		if(bit & (1 << (i-1))) cnt++;
	}
	if(cnt == k) return 0;
	d[bit] = INF;
	for(int i = 1;i <= n;i++) {
		if(bit & (1 << (i-1))) {
			for(int j = 1;j <= n;j++) {
				if((bit & (1 << (j-1)))&&i != j) {
					d[bit] = min(d[bit],go(bit-(1 << (i-1)))+a[i][j]);
				}
			}
		}
	}
	return d[bit];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) {
			cin >> a[i][j];
		}
	}
	memset(d,-1,sizeof(d));
	cout << go((1 << n)-1);
}