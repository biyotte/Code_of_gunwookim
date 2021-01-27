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
const long long llINF = 1e18;
const long long mod = 998244353;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,ans;
pi a[300005];
vecpi v;
stack <int> st;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); 
	cin >> n;
	for(int i = 1;i <= n;i++) {
		cin >> a[i].x >> a[i].y;
		v.pb({a[i].x-a[i].y,1});
		v.pb({a[i].x+a[i].y,0});
	}
	sort(all(v));
	for(int i = 0;i < v.size();i++) {
		if(v[i].y) { //in
			if(!i||st.empty()) st.push(0);
			else if(v[i].x != v[i-1].x) {
				st.pop(); st.push(-1);
				st.push(0);
			}
			else {
				int x = st.top(); st.pop();
				st.push((x^-1?1:-1)), st.push(0);
			}
		}
		else {
			int x = st.top(); st.pop();
			ans += 1+(x == 1&&v[i].x == v[i-1].x);
		}
	}
	cout << ans+1;
}
