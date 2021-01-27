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
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while(T--) {
		cin >> n;
		if(n > 45) cout << "-1\n";
		else {
			vec ans;
			int i,sum = 0;
			for(i = 9;i >= 1;i--) {
				if(sum+i > n) {
					if(sum != n) ans.pb(n-sum);
					break;
				}
				sum += i;
				ans.pb(i);
			}
			reverse(all(ans));
			for(int i : ans) cout << i;
			cout << '\n';
		}
	}
}