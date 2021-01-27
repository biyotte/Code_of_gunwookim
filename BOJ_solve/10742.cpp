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
const int mod = 1e9+7;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,k;
double a[300005],sum[300005];

bool isok(double mid) {
	for(int i = n;i >= 1;i--) sum[i] = sum[i+1]+a[i]-mid;
	double mx = -1e12;
	for(int i = k;i <= n;i++) {
		mx = max(mx,sum[i-k+1]);
		if(mx >= sum[i+1]) return true;
	}
	return false;
}

int main() {
	//ios_base::sync_with_stdio(false); cin.tie(0);
	scanf("%d %d", &n, &k);
	for(int i = 1;i <= n;i++) scanf("%lf",&a[i]);
	double l = 0,r = 1e6+1;
	for(int t = 1;t <= 300;t++) {
		double mid = (l + r) / 2;
		if(isok(mid)) l = mid;
		else r = mid;
	}
	printf("%.7lf",l);
} 
