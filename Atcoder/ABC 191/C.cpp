#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define all(v) v.begin(),v.end()
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
using namespace std;
const long long INF = 1e9;
const int TMX = 1 << 18;
const long long llINF = 1e18;
const long long mod = 1e9+7;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,m;
char a[15][15];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	int ans = 0;
	for(int i = 1;i <= n;i++) cin >> a[i]+1;
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= m;j++) {
			if(a[i][j] == '#') {
				if(a[i+1][j] == '.'&&a[i][j+1] == '.'&&a[i+1][j+1] == '.') ans++;
				if(a[i-1][j] == '.'&&a[i][j+1] == '.'&&a[i-1][j+1] == '.') ans++;
				if(a[i+1][j] == '.'&&a[i][j-1] == '.'&&a[i+1][j-1] == '.') ans++;
				if(a[i-1][j] == '.'&&a[i][j-1] == '.'&&a[i-1][j-1] == '.') ans++;
			}
			if(a[i][j] == '.') {
				if(a[i+1][j] == '#'&&a[i][j+1] == '#'&&a[i+1][j+1] == '#') ans++;
				if(a[i-1][j] == '#'&&a[i][j+1] == '#'&&a[i-1][j+1] == '#') ans++;
				if(a[i+1][j] == '#'&&a[i][j-1] == '#'&&a[i+1][j-1] == '#') ans++;
				if(a[i-1][j] == '#'&&a[i][j-1] == '#'&&a[i-1][j-1] == '#') ans++;
			}
		}
	}
	cout << ans;
}
