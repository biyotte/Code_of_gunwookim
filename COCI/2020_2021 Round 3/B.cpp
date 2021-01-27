#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define all(v) v.begin(),v.end()
using namespace std;
const int INF = 1e9;
const int TMX = 1 << 18;
const long long llINF = 2e18;
const long long mod = 1e9+7;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n;
ll t,t2,st;
pi a[1005];
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); 
	cin >> t >> n >> t2;
	st = t;
	for(int i = 1;i <= n;i++) {
		cin >> a[i].x >> a[i].y;
		t -= a[i].x-a[i-1].y;
		if(t <= 0) {
			cout << "No";
			return 0;
		}
		t += a[i].y-a[i].x;
		t = min(t,st);
	}
	if(t2-a[n].y < t) cout << "Yes";
	else cout << "No";
}