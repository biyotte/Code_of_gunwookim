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
char a[1000005];
int n,len,idx[1000005];
int g[1000005],tg[1000005];
int ra[1000005],lcp[1000005];

bool cmp(int x,int y) {
	if(g[x]^g[y]) return g[x] < g[y];
	return g[x+len] < g[y+len];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while(T--) {
		cin >> a+1;
		n = strlen(a+1);
		for(int i = 1;i <= n;i++) {
			g[i] = a[i]+1;
			idx[i] = i;
		}
		len = 1;
		while(len <= n) {
			sort(idx+1,idx+n+1,cmp);
			tg[idx[1]] = 1;
			for(int i = 2;i <= n;i++) {
				tg[idx[i]] = tg[idx[i-1]];
				if(cmp(idx[i-1],idx[i])) tg[idx[i]]++;
			}
			for(int i = 1;i <= n;i++) g[i] = tg[i];
			len *= 2;
		}
		for(int i = 1;i <= n;i++) ra[idx[i]] = i;
		len = 0;
		for(int i = 1;i <= n;i++) {
			if(ra[i]^1) {
				while(a[i+len] == a[idx[ra[i]-1]+len]) len++;
				lcp[ra[i]] = len;
				if(len) len--;
			}
		}
		ll ans = 0;
		int mi = 0;
		for(int i = 2;i <= n;i++) {
			if(lcp[i-1] > lcp[i]) mi = lcp[i];
			else mi = lcp[i-1];
			ans += lcp[i]-mi;
		}
		cout << ans << '\n';
	}
}