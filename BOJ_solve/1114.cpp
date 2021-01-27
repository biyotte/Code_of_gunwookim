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
const long long mod = 1e9+7;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int l,k,c,st;
int a[10005];

bool isok(int mid) {
	int cnt = c,la = l;
	st = 0;
	for(int i = k;i >= 0;i--) {
		if(i&&(a[i]-a[i-1]) > mid) return false;
		if(la-a[i] > mid) {
			cnt--;
			st = la = a[++i];
			if(!cnt) return (a[i] <= mid);
		}
	}
	st = a[1];
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); 
	cin >> l >> k >> c;
	for(int i = 1;i <= k;i++) cin >> a[i];
	sort(a+1,a+k+1);
	a[++k] = l;
	int L = 1,R = l;
	while(L < R) {
		int mid = (L + R) >> 1;
		if(isok(mid)) R = mid;
		else L = mid+1;
	}
	isok(L);
	cout << L << ' ' << st;
}