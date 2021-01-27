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
long long mod = 1e9+7;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef vector <int> vec;
typedef vector <pi> vecpi; 
typedef long long ll;
int n,m;
int c[200005],p[200005];
ll a[200005],b[200005],ca[200005],cb[200005];

int Find(int x) {return (p[x]^x ? p[x] = Find(p[x]) : x);}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= n;i++) cin >> b[i], p[i] = i;
	for(int i = 1;i <= m;i++) {
		int x,y; cin >> x >> y;
		x = Find(x), y = Find(y);
		if(x == y) continue;
		p[y] = x;
	}
	for(int i = 1;i <= n;i++) {
		ca[Find(i)] += a[i], cb[Find(i)] += b[i];
	}
	for(int i = 1;i <= n;i++) {
		if(ca[i] != cb[i]) {
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
}