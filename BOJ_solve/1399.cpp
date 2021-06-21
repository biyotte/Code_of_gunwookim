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
const long long llINF = 1e16;
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
int T,x,y;
ll a[15];

// not solved

void f(int time,int val,ll gop) {
	if(time == 1) y += gop*val;
	if(time == 2) x += gop*val;
	if(time == 3) y -= gop*val;
	if(time == 4) x -= gop*val;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	while(T--) {
		ll k,m; cin >> k >> m;
		int n,st;
		x = 0, y = 0;
		a[1] = n;
		for(n = 2;1;n++) {
			a[n] = a[n-1]*m;
			while(a[n] >= 10) {
				a[n] = a[n]%10+(a[n]/10)%10+((a[n]/10)/10)%10+(((a[n]/10)/10)/10)%10;
			}
			for(int j = 1;j < n;j++) {
				if(a[n] == a[j]) {
					st = j;
					break;
				}
			}
		}
		for(int i = 1;i <= min(st-1,k);i++) {
			f(i,a[i]);
		}
		int go = min(n,k)+1;
		k -= min(n,k);
		int ti = (n-st+1)/k;
		for(int i = st;i <= n;i++) {
			f((go+i))
		}
	}
}