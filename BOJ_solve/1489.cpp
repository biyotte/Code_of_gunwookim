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
int n,a[55],b[55];
int d[55][55];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= n;i++) cin >> b[i];
	sort(a+1,a+n+1), sort(b+1,b+n+1);
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) {
			d[i][j] = max(d[i-1][j],d[i][j-1]);
			if(a[i] > b[j]) d[i][j] = max(d[i][j],d[i-1][j-1]+2);
			if(a[i] == b[j]) d[i][j] = max(d[i][j],d[i-1][j-1]+1);
		}
	}
	cout << d[n][n];
}
