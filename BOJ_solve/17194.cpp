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
int n,c1;
int a[200005];

ll inv(int l,int r) {
	ll ret = 0,cnt = 0;
	for(int i = l;i <= r;i++) {
		if(a[i]) cnt++;
		else ret += cnt;
	}
	return ret;
}

ll getAns(int is,int mi) {
	ll invL = inv(1,n), invR = inv(n+1,2*n);
	ll dif = invL-invR;
	ll ret = abs(dif),val = 0,co = 0;
	int cnt1 = 0,j = n;
	for(int i = n;i >= 1;i--) {
		if(a[i]^is) continue;
		dif += (val+cnt1+c1-n-n+i)*mi;
		co += n-i+1+cnt1+val;
		if(++cnt1+val > n) return ret;
		while(cnt1+val > j-n) {
			if(a[j+1]^(is^1)) {
				if(j == 2*n+1) return ret;
				dif += (n+cnt1+val-j)*mi;
				co += (n+cnt1+val-j);
				val++;
			}
			j++;
		}
		ret = min(ret,co+abs(dif));
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i <= 2*n;i++) cin >> a[i], c1 += a[i];
	cout << min(getAns(1,1),getAns(0,-1));
}