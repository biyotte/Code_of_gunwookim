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
int n,a[200005],ans[100005];
stack <int> st;
set <int> s;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	//int T; cin >> T;
	int T = 1;
	while(T--) {
		cin >> n;
		int chk = 0;
		for(int i = 1;i <= 2*n;i++) {
			char op; cin >> op;
			if(op == '+') a[i] = -1;
			else {
				int x; cin >> x;
				a[i] = x;
			}
		}
		int g = n;
		for(int i = 2*n;i >= 1;i--) {
			if(a[i] == -1) {
				if(st.empty()) {
					chk = 1;
					break;
				}
				ans[g--] = st.top();
				st.pop();
			}
			else st.push(a[i]);
		}
		if(chk) {
			cout << "NO\n";
			return 0;
		}
		g = 0;
		for(int i = 1;i <= 2*n;i++) {
			if(a[i] == -1) s.insert(ans[++g]);
			else {
				if(s.empty()) {
					chk = 1;
					break;
				}
				int it = *s.begin();
				if(it != a[i]) {
					chk = 1;
					break;
				}
				s.erase(s.begin());
			}
		}
		if(chk) cout << "NO\n";
		else {
			cout << "YES\n";
			for(int i = 1;i <= n;i++) cout << ans[i] << ' ';
		}
	}
}