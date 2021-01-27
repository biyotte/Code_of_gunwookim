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
int n,k,cnt[2000005],mx[1000005];
int pr[25];
char a[1000005];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while(T--) {
		cin >> n >> k;
		cin >> a+1;
		for(int i = 1;i <= n;i++) {
			if(a[i] == '1') mx[i] = mx[i-1]+1;
			else mx[i] = 0;
		}
		int rk = min(20,k),cn = 0;
		vec cl;
		for(int i = 0;i <= n-rk;i++) {
			if(mx[i] >= k-rk) {
				int val = 0;
				for(int j = i+1;j <= i+rk;j++) val = val*2+a[j]-'0'; 
				cl.pb(val);
				if(!cnt[val]) cn++;
				cnt[val]++;
				
			}
		}
		if(cn == (1 << rk)) {
			cout << "NO\n";
			for(int i : cl) cnt[i]--;
			continue;
		}
		cout << "YES\n";
		for(int i = 1;i <= k-rk;i++) cout << '0';
		for(int i = 1;i <= rk;i++) pr[i] = 0;
		for(int i = (1 << rk)-1;i >= 0;i--) {
			if(!cnt[i]) {
				i = (1 << rk)-1-i;
				int g = rk;
				while(i) {
					pr[g--] = i%2;
					i /= 2;
				}
				for(int i = 1;i <= rk;i++) cout << pr[i];
				cout << '\n';
				break;
			}
		}
		for(int i : cl) cnt[i]--;
	}
}