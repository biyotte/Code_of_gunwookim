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
int n,cnt;
char a[500005];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> a+1;
	n = strlen(a+1);
	for(int i = 1;i <= n;i++) {
		if(a[i]^a[n-i+1]) {
			cout << n;
			return 0;
		}
		else if(a[i] == a[1]) cnt++;
	}
	cout << (cnt^n ? n-1 : -1);
}