#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define all(v) v.begin(),v.end()
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
using namespace std;
const long long INF = 1e9;
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
int n,d[505];
vec ans;
vec b;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n, n++;
	for(int i = 1;i <= n;i++) cin >> d[i];
	for(int i = 1;i <= n;i++) {
		b.clear();
		for(int j = 1;j <= n;j++) {
			if(i^j) b.pb(d[j]);
		}
		sort(all(b));
		bool nope = 0;
		while(1) {
			while(!b.empty()&&b[0] == 0) b.erase(b.begin());
			if(b.empty()) {
				nope = 0;
				break;
			}
			int x = b.back(); b.pop_back();
			if(x > b.size()) {
				nope = 1;
				break;
			}
			for(int k = b.size()-x;k < b.size();k++) b[k]--;
			sort(all(b));
		}
		if(!nope) ans.pb(i);
	}
	cout << ans.size() << '\n';
	for(int i : ans) cout << i << '\n';
}
