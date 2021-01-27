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
typedef pair <int,int> pl;
typedef pair <ll,ll> pi;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
char a[100005];
int n;
ll L0[100005],R0[100005],L1[100005],R1[100005];
ll cntL[100005],cntR[100005];
ll x,y;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> a+1 >> x >> y;
	n = strlen(a+1);
	if(x > y) {
		swap(x,y);
		for(int i = 1;i <= n;i++) {
			if(a[i] == '0') a[i] = '1';
			else if(a[i] == '1') a[i] = '0';
		}
	}
	for(int i = 1;i <= n;i++) {
		if(a[i] == '?') cntL[i] = 1;
		if(a[i] == '0') L0[i] = 1;
		if(a[i] == '1') L1[i] = 1;
		cntL[i] += cntL[i-1];
		L0[i] += L0[i-1];
		L1[i] += L1[i-1];
	}
	for(int i = 1;i <= n;i++) {
		R0[i] = L0[n]-L0[i-1];
		R1[i] = L1[n]-L1[i-1];
		cntR[i] = cntL[n]-cntL[i-1];
	}
	ll ans,sum = 0,nam = 0;
	for(int i = 1;i <= n;i++) {
		if(a[i] == '0') { // ? : 1가정
			sum += y*(L1[i]+nam);
		}
		else sum += x*L0[i];
		if(a[i] == '?') nam++;
	}
	ans = sum;
	ll nam1R = cntL[n],nam0L = 0;
	for(int i = 1;i <= n;i++) {
		if(a[i] == '?') { // 1 -> 0
			sum -= x*(L0[i]+nam0L)+y*R0[i];
			nam0L++, nam1R--;
			sum += y*L1[i]+x*(R1[i]+nam1R);
			ans = min(ans,sum);
		}
	}
	cout << ans;
}