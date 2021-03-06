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
int T;
char a[10005],b[105];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	while(T--) {
		int n,m;
		cin >> a+1 >> b+1;
		n = strlen(a+1), m = strlen(b+1);
		int i,ans = 0;
		for(i = 1;i <= n-m+1;i++) {
			ans++;
			int fl = 1;
			for(int j = 1;j <= m;j++) {
				if(a[i+j-1] != b[j]) fl = 0;
			}
			if(fl) i += m-1; 
		}
		cout << ans+n-i+1 << '\n';
	}
}