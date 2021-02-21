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
int n,k;
int a[250005];
ll d[250005][10][20];

//not solved

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
	}
	for(int i = 0;i <= n;i++) for(int l = 0;l <= k;l++) for(int j = 0;j <= k*2+1;j++) d[i][l][j] = llINF;
	d[0][0][k] = 0;
	for(int i = 1;i <= n;i++) {
		for(int l = 0;l <= k;l++) {
			for(int j = 0;j <= k*2;j++) {
				d[i][l][j] = min({d[i-1][l][j],(i > 1 ? d[i-2][l][j] : llINF),(i > 3 ? d[i-3][l][j] : llINF)})+a[i];
				if(j&&l) {	
					d[i][l][j] = min({
						d[i][l][j],
						(i > 1 ? d[i-1][l-1][j-1]+a[i]+a[i-1] : llINF),
						(i > 1 ? d[i-2][l-1][j-1]+a[i]+a[i-1] : llINF),
						(i > 3 ? d[i-3][l-1][j-1]+a[i]+a[i-2] : llINF)
					});
				}
				if(l) {
					d[i][l][j] = min({
						d[i][l][j],
						d[i-1][l-1][j]+a[i],
						(i > 1 ? d[i-2][l-1][j]+a[i-1] : llINF),
						(i > 3 ? d[i-3][l-1][j]+a[i-2] : llINF
					)});
				}
				d[i][l][j] = min({d[i][l][j],(i > 1 ? d[i-1][l][j+1] : llINF),(i > 1 ? d[i-2][l][j+1] : llINF),(i > 3 ? d[i-3][l][j+1] : llINF)}); // in
				cout << d[i][l][j] << ' ';
			}
			cout << '\n';
		}
		cout << '\n';
	}
}