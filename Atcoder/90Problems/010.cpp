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
int n,Q;
int sum[2][100005];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) {
		int x,y; cin >> x >> y;
		sum[0][i] = sum[0][i-1]+(x&1 ? y : 0);
		sum[1][i] = sum[1][i-1]+(x&1 ? 0 : y);
	}
	cin >> Q;
	while(Q--) {
		int l,r; cin >> l >> r;
		cout << sum[0][r]-sum[0][l-1] << ' ' << sum[1][r]-sum[1][l-1] << '\n';
	}
}
