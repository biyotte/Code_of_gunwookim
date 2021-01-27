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
int n;
double a[100005],b[100005],sa,sb,ans;

int main() {
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i] >> b[i];
	sort(a+1,a+n+1), sort(b+1,b+n+1);
	for(int i = n,j = n;i >= 0&&j >= 0;) {
		if(sa < sb) sa += a[i--];
		else sb += b[j--];
		ans = max(ans,min(sa,sb)-(n-i)-(n-j));
	}
	printf("%.4lf",ans);
}
