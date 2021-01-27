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
const long long llINF = 2e18;
const long long mod = 1e9+7;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pl;
typedef pair <ll,ll> pi;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n;
char a[100005];
ll T,sum,cnt[200];
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> T;
	cin >> a+1;
	reverse(a+1,a+n+1);
	T -= (1 << (a[1]-'a'))-(1 << (a[2]-'a'));
	for(int i = 3;i <= n;i++) cnt[a[i]-'a']++;
	if(T < 0) T = -T;
	for(int i = 3;i <= n;i++) T += (1 << (a[i]-'a'));
	for(int i = 25;i >= 0;i--) {
		while(cnt[i]&&(2 << i) <= T) {
			T -= (2 << i);
			cnt[i]--;
		}
	}
	if(!T) cout << "Yes";
	else cout << "No";
}