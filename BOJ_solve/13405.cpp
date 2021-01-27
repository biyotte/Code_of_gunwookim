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
int n,full,all,sz;
set <int> s;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) {
		int x; cin >> x;
		if(full == x&&!all&&sz == full) {
			all = 1;
			cout << "Yes\n";
			full = INF;
			continue;
		}
		if(full >= x) {
			cout << "No\n";
			continue;
		}
		cout << "Yes\n";
		while(s.find(x) != s.end()) {
			s.erase(x); x--; sz--;
		}
		s.insert(x); sz++;
		while(s.find(full+1) != s.end()) {
			s.erase(full+1);
			full++;
		}
	}
}