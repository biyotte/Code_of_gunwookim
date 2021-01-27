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
const long long llINF = 5e18;
long long mod;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi; 
typedef long long ll;
int n,m,h,k;
ll ans,res, a[1005],la[1005],wi[1005];
pi b[100005];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> h >> k;
	for(int i = 1;i <= n;i++) cin >> a[i], la[i] = i;
	for(int i = 1;i <= m;i++) cin >> b[i].y >> b[i].x;
	sort(b+1,b+m+1);
	for(int i = 1;i <= m;i++) swap(la[b[i].y],la[b[i].y+1]);
	for(int i = 1;i <= n;i++) wi[la[i]] = i, la[i] = i;
	for(int i = 1;i <= k;i++) ans += a[wi[i]]; res = ans;
	for(int i = 1;i <= m;i++) {
		ll tmp = ans;
		if(la[b[i].y] <= k) tmp += a[wi[la[b[i].y+1]]]-a[wi[la[b[i].y]]];
		if(la[b[i].y+1] <= k) tmp += a[wi[la[b[i].y]]]-a[wi[la[b[i].y+1]]];
		res = min(res,tmp);
		swap(la[b[i].y],la[b[i].y+1]);
	}
	cout << res;
}