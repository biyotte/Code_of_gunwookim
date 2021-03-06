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
ld a,b,c;

int main() {
	//ios_base::sync_with_stdio(false); cin.tie(0);
	for(int tc = 1;1;tc++) {
		cin >> a >> b >> c;
		if(!a) break;
		cout << "Triangle #" << tc << '\n';
		if(a == -1) {
			if(b*b >= c*c) cout << "Impossible.\n";
			else printf("a = %.3LF\n",sqrt(c*c-b*b));
		}
		if(b == -1) {
			if(a*a >= c*c) cout << "Impossible.\n";
			else printf("b = %.3LF\n",sqrt(c*c-a*a));
		}
		if(c == -1) {
			printf("c = %.3LF\n",sqrt(a*a+b*b));
		}
		cout << '\n';
	}
}