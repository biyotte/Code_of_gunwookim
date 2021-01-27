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
ll A,B,ans;
ll a[250005],b[250005];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> A >> B >> n >> m;
	a[n+1] = A, b[m+1] = B;
	for(int i = n;i > 0;i--) cin >> a[i];
	for(int i = m;i > 0;i--) cin >> b[i];
	sort(a+1,a+n+1), sort(b+1,b+m+1);
	for(int i = n;i > 0;i--) a[i+1] -= a[i];
	for(int i = m;i > 0;i--) b[i+1] -= b[i];
	n++, m++;
	sort(a+1,a+n+1), sort(b+1,b+m+1);
	ans = a[1]*(m-1)+b[1]*(n-1);
	for(int i = 2,j = 2;i <= n&&j <= m;) {
		if(a[i] < b[j]) {
			ans += a[i]*(m-j+1);
			i++;
		}
		else {
			ans += b[j]*(n-i+1);
			j++;
		}
	}
	cout << ans;
}