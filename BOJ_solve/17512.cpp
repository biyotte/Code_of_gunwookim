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
int T,cnt[520],c[520];
int n,ind[520],mx;
vec v[520];
char in[520];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); 
	cin >> T;
	while(T--) {
		cin >> n;
		for(mx = 0;(1 << mx) <= n;mx++);
		for(int i = 1;i <= n;i++) v[i].clear();
		for(int i = 1;i <= n;i++) {
			cin >> in+1;
			for(int j = i+1;j <= n;j++) {
				if(in[j] == 'W') v[i].pb(j);
				else v[j].pb(i);
			}
		}
		vec ans;
		for(int st = 1;st <= n;st++) {
			priority_queue <pi> q;
			q.push({0,st});
			int g = 0;
			memset(cnt,0,sizeof(cnt));
			memset(c,0,sizeof(c));
			ans.clear();
			while(!q.empty()) {
				int val = q.top().x, x = q.top().y; q.pop();
				if(cnt[x]^g) continue;
				g++;
				ans.pb(x);
				if((int)ans.size() == mx) break;
				for(int i : v[x]) {
					if(++cnt[i] == g) {
						c[i] = 1;
					}
				}
				for(int i : v[x]) {
					if(cnt[i] == g) {
						int sum = 0;
						for(int j : v[i]) sum += c[j];
						q.push({sum,i});
					}
				}
			}
			if((int)ans.size() == mx) break;
		}
		if((int)ans.size() != mx) {
			return -1;
		}
		for(int i : ans) cout << i << ' ';
		cout << '\n';
	}
}