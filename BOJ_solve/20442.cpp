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
int n,lk[3000005],rk[3000005],r[3000005];
int L[3000005],R[3000005];
char a[3000005];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> a+1; n = strlen(a+1);
	L[0] = 0, R[0] = n+1;
	for(int i = 1;i <= n;i++) L[i] = INF, R[i] = 0;
	for(int i = 1;i <= n;i++) {
		lk[i] = lk[i-1]+(a[i] == 'K');
		r[i] = r[i-1]+(a[i] == 'R');
		L[lk[i]] = min(L[lk[i]],i);
	}
	for(int i = n;i >= 1;i--) {
		rk[i] = rk[i+1]+(a[i] == 'K');
		R[rk[i]] = max(R[rk[i]],i);
	}
	int ans = 0;
	for(int i = 0;i <= n;i++) {
		if(L[i] >= R[i]) break;
		if(r[R[i]-1]-r[L[i]]) ans = max(ans,i*2+r[R[i]-1]-r[L[i]]);
	}
	cout << ans;
}
