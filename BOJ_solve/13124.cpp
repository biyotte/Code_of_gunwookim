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
const long long llINF = 2e18;
const long long mod = 998244353;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,Q;
int a[100005];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); 
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	cin >> Q;
	while(Q--) {
		int x,y; cin >> x >> y;
		swap(a[x],a[y]);
		if(a[1] == 2&&a[2] == n&&a[3] == 1) cout << "YES\n";
		else if(a[n-2] == n&&a[n-1] == 1&&a[n] == n-1) cout << "YES\n";
		else if(a[1] == 3&&a[2] == 1&&a[n] == 2) cout << "YES\n";
		else if(a[1] == n-1&&a[n-1] == n&&a[n] == n-2) cout << "YES\n";
		else cout << "NO\n";
	}
}