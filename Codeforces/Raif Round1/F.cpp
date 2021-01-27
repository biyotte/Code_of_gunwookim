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
long long mod;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi; 
typedef long long ll;
int n,la[500005];
ll ans[500005],res;
char a[500005];

int f(int l,int r) {
	int mx = 0,ret = 0;
	for(int i = l;i <= r;i++) {
		if(a[i] == '1') {
			mx++;
			ret = max(ret,mx);
		}
		else mx = 0;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	//int T; cin >> T;
	int T; T = 1;
	while(T--) {
		cin >> n >> a+1;
		int y = 0,l = n+1;
		for(int i = 1;i <= n;i++) la[i] = n+1;
		for(int i = n;i >= 1;i--) {
			ans[i] = ans[i+1];
			if(a[i] == '1') {
				if(!y) l = i;
				y++;
				ans[i] += la[y]-i;
			}
			else {
				if(y) for(int j = i+1;j <= l;j++) la[j-i] = j;
				y = 0;
			}
			res += ans[i];
		}
		cout << res << '\n';
	}
}