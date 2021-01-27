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
int n;
ll a[200000],b[200000];

bool isok(int mid) {
	for(int i = 0;i < n;i++) b[i] = a[i];
	for(int i = mid;i < n;i++) b[0] += b[i];
	ll nec = 1;
	for(int i = mid-1;i >= 0;i--) {
		if(nec > b[i]) {
			if(!i) return false;
			nec += nec-b[i];
		}
		else b[0] += b[i]-nec;
		nec = min(nec,llINF);
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); 
	cin >> n;
	ll sum = 0, wi = 0;
	for(int i = 0;i < n;i++) {
		cin >> a[i];
		sum += a[i];
		if(a[i]) wi = i;
	}
	if(sum == 1) {
		cout << (!wi ? 1 : wi);
		return 0;
	}
	int l = 0,r = 150000;
	while(l < r) {
		int mid = (l + r + 1) >> 1;
		if(isok(mid)) l = mid;
		else r = mid-1;
	}
	cout << l;
}