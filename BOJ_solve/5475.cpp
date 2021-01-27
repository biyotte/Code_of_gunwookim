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
int d[2][4][4][4][4],n;
char a[100005];

int f(char x) {
	if(x == 'M') return 1;
	if(x == 'B') return 2;
	if(x == 'F') return 3;
	return 0;
}

int getScore(int x,int y,int z) {
	int ans = 3;
	for(int i = 1;i <= 3;i++) {
		if(x^i&&y^i&&z^i) ans--;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> a+1;
	for(int i = n;i >= 0;i--) {
		for(int a1 = 0;a1 < 4;a1++) {
			for(int a2 = 0;a2 < 4;a2++) {
				for(int b1 = 0;b1 < 4;b1++) {
					for(int b2 = 0;b2 < 4;b2++) {
						d[i%2][a1][a2][b1][b2] = max(d[(i+1)%2][a2][f(a[i])][b1][b2]+getScore(a1,a2,f(a[i])),d[(i+1)%2][a1][a2][b2][f(a[i])]+getScore(b1,b2,f(a[i])));
					}
				}
			}
		}
	}
	cout << d[0][0][0][0][0];
}