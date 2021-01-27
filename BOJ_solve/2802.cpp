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
int s[260][260][260];
int n,K,a[100005][3];
vec ans;

int getSum(int x,int y,int z,int x2,int y2,int z2) {
	return s[x2][y2][z2]-s[x-1][y2][z2]-s[x2][y-1][z2]-s[x2][y2][z-1]+s[x2][y-1][z-1]+s[x-1][y2][z-1]+s[x-1][y-1][z2]-s[x-1][y-1][z-1];
}

bool isok(int x,int ch) {
	for(int i = x+1;i <= 256;i++) {
		for(int j = x+1;j <= 256;j++) {
			for(int k = x+1;k <= 256;k++) {
				if(getSum(i-x,j-x,k-x,i,j,k) >= K) {
					if(ch) {
						for(int l = 1;l <= n;l++) {
							if(i-x <= a[l][0]&&a[l][0] <= i&&j-x <= a[l][1]&&a[l][1] <= j&&k-x <= a[l][2]&&a[l][2] <= k) ans.pb(l);
						}
					}
					return true;
				}
			}
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> K;
	for(int i = 1;i <= n;i++) {
		int x,y,z; cin >> x >> y >> z;
		x++, y++, z++;
		a[i][0] = x, a[i][1] = y, a[i][2] = z;
		s[x][y][z]++;
	}
	for(int i = 1;i <= 256;i++) {
		for(int j = 1;j <= 256;j++) {
			for(int k = 1;k <= 256;k++) {
				s[i][j][k] = 2*s[i][j][k]-getSum(i,j,k,i,j,k);
			}
		}
	}
	int l = 0,r = 255;
	while(l < r) {
		int mid = (l + r) >> 1;
		if(isok(mid,0)) r = mid;
		else l = mid+1;
	}
	isok(l,1);
	cout << l << '\n';
	for(int i = 0;i < K;i++) cout << a[ans[i]][0]-1 << ' ' << a[ans[i]][1]-1 << ' ' << a[ans[i]][2]-1 << '\n';
}