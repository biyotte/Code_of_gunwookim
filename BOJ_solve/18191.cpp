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
const long long mod = 1e9+7;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,m;
ll k,a[200005];

bool isok(ll mid) {
	ll l = 1, r = n;
	for(int i = 2;i <= m;i++) {
		ll cha = a[i]-a[i-1]-mid;
		ll vl,vr;
		if(cha < 0) vl = cha/k;
		else vl = cha/k+(cha%k != 0);
		cha += 2*mid;
		if(cha < 0) vr = cha/k-(cha%k != 0);
		else vr = cha/k;
		if(vl > vr) return 0;
		l += vl, r += vr;
		if(l > n||r < 1) return 0;
		l = max(l,1LL), r = min(r,(ll)n);
	}
	if(l > r) return 0;
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++) {
		cin >> a[i];
	}
	ll l = 0, r = llINF;
	while(l < r) {
		ll mid = (l + r) >> 1;
		if(isok(mid)) r = mid;
		else l = mid+1;
	}
	cout << l;
}
