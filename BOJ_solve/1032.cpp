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
const long long llINF = 2e18;
const long long mod = 1e9+7;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,m,c[55];
char a[55][55];


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); 
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i]+1;
	m = strlen(a[1]+1);
	for(int i = 1;i <= n;i++) {
		for(int j = i+1;j <= n;j++) {
			for(int k = 1;k <= m;k++) {
				if(a[i][k] != a[j][k]) c[k] = 1;
			}
		}
	}
	for(int i = 1;i <= m;i++) cout << (c[i] ? '?' : a[1][i]);
}