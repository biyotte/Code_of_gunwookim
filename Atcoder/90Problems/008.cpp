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
const long long llINF = 1e18+10;
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
int n,d[8][100005];
char a[100005],at[8] = {'!','a','t','c','o','d','e','r'};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> a+1;
	d[0][0] = 1;
	for(int i = 0;i <= 7;i++) {
		for(int j = 1;j <= n;j++) {
			d[i][j] = d[i][j-1];
			if(a[j] == at[i]) d[i][j] += d[i-1][j-1];
			d[i][j] %= mod;
		}
	}
	cout << d[7][n];
}
