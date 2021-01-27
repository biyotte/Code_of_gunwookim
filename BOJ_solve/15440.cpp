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
int n,k,c[2005],ans;
char a[2005];
int cnt[30],correct;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	cin >> n >> k >> a+1;
	for(int i = 1;i <= n;i++) {
		if(!cnt[a[i]-'a']) cnt[a[i]-'a'] = 1, correct++;
		if(correct == 26) {
			c[i] = 1;
			ans++;
			for(int j = 0;j < 26;j++) cnt[j] = 0;
		}
	}
	if(ans > k) {
		cout << "WRONGANSWER";
		return 0;
	}
	for(int i = 1;i <= n&&ans < k;i++) {
		if(c[i]) continue;
		c[i] = 1;
		ans++;
	}
	for(int i = 1;i <= n;i++) {
		
	}
}
