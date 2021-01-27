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
const long long llINF = 1e18;
long long mod = 1e9+7;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef vector <int> vec;
typedef vector <pi> vecpi; 
typedef long long ll;
int n;
char a[100005];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	//int T = 1;
	while(T--) {
		cin >> n;
		cin >> a+1;
		int mx = 0,cnt = 1,s0 = 0,s1 = 0;
		for(int i = 2;i <= n;i++) {
			if(a[i] == a[i-1]) cnt++;
			else {
				if(a[i-1] == '0') s0 += cnt-1;
				else s1 += cnt-1;
				cnt = 1;
			}
		}
		cout << max(s0,s1) << '\n';
	}
}