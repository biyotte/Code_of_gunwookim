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
int n,m,a[500005];
int b[500005];
char in[500005];
int st[500005],top;
vecpi ans;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); 
	cin >> in+1;
	n = strlen(in+1);
	for(int i = 1;i <= n;i++) {
		a[i] = in[i]-'0';
	}
	a[n+1] = '!';
	int la = 0;
	for(int i = 1;i <= n;i++) {
		if(a[i] != a[i+1]) b[++m] = i-la, la = i;
	}
	int i,ch = 1,g = 0;
	for(i = 2;i <= m-1;i += 2) {
		int del = min(b[i],b[i+1]);
		if(b[i] < b[i+1]) {
			//cout << del << '\n';
			ans.pb({ch*b[1]+1,ch*b[1]+del*2});
			b[i+1] -= b[i];
			if(ch) b[1] += b[i+1];
		}
		else {
			//cout << del << '\n';
			ans.pb({ch*b[1]+b[i]-del+1,ch*b[1]+b[i]+del});
			b[i+2] += b[i]-b[i+1];
		}
		g += del*2;
	}
	g = n-g;
	if(g) ans.pb({1,g});
	cout << ans.size() << '\n';
	for(pi i : ans) {
		cout << i.x << ' ' << i.y << '\n';
	}
}