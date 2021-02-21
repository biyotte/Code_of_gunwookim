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
const long long llINF = 1e16;
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
int n,dep[5005],c[5005];
vec v[5005];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) {
		int cn; cin >> cn;
		while(cn--) {
			int x; cin >> x;
			v[x].pb(i);
		}
	}
	int rans = INF;
	for(int st = 1;st <= n;st++) {
		memset(c,0,sizeof(c));
		queue <int> q;
		q.push(st);
		dep[st] = 1;
		c[st] = 1;
		int ans = 1,cn = 0;
		while(!q.empty()) {
			int x = q.front(); q.pop();
			cn++;
			for(int i : v[x]) {
				if(c[i]) continue;
				dep[i] = dep[x]+1;
				ans += dep[i];
				c[i] = 1;
				q.push(i);
			}
		}
		if(cn == n) rans = min(rans,ans);
	}
	cout << rans;
}