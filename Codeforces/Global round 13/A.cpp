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
int n,a[100005],c0,c1,Q;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T = 1;
	while(T--) {
		cin >> n >> Q;
		for(int i = 1;i <= n;i++) {
			cin >> a[i];
			if(!a[i]) c0++;
			else c1++;
		}
		while(Q--) {
			int x,y; cin >> x >> y;
			if(x == 2) {
				if(y <= c1) cout << "1\n";
				else cout << "0\n";
			}
			else {
				if(a[y]) c0++, c1--;
				else c1++, c0--;
				a[y] ^= 1;
			}
		}
	}
}