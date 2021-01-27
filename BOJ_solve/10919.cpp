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
int n,k,L;
int a[10000005];
ll dl[10000005],dr[30000005];
ll rans;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k >> L;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++) {
		dl[i] = (i <= k ? 0 : dl[i-k])+a[i]*2;
	}
	for(int i = n;i >= 1;i--) {
		dr[i] = (i > n-k ? 0 : dr[i+k])+(L-a[i])*2;
	}
	ll rans = llINF;
	for(int i = 0;i <= n;i++) {
		rans = min({rans,dl[i]+dr[i+1],dl[i]+L+dr[i+k+1],dl[i]+L*2+dr[i+2*k+1]});
	}
	cout << rans;
}
