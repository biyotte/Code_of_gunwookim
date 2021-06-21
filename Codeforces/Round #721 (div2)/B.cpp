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
int n;
char a[1005];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while(T--) {
		cin >> n >> a+1;
		int cnt = 0,nam = 0;
		for(int i = 1;i <= n/2;i++) {
			if(a[i] != a[n-i+1]) cnt++;
		}
		for(int i = 1;i <= n;i++) nam += '1'-a[i];
		int A = 0,B = 0,cnt2 = 0;
		nam -= cnt;
		if(n % 2&&a[(n+1)/2] == '0') {
			nam--;
			nam %= 4;
			cnt2++;
			B = nam;
		}
		else {
			nam %= 4;
			A = nam;
		}
		if(A+cnt2 < B+cnt) cout << "ALICE\n";
		else if(A+cnt2 == B+cnt) cout << "DRAW\n";
		else cout << "BOB\n";
	}
}