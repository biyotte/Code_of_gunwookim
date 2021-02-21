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
int n,k,B,C,a[505];
int d[505][2005];
int mn[505];
multiset <int> s;
deque <pi> d2[2005];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k >> B >> C;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
	}
	for(int i = 0;i <= n;i++) for(int j = 0;j <= n*4;j++) d[i][j] = INF;
	d[0][n] = 0;
	for(int i = 1;i <= 3*n;i++) d2[i].pb({0,d[0][i]});
	for(int i = 1;i <= n;i++) {
		s.insert(a[i]);
		if(i > k) s.erase(s.find(a[i-k]));
		if(i >= k) {
			int g = 0;
			for(auto i : s) mn[++g] = i, mn[g] += mn[g-1];
		}
		for(int j = n-i;j <= n+i;j++) {
			d[i][j] = min(d[i-1][j]+a[i],(!j ? INF : d[i-1][j-1]));
			if(i >= k) {
				for(int l = 0;l <= k;l++) {
					d[i][j] = min(d[i][j],d2[j+l].front().y+mn[l]+l*C+B);
				}
			}
			while(!d2[j].empty()&&d2[j].front().x+k <= i) d2[j].pop_front();
			while(!d2[j].empty()&&d2[j].back().y >= d[i][j]) d2[j].pop_back();
			d2[j].pb({i,d[i][j]});
		}
	}
	cout << d[n][n];
}