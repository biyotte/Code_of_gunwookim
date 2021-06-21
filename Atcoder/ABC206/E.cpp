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
const long long llINF = 1e18+10;
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
int n,L,R;
bool isp[1000005];
vec p,pp;

int Cnt(int x,int X) {
	int Rc = (X)/x;
	int Lc = (L-1)/x;
	return Rc-Lc;
}

ll Count(int X) {
	ll ret = 0;
	int sz = pp.size();
	for(int i = 1;i < (1 << sz);i++) {
		int val = 1,cnt = 0;
		for(int j = 0;j < sz;j++) {
			if(i & (1 << j)) val *= pp[j], cnt++;
		}
		if(cnt % 2) ret += Cnt(val,X);
		else ret -= Cnt(val,X);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> L >> R;
	isp[1] = 1;
	for(int i = 2;i <= 1000000;i++) {
		if(isp[i]) continue;
		p.pb(i);
		if(i >= 1000) continue;
		for(int j = i*i;j <= 1000000;j += i) isp[j] = true;
	}
	ll ans = 0;
	for(int i = L;i <= R;i++) {
		pp.clear();
		int now = i;
		for(int j : p) {
			if(now % j == 0) {
				pp.pb(j);
				while(now % j == 0) now /= j;
			}
			if(now < j*j) break;
		}
		if(now != 1) pp.pb(now);
		if(!isp[i]) continue;
		ans += Count(i);
		for(int j = 1;j*j <= i;j++) {
			if(i % j == 0) {
				if(L <= j&&j <= R&&j != 1) ans--;
				if(j*j != i&&L <= i/j&&i/j <= R) ans--;
			}
		}
	}
	cout << ans*2;
}
