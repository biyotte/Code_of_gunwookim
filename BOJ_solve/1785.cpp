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
const long long llINF = 1e18+10;
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
ll N,K;
ll d[60][40][30][30];
int a[5];

ll go(ll n,ll k) {
	if(!n||k >= K) return n;
	ll &ret = d[a[1]][a[2]][a[3]][a[4]];
	if(ret) return ret;
	ret = llINF;
	for(ll i = 2;i <= 5;i++) {
		a[i-1]++;
		ret = min(ret,go(n/i,k+1)+n%i);
		a[i-1]--;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> N >> K;
	cout << go(N,1);
}
