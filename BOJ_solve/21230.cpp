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
int a[305];
int d[305][305];

// not solved

pi Find(int co,int l,int r) {
	while(a[l] == co) l++;
	while(a[r] == co) r--;
	return {l,r};
}

int go(int l,int r) {
	if(l > r) return 0;
	if(d[l][r] != -1) return d[l][r];
	if(l == r) return 1;
	pi g = Find(a[l],l,r);
	d[l][r] = go(g.x,g.y)+1;
	g = Find(a[r],l,r);
	d[l][r] = min(d[l][r],go(g.x,g.y)+1);
	for(int i = l;i < r;i++) d[l][r] = min(d[l][r],go(l,i)+go(i+1,r));
	return d[l][r];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	memset(d,-1,sizeof(d));
	for(int i = 1;i <= n;i++) cin >> a[i];
	cout << go(1,n);
}