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
int n;
int a[200005];
int p[200005];

int Find(int x) {
	return (x^p[x] ? p[x] = Find(p[x]) : x);
}

void merge(int x,int y)  {
	x = Find(x), y = Find(y);
	if(x == y) return ;
	p[y] = x;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
	}
	for(int i = 1;i <= 200000;i++) p[i] = i;
	for(int i = 1;i <= n;i++) {
		merge(a[i],a[n-i+1]);
	}
	int ans = 0;
	for(int i = 1;i <= 200000;i++) {
		if(i != Find(i)) ans++;
	}
	cout << ans;
}
