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
int n,x,y;
int a[105];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while(T--) {
		cin >> n >> x >> y;
		int fl = 0,fl2 = 0;
		for(int i = 1;i <= n;i++) {
			cin >> a[i];
			if(i > 1&&a[i] != a[i-1]) {
				fl = 1;
				if(abs(a[i]-a[i-1]) > 1) fl2 = 1;
			}
		}
		if(!fl) cout << y+min(x,y) << '\n';
		else if(!fl2) cout << min(x,y) << '\n';
		else cout << "0\n";
	}
}