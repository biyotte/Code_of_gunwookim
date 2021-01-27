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
const long long mod = 998244353;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int d[1000005][3];
int n,a[1000005];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i], d[i][0] = d[i][1] = d[i][2] = INF;
	d[1][a[1]+1] = 0;
	for(int i = 2;i <= n;i++) {
		d[i][0] = d[i-1][0]+(a[i]+1);
		if(a[i] == 1) d[i][1] = d[i-1][0]+1;
		else if(a[i] == 0) d[i][1] = min(d[i-1][0],d[i-1][1]);
		if(a[i] == 1) d[i][2] = min({d[i-1][0],d[i-1][1],d[i-1][2]});
		else if(a[i] == 0) d[i][2] = d[i-1][2]+1;
		else d[i][2] = d[i-1][2]+2;
 	}
 	if(min({d[n][0],d[n][1],d[n][2]}) >= INF) cout << "BRAK";
 	else cout << min({d[n][0],d[n][1],d[n][2]});
}