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
const int MAXN = 100000;
const int MAXM = 1000000;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int m;
double n,a[100005];

int main() {
	//ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= m;i++) {
		char x; cin >> a[i] >> x;
	}
	sort(a+1,a+m+1);
	double mn = INF,mx = -INF;
	for(int i = 1;i <= m;i++) {
		double val = a[i]-(i/2)*(double)n*2/m;
		if(i % 2) val *= -1;
		mx = max(mx,val), mn = min(mn,val);
	}
	printf("%.6lf",(mx-mn)/2);
}