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
long long mod = 1e9+7;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef vector <int> vec;
typedef vector <pi> vecpi; 
typedef long long ll;
int n;
int x[15],y[15],r[15];
double ans;

int main() {
	//ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> x[i] >> y[i] >> r[i];
	for(int i = 1;i < (1 << n);i++) {
		int gop = 1,mx = 0,my = 0,msum = INF;
		for(int j = 1;j <= n;j++) {
			if(i & (1 << (j-1))) {
				gop *= -2;
				mx = max(mx,x[j]), my = max(my,y[j]);
				msum = min(msum,x[j]+y[j]+r[j]);
			}
		}
		if(mx+my < msum) ans += -0.25*(msum-mx-my)*(msum-mx-my)*gop;
	}
	printf("%.1lf",ans);
}