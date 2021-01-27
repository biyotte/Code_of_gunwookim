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
const long long mod = 998244353;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,S,d[1105][5005],c[1105],sum[1005];
pi p[1105][5005];
char in[5005];
char a[5005];

int number(int l,int r) {
	int ret = 0;
	for(int i = l;i <= r;i++) ret = ret*10+(a[i]-'0');
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> in+1; n = strlen(in+1);
	for(int i = 1;i <= n;i++) {
		if(in[i] == '=') {
			for(int j = i+1;j <= n;j++) S = S*10+(in[j]-'0');
			n = i-1; break;
		}
		a[i] = in[i];
	}
	#if 0
	vector <pair<char,int>> tm;
	tm.pb({'!',0});
	a[n+1] = '!';
	for(int i = 1;i <= n;i++) {
		if(a[i] != '0'||a[i] != a[i+1]) tm.pb({a[i],i});
	}
	n = tm.size();
	for(int i = 0;i < n;i++) {
		a[i] = tm[i].x;
		sum[i] = tm[i].y-(i?tm[i-1].y:0);
	}
	n--;
	#endif
	for(int i = 0;i <= n+2;i++) {
		for(int j = 0;j <= S+2;j++) {
			d[i][j] = INF;
		}
	}
	d[0][0] = 0;
	for(int i = 1;i <= n;i++) {
		for(int j = 0;j <= S;j++) {
			for(int k = 0;k <= 4;k++) {
				if(k >= i) break;
				int tmp = number(i-k,i);
				if(tmp > j) break;
				if(d[i-k-1][j-tmp]+1 < d[i][j]) {
					d[i][j] = d[i-k-1][j-tmp]+1;
					p[i][j] = {i-k-1,j-tmp};
				}
			}
		}
	}
	for(int x = n, y = S;x;) {
		if(x^n) c[x] = 1;
		int tx = x, ty = y;
		x = p[tx][ty].x;
		y = p[tx][ty].y;
	}
	for(int i = 1;i <= n;i++) {
		cout << a[i];
		if(c[i]) {
			int l = 1;
			for(int j = i-1;j >= 1;j--) {
				if(c[j]) {l = j+1; break;}
			}
			if(number(l,i)) cout << '+';
		}
	}
	cout << "=" << S;
}