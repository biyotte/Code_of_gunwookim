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
int n,K;
int a[55];
ll d[2][50002][11];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	cin >> K;
	sort(a+1,a+n+1), reverse(a+1,a+n+1);
	for(int i = 1;i <= n;i++) {
		for(int nam = 0;nam <= 50001;nam++) {
			for(int k = 0;k <= K;k++) d[i%2][nam][k] = 0;
		}
		for(int nam = 0;nam <= 50001;nam++) {
			for(int k = 1;k <= K;k++) {
				if(nam > a[i]) d[i%2][nam-a[i]][k] += d[(i+1)%2][nam][k-1];
				else d[i%2][0][k] += d[(i+1)%2][nam][k-1];
				d[i%2][nam][k] += d[(i+1)%2][nam][k];
			}
		}
		d[i%2][a[i]+1][1]++;
	}
	cout << d[n%2][0][K];
}