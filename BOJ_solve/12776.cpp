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
long long mod;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi; 
typedef long long ll;
int n;
pi a[1000005];
vecpi v,v2;

bool cmp(pi x,pi y) {
	return x.y > y.y;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) {
		cin >> a[i].x >> a[i].y;
		if(a[i].x < a[i].y) v.pb(a[i]);
		else v2.pb(a[i]);
	}
	sort(all(v)), sort(all(v2),cmp);
	ll nam = 0,ans = 0;
	for(pi i : v) {
		if(nam < i.x) {
			ans += i.x-nam;
			nam = i.x;
		}
		nam += i.y-i.x;
	}
	for(pi i : v2) {
		if(nam < i.x) {
			ans += i.x-nam;
			nam = i.x;
		}
		nam += i.y-i.x;
	}
	cout << ans;
}