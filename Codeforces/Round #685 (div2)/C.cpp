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
const long long llINF = 5e18;
const long long mod = 1e9+7;
const long long hmod1 = 1e9+409;
const long long hmod2 = 1e9+433;
const long long base = 257;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
char a[1000005],b[1000005];
int n,k,ca[30],cb[30];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int T; cin >> T;
	//int T = 1;
	while(T--) {
		cin >> n >> k >> a+1 >> b+1;
		memset(ca,0,sizeof(ca));
		memset(cb,0,sizeof(cb));
		for(int i = 1;i <= n;i++) ca[a[i]-'a']++;
		for(int i = 1;i <= n;i++) cb[b[i]-'a']++;
		int nope = 0;
		for(int i = 0;i < 26;i++) {
			if(ca[i] < cb[i]) {
				nope = 1;
				break;
			}
			if(ca[i] % k != cb[i] % k) {
				nope = 1;
				break;
			}
			ca[i] -= cb[i];
			ca[i+1] += ca[i];
		}
		cout << (nope ? "No" : "Yes") << '\n';
	}
}
